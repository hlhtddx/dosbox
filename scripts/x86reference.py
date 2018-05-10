#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

import xml.dom.minidom
import copy
import sys
import logging

class X86Error(Exception):
    def __init__(self):
        super(Exception, self).__init__()


class OperandFormat:
    """
    To specify the format of each operand.
    """
    def __init__(self, ind, address, type, group, nr):
        self.ind = ind
        if group:
            self.address = ('reg', group, nr)
        elif address:
            self.address = address_methods[address]

        self.origin_type = type
        self.type = operand_types[type] if type else None

        if self.address[0] == 'mem':
            self.is_addressing = True
        elif self.address[0] == 'rm' and self.address[1] != 'reg':
            self.is_addressing = True
        else:
            self.is_addressing = False

    def __str__(self):
        return self.unique_name()

    def parse(self, indicator, node):
        if not node:
            return False

        is_addressing = False
        for operand in node:
            if operand.hasAttribute('displayed') and operand.getAttribute('displayed') == 'no':
                continue

            if operand.hasAttribute('address'):
                a = operand.getAttribute('address')
            elif operand.getElementsByTagName('a'):
                a = operand.getElementsByTagName('a')[0].childNodes[0].data
            else:
                a = ""

            if operand.hasAttribute('type'):
                t = operand.getAttribute('type')
            elif operand.getElementsByTagName('t'):
                t = operand.getElementsByTagName('t')[0].childNodes[0].data
            else:
                t = ""

            if t == 'wo':
                t = 'w'
            elif t == 'do':
                t = 'd'

            if operand.hasAttribute('nr'):
                nr = int(operand.getAttribute('nr'))
            else:
                nr = -1

            if operand.hasAttribute('group'):
                group = operand.getAttribute('group')
            else:
                group = None

            op_format = OperandFormat(indicator, a, t, group, nr)
            is_addressing = is_addressing or op_format.is_addressing()
            ops.append(op_format)

        return is_addressing

    def unique_name(self):
        s = ''
        for address in self.address:
            if address:
                s += '%s_' % address
        return s + self.origin_type

    def unique_sized_names(self, operand_size):
        return self.unique_name() + '_' + self.type[operand_size]


class OperandFormatList:
    """
    To specify the format of all operands.
    """
    def __init__(self):
        self.operands = []
        self.is_addressing = False

    def append(self, ind, address, type, group, nr):
        operand_fmt = OperandFormat(ind, address, type, group, nr)
        self.operands.append(operand_fmt)
        if operand_fmt.is_addressing:
            self.is_addressing = True

    def __str__(self):
        return self.unique_name()

    def __parse_operand(self, node, indicator):
        operands = node.getElementsByTagName(indicator)
        if not operands:
            return False

        is_addressing = False
        for operand in operands:
            if operand.hasAttribute('displayed') and operand.getAttribute('displayed') == 'no':
                continue

            if operand.hasAttribute('address'):
                a = operand.getAttribute('address')
            elif operand.getElementsByTagName('a'):
                a = operand.getElementsByTagName('a')[0].childNodes[0].data
            else:
                a = ""

            if operand.hasAttribute('type'):
                t = operand.getAttribute('type')
            elif operand.getElementsByTagName('t'):
                t = operand.getElementsByTagName('t')[0].childNodes[0].data
            else:
                t = ""

            if t == 'wo':
                t = 'w'
            elif t == 'do':
                t = 'd'

            if operand.hasAttribute('nr'):
                nr = int(operand.getAttribute('nr'))
            else:
                nr = -1

            if operand.hasAttribute('group'):
                group = operand.getAttribute('group')
            else:
                group = None

            op_format = OperandFormat(indicator, a, t, group, nr)
            is_addressing = is_addressing or op_format.is_addressing()
            ops.append(op_format)

    def parse(self, node):
        self.__parse_operand(node, 'dst')
        self.__parse_operand(node, 'src')

    def unique_sized_names(self, operand_size):
        return self.unique_name() + '_' + self.type[operand_size]

    def unique_name(self):
        s = ''
        for operands in self.operands:
            if operands:
                s += '%s_' % operands
        return s + self.origin_type


class InstructionBase:
    def __init__(self, pri_opcd):
        self.mnemonic = ''          # mnemonic of instruction
        self.description = ''       # description
        self.opcodes = [pri_opcd]   # opcodes, including the mandatory prefix

    @property
    def __str__(self):
        s = ''
        for opcode in self.opcodes:
            s += '_%02X' % opcode
        return s

    def parse(self, node):
        return False


class InstrPrefix(object, InstructionBase):
    def __init__(self, pri_opcd):
        super(InstrPrefix, self).__init__(pri_opcd)

    @property
    def __str__(self):
        # type: () -> object
        return 'prefix' + super.__str__()

    def parse(self, node):
        return False

    def unique_name(self):
        return self.__str__


class Instruction(object, InstructionBase):
    opcd_ext = None  # type: int

    def __init__(self, pri_opcd):
        super(Instruction, self).__init__(pri_opcd)
        self.prefix = False     # mandatory prefix
        self.operand_fmts = []  # operands
        self.opcd_ext = -1      # opcode extension coded in R/M bits in MODR/M byte
        self.alias = None       # if alias
        self.attr = None        # extra attribute, 'invd', etc.
        self.instr_ext = None   # in which extension, 'mmx', 'sse', etc.
        self.run_mode = None    # R = real/proteced/64, P = protected/64, E = 64 only, S = SMM
        self.is_doc = True      # whether is documented. <entry.is_doc> or <entry.is_undoc>
        self.doc = None         # documented in which part
        self.direction = -1     # -1 = N/A, 0 = R/M<-REG, 1 = REG<-R/M
        self.op_size = -1       # -1 = N/A, 0 = b, 1 = w/d
        self.ad_size = False    # False=size regardless, True = size dependant
        self.sign_ext = -1      # -1 = N/A, 0 = unsigned(0-ext), 1 = signed(1-ext)
        self.register = ''      # indicates that the ModR/M byte contains a register operand and an r/m operand.
        self.tttn = -1          # test conditions
        self.mod = None         # mod field in MODR/M byte: 'mem'=00,01,10, 'nomem'=11
        self.ring = None

    @property
    def __str__(self):
        s = '''Instruction: opcode={} opcd_ext={:02x}
    mnemonic={} operand format={}
    description={}
    run_mode={} ring={} attr={} is_doc={}
    direction={:d} op_size={:d} ad_size={} sign_ext={} register={} tttn={}
'''.format(super.__str__(),
           self.opcd_ext,
           self.mnemonic,
           self.operand_fmts,
           self.description,
           self.run_mode,
           self.ring,
           self.attr,
           self.is_doc,
           self.direction,
           self.op_size,
           self.ad_size,
           self.sign_ext,
           self.register,
           self.tttn)
        return s

    def parse(self, node, flag):
        # Check secondary_opcode
        sec_opcd = node.getElementsByTagName('sec_opcd')
        if sec_opcd:
            so = int(sec_opcd[0].childNodes[0].data, base=16)
            self.opcodes.append(so)

        # Check 0F escape
        if flag:
            self.opcodes.insert(0, flag)

        # Check mandatory prefix
        pref = node.getElementsByTagName('pref')
        if pref:
            prefix = int(pref[0].childNodes[0].data, base=16)
            self.prefix = True
            self.opcodes.insert(0, prefix)

        opcd_ext = node.getElementsByTagName('opcd_ext')
        if opcd_ext:
            self.opcd_ext = int(opcd_ext[0].childNodes[0].data)

        note = node.getElementsByTagName('note')[0]
        brief = note.getElementsByTagName('brief')[0]

        self.description = brief.childNodes[0].data

        if node.hasAttribute('alias'):
            self.alias = node.getAttribute('alias')

        if node.hasAttribute('attr'):
            self.attr = node.getAttribute('attr')
            if self.attr in InstructionSet.ignore_entry:
                return False

        if node.hasAttribute('direction'):
            self.direction = int(node.getAttribute('direction'))

        if node.hasAttribute('op_size'):
            self.op_size = int(node.getAttribute('op_size'))

        if node.hasAttribute('r'):
            self.register = node.getAttribute('r')

        if node.hasAttribute('tttn'):
            self.tttn = node.getAttribute('tttn')

        if node.hasAttribute('sign-ext'):
            self.sign_ext = node.getAttribute('sign-ext')

        if node.hasAttribute('mode'):
            self.run_mode = node.getAttribute('mode')

        if node.hasAttribute('ring'):
            self.ring = node.getAttribute('ring')

        multi_syntax = node.getElementsByTagName('syntax')

        if len(multi_syntax) > 1:
            logging.warning("More than 1 syntax")

        for syntax in multi_syntax:
            # Skip invalid opcode
            if not syntax.childNodes:
                logging.warning("Syntax has no body for %02x. Skip it" % super())
                continue

            mnemonic = syntax.getElementsByTagName('mnem')[0]
            self.mnemonic = mnemonic.childNodes[0].data

            self.is_addressing = ParseOperandFormat(syntax, 'dst', self.operand_fmts)
            self.is_addressing = self.is_addressing or ParseOperandFormat(syntax, 'src', self.operand_fmts)

            if syntax.hasAttribute('mod'):
                self.mod = syntax.getAttribute('mod')
            elif node.hasAttribute('mod'):
                self.mod = node.getAttribute('mod')
            return True
        return False

    def unique_name(self):
        name = self.mnemonic

        if self.attr:
            name += '_%s' % self.attr

        for fmt in self.operand_fmts:
            name += '_%s' % fmt.unique_name()
        return name

    def extract_z_register(self):
        new_inses = []
        for i in range(8):
            new_ins = copy.deepcopy(self)
            new_ins.opcodes[-1] += i
            new_ins.operand_fmts[0].address = 'reg'
            new_ins.operand_fmts[0].group = 'reg'
            new_ins.operand_fmts[0].nr = i
            new_inses.append(new_ins)
        return new_inses


class InstructionSet:
    address_methods = {
        # (
        #  0: 'rm', 'mem', 'direct_addr', 'offset_addr', imm', 'flags', None
        #  1: "default", "reg", "seg", "ctrl", "debug", "test", "x87", "x87m", "mmx", "xmm"
        #  2: Reserved
        # )
        # Direct address. The instruction has no ModR/M byte;
        # the address of the operand is encoded in the instruction;
        # no base register, index register, or scaling factor can be applied (for example, far JMP (EA)).
        "A": ('mem', 'imm', None),

        # Memory addressed by DS:EAX, or by rAX in 64-bit mode (only0F01C8 MONITOR).
        "BA": ('mem', 'reg', 0),

        # Memory addressed by DS:eBX+AL, or by rBX+AL in 64-bit mode (only XLAT).
        # (This code changed from single B in revision 1.00)
        "BB": ('mem', 'reg', 3),

        # Memory addressed by DS:eDI or by RDI (only 0FF7 MASKMOVQ and660FF7 MASKMOVDQU)
        # (This code changed from YD (introduced in 1.00) in revision 1.02)
        "BD": ('mem', 'gen', 7),

        # The reg field of the ModR/M byte selects a control register (only MOV (0F20, 0F22)).
        "C": ('rm', 'reg', 'ctrl'),

        # The reg field of the ModR/M byte selects a debug register (only MOV (0F21, 0F23)).
        "D": ('rm', 'reg', 'debug'),

        # A ModR/M byte follows the opcode and specifies the operand.
        # The operand is either a general-purpose register or a memory address.
        # If it is a memory address, the address is computed from a segment register and any of the following values:
        #  a base register, an index register, a scaling factor, or a displacement.
        "E": ('rm', 'mod', 'reg'),

        # (Implies original E).
        # A ModR/M byte follows the opcode and specifies the operand.
        # The operand is either a x87 FPU stack register or a memory address.
        # If it is a memory address, the address is computed from a segment register and any of the following values:
        #  a base register, an index register, a scaling factor, or a displacement.
        "ES": ('rm', 'mod', 'x87m'),

        # (Implies original E). A ModR/M byte follows the opcode and specifies the x87FPU stack register.
        "EST": ('rm', 'mod', 'x87'),

        # rFLAGS register.
        "F": ('reg', 'flags', None),

        # The reg field of the ModR/M byte selects a general register (for example, AX (000)).
        "G": ('rm', 'reg', 'reg'),

        # The r/m field of the ModR/M byte always selects a general register, regardless of the mod field
        #  (for example, MOV (0F20)).
        "H": ('rm', 'rm', 'reg'),

        # Immediate data. The operand value is encoded in subsequent bytes of the instruction.
        "I": ('imm', None, None),

        # The instruction contains a relative offset to be added to the instruction pointer register
        #  (for example, JMP (E9), LOOP)).
        "J": ('mem', 'imm', None),

        # The ModR/M byte may refer only to memory: mod != 11bin
        #  (BOUND, LEA,CALLF, JMPF, LES, LDS, LSS, LFS, LGS, CMPXCHG8B, CMPXCHG16B,F20FF0 LDDQU).
        "M": ('rm', 'mem', None),

        # The R/M field of the ModR/M byte selects a packed quadword MMXtechnology register.
        "N": ('rm', 'rm', 'mmx'),

        # The instruction has no ModR/M byte;
        # the offset of the operand is coded as a word, double word or quad word (depending on address size attribute) in the instruction.
        # No base register, index register, or scaling factor can be applied (only MOV  (A0, A1, A2, A3)).
        "O": ('offset_addr', None, None),

        # The reg field of the ModR/M byte selects a packed quadword MMXtechnology register.
        "P": ('rm', 'reg', 'mmx'),

        # A ModR/M byte follows the opcode and specifies the operand.
        # The operand is either an MMX technology register or a memory address.
        # If it is a memory address, the address is computed from a segment register and any of the following values:
        #  a base register, an index register, a scaling factor, and a displacement.
        "Q": ('rm', 'mod', 'mmx'),

        # The mod field of the ModR/M byte may refer only to a general register (onlyMOV (0F20-0F24, 0F26)).
        "R": ('rm', 'mod', 'reg'),

        # The reg field of the ModR/M byte selects a segment register (only MOV (8C,8E)).
        "S": ('rm', 'reg', 'seg'),

        # Stack operand, used by instructions which either push an operand to the stack or pop an operand from the stack.
        # Pop-like instructions are, for example, POP, RET, IRET, LEAVE. Push-like are, for example, PUSH, CALL, INT.
        # No Operand type is provided along with this method because it depends on source/destination operand(s).
        "SC": (None, None, None),

        # The reg field of the ModR/M byte selects a test register (only MOV (0F24,0F26)).
        "T": ('rm', 'reg', 'test'),

        # The R/M field of the ModR/M byte selects a 128-bit XMM register.
        "U": ('rm', 'rm', 'xmm'),

        # The reg field of the ModR/M byte selects a 128-bit XMM register.
        "V": ('rm', 'reg', 'xmm'),

        # A ModR/M byte follows the opcode and specifies the operand.
        # The operand is either a 128-bit XMM register or a memory address.
        # If it is a memory address, the address is computed from a segment register and any of the following values:
        #  a base register, an index register, a scaling factor, and a displacement
        "W": ('rm', 'mod', 'xmm'),

        # Memory addressed by the DS:eSI or by RSI (only MOVS, CMPS, OUTS, andLODS).
        # In 64-bit mode, only 64-bit (RSI) and 32-bit (ESI) address sizes are supported.
        # In non-64-bit modes, only 32-bit (ESI) and 16-bit (SI) address sizes are supported.
        "X": ('mem', 'reg', 6),

        # Memory addressed by the ES:eDI or by RDI (only MOVS, CMPS, INS, STOS, andSCAS).
        # In 64-bit mode, only 64-bit (RDI) and 32-bit (EDI) address sizes are supported.
        # In non-64-bit modes, only 32-bit (EDI) and 16-bit (DI) address sizes are supported.
        # The implicit ES segment register cannot be overriden by a segment prefix.
        "Y": ('mem', 'reg', 7),

        # The instruction has no ModR/M byte;
        # the three least-significant bits of the opcode byte selects a general-purpose register
        "Z": ('reg', 'reg', None),
    }

    operand_types = {
        # Two one-word operands in memory or two double-word operands in memory, depending on operand-size attribute
        #  (only BOUND).
        "a": ('word', 'dword', 'dword'),

        # Byte, regardless of operand-size attribute.
        "b": ('byte', 'byte', 'byte'),

        # Packed-BCD. Only x87 FPU instructions (for example, FBLD).
        "bcd": ('bcd80', 'bcd80', 'bcd80'),

        # Byte, sign-extended to the size of the destination operand.
        "bs": ('byte', 'byte', 'byte'),

        # (Byte, sign-extended to 64 bits.)
        "bsq": ('byte', 'byte', 'byte'),

        # Byte, sign-extended to the size of the stack pointer (for example, PUSH (6A)).
        "bss": ('byte', 'byte', 'byte'),

        # Doubleword, regardless of operand-size attribute.
        "d": ('dword', 'dword', 'dqword'),

        # Doubleword-integer. Only x87 FPU instructions (for example, FIADD).
        "di": ('dword', 'dword', 'dqword'),

        # Double-quadword, regardless of operand-size attribute (for example, CMPXCHG16B).
        "dq": ('dqword', 'dqword', 'dqword'),

        # Doubleword, or quadword, promoted by REX.W in 64-bit mode (for example, MOVSXD).
        "dqp": ('dword', 'dword', 'qword'),

        # Double-real. Only x87 FPU instructions (for example, FADD).
        "dr": ('qword', 'qword', 'qword'),

        # Doubleword, sign-extended to 64 bits (for example, CALL (E8).
        "ds": ('dword', 'dword', 'dword'),

        # x87 FPU environment (for example, FSTENV).
        "e": ('e', 'ee', None),

        # Extended-real. Only x87 FPU instructions (for example, FLD).
        "er": ('byte', 'word', 'dword'),

        # Quadword MMX technology data.
        "pi": ('qword', 'qword', 'qword'),

        # 128-bit packed double-precision floating-point data.
        "pd": ('dqword', 'dqword', 'dqword'),

        # 128-bit packed single-precision floating-point data.
        "ps": ('dqword', 'dqword', 'dqword'),

        # 64-bit packed single-precision floating-point data.
        "psq": ('qword', 'qword', 'qword'),

        # (80-bit far pointer.)
        "pt": ('far_pt', 'far_pt', 'far_pt'),

        # Quadword, regardless of operand-size attribute (for example, CALL (FF /2)).
        "q": ('qword', 'qword', 'qword'),

        # Qword-integer. Only x87 FPU instructions (for example, FILD).
        "qi": ('qword', 'qword', 'qword'),

        # Quadword, promoted by REX.W (for example, IRETQ).
        "qp": ('qword', 'qword', 'qword'),

        # 6-byte pseudo-descriptor, or 10-byte pseudo-descriptor in 64-bit mode (for example, SGDT).
        "s": ('pseudo_desc_6bit', 'pseudo_desc_6bit', 'pseudo_desc_10bit'),

        # Scalar element of a 128-bit packed double-precision floating data.
        "sd": ('dqword', 'dqword', 'dqword'),

        # Doubleword integer register (e. g., eax). (unused even by Intel?)
        "si": ('dword', 'dword', 'dword'),

        # Single-real. Only x87 FPU instructions (for example, FADD).
        "sr": ('dword', 'dword', 'dword'),

        # Scalar element of a 128-bit packed single-precision floating data.
        "ss": ('dqword', 'dqword', 'dqword'),

        # x87 FPU state (for example, FSAVE).
        "st": ('st', 'st', 'st_ex'),

        # x87 FPU and SIMD state (FXSAVE and FXRSTOR).
        "stx": ('stx', 'stx', 'stx_ex'),

        # 10-byte far pointer.
        "t": ('far', 'far', 'far'),

        # Word, regardless of operand-size attribute (for example, ENTER).
        "w": ('word', 'word', 'word'),

        # Word-integer. Only x87 FPU instructions (for example, FIADD).
        "wi": ('word', 'word', 'word'),

        # Byte or word, depending on operand-size attribute. (unused even by Intel?)
        "c": ('byte', 'word', None),

        # 32-bit or 48-bit pointer, depending on operand-size attribute (for example, CALLF (9A).
        "p": ('pt_32', 'pt_48', None),

        # 32-bit or 48-bit pointer, depending on operand-size attribute,
        # or 80-bit far pointer, promoted by REX.W in 64-bit mode
        #  (for example,CALLF (FF /3)).
        "ptp": ('pt_32', 'pt_48', 'pt_80'),

        # Word or doubleword, depending on operand-size attribute (for example, INC (40), PUSH (50)).
        "v": ('word', 'dword', None),

        # Word or doubleword, depending on operand-size attribute,
        # or doubleword, sign-extended to 64 bits for 64-bit operand size.
        "vds": ('word', 'dword', 'qword'),

        # Quadword (default) or word if operand-size prefix is used (for example, PUSH (50)).
        "vq": ('qword', 'word', 'qword'),

        # Word or doubleword, depending on operand-size attribute, or quadword, promoted by REX.W in 64-bit mode.
        "vqp": ('word', 'dword', 'qword'),

        # Word or doubleword sign extended to the size of the stack pointer (for example, PUSH (68)).
        "vs": ('word', 'dword', None),
    }

    address_width = ['word', 'dword', 'qword']

    operand_width = ['byte', 'word', 'dword', 'qword', 'dqword']

    ignore_entry = ['invd', 'undef', 'null']

    not_support_ext = [
        "sse1",
        "mmx",
        "sse2",
        "sse3",
        "ssse3",
        "vmx",
        "smx",
        "sse41",
        "sse42",
    ]

    def __init__(self):
        self.instructions = {}
        self.state_map = {}
        self.handler_map = {}
        self.prefix_map = {}
        self.operand_types = {}

    def __parse_prefix(self, entry, pri_opcd, flag):
        if flag:
            raise TypeError

        if entry.hasAttribute('attr'):
            attr = entry.getAttribute('attr')
            if attr in InstructionSet.ignore_entry:
                return None

        # Skip x87 fpu prefix for now
        grp2 = entry.getElementsByTagName('grp2')
        if grp2 and grp2[0].childNodes[0].data == 'x87fpu':
            logging.info("Skip x87fpu prefixes for now", grp2)
            return None

        prefix = InstrPrefix(pri_opcd)
        all_syntax = entry.getElementsByTagName('syntax')
        if len(all_syntax) > 1:
            logging.warninging("More than 1 syntax")

        syntax = all_syntax[0]
        if syntax:
            mnemonic = syntax.getElementsByTagName('mnem')
            if mnemonic:
                prefix.mnemonic = mnemonic[0].childNodes[0].data

            self.prefix_map[pri_opcd] = prefix

        return prefix

    def __parse_regular_instruction(self, entry, pri_opcd, flag):
        # Skip Intel-64 instructions
        if entry.hasAttribute('mode') and entry.getAttribute('mode') == 'e':
            logging.info("Skip 64bit for now", pri_opcd)
            return None

        if entry.hasAttribute('instr_ext'):
            instr_ext = entry.getAttribute('instr_ext')
            if instr_ext in InstructionSet.not_support_ext:
                return None

        if entry.hasAttribute('doc_ref') or entry.hasAttribute('doc64_ref') or entry.hasAttribute('doc3264_ref'):
            return None

        if entry.getElementsByTagName('proc_start'):
            proc_start = entry.getElementsByTagName('proc_start')[0].childNodes[0].data
            if proc_start == '99':
                logging.info('Skip IA64 instruction', pri_opcd)
                return None

        is_undoc = False
        if entry.hasAttribute('is_undoc'):
            is_undoc = (entry.getAttribute('is_undoc') == 'yes')
        elif entry.hasAttribute('is_doc'):
            is_undoc = (entry.getAttribute('is_doc') != 'yes')
        if is_undoc:
            return None

        instruction = Instruction(pri_opcd, flag)

        try:
            if instruction.parse(entry):
                return instruction
        except Exception as err:
            logging.error('Error while parsing instruction', err)
            return None

        return None

    def __parse_entry(self, entry, pri_opcd, flag):
        # Check prefix code. If yes, parse it as prefix
        if entry.getElementsByTagName('grp1'):
            if entry.getElementsByTagName('grp1')[0].childNodes[0].data == 'prefix':
                logging.info("Parsing prefix code %02X" % pri_opcd)
                return self.__parse_prefix(entry, pri_opcd, flag)

        instruction = self.__parse_regular_instruction(entry, pri_opcd, flag)
        InsertInstruction(instruction)

    def __parse_instruction(self, node, flag):
        ops = node.getElementsByTagName('pri_opcd')
        for op in ops:
            pri_opcd = int(op.getAttribute('value'), base=16)

            if 0xd8 <= pri_opcd <= 0xdf:
                continue

            entries = op.getElementsByTagName('entry')
            if len(entries) > 1:
                logging.warning('There are more than 1 entries for %02x' % pri_opcd)

            for entry in entries:
                self.__parse_entry(entry, pri_opcd, flag)

    def __parse_node(self, node):
        one_byte = node.getElementsByTagName('one-byte')[0]
        self.__parse_instruction(one_byte, None)

        two_byte = node.getElementsByTagName('two-byte')[0]
        self.__parse_instruction(two_byte, 0x0f)

    def parse_file(self, infile):
        dom_tree = xml.dom.minidom.parse(infile)
        x86ref = dom_tree.documentElement
        self.__parse_node(x86ref)


def ParseOperandFormat(node, indicator, ops):
    operands = node.getElementsByTagName(indicator)
    if not operands:
        return False

    is_addressing = False
    for operand in operands:
        if operand.hasAttribute('displayed') and operand.getAttribute('displayed') == 'no':
            continue

        if operand.hasAttribute('address'):
            a = operand.getAttribute('address')
        elif operand.getElementsByTagName('a'):
            a = operand.getElementsByTagName('a')[0].childNodes[0].data
        else:
            a = ""

        if operand.hasAttribute('type'):
            t = operand.getAttribute('type')
        elif operand.getElementsByTagName('t'):
            t = operand.getElementsByTagName('t')[0].childNodes[0].data
        else:
            t = ""

        if t == 'wo':
            t = 'w'
        elif t == 'do':
            t = 'd'

        if operand.hasAttribute('nr'):
            nr = int(operand.getAttribute('nr'))
        else:
            nr = -1

        if operand.hasAttribute('group'):
            group = operand.getAttribute('group')
        else:
            group = None

        op_format = OperandFormat(indicator, a, t, group, nr)
        is_addressing = is_addressing or op_format.is_addressing()
        ops.append(op_format)

    return is_addressing
