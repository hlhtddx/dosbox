#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

from optparse import OptionParser
import xml.dom.minidom
import copy
import logging


class X86Error(Exception):
    def __init__(self, what):
        super(Exception, self).__init__()


class OperandFormat:
    """
    To specify the format of each operand.
    """
    def __init__(self, ind, displayed):
        self.ind = ind
        self.is_addressing = False
        self.address = None
        self.type = None
        self.origin_type = None
        self.origin_addr = None
        self.displayed = displayed

    def __str__(self):
        return self.unique_name

    def parse(self, node):
        if node.hasAttribute('group'):
            group = node.getAttribute('group')
            if not group in InstructionSet.available_groups:
                return False
            nr = int(node.getAttribute('nr'))
            self.address = ('reg', group, nr)
            self.origin_addr = None
        else:
            if node.hasAttribute('address'):
                self.origin_addr = address = node.getAttribute('address')
            elif node.getElementsByTagName('a'):
                self.origin_addr = address = node.getElementsByTagName('a')[0].childNodes[0].data
            else:
                return False

            self.address = InstructionSet.address_methods[address]

        if node.hasAttribute('type'):
            op_type = node.getAttribute('type')
        elif node.getElementsByTagName('t'):
            op_type = node.getElementsByTagName('t')[0].childNodes[0].data
        else:
            return False

        self.origin_type = op_type
        self.type = InstructionSet.operand_types[op_type] if op_type else None

        if not self.origin_addr:
            self.origin_addr = InstructionSet.registers[op_type][self.address[1]][self.address[2]]

        if self.address[0] == 'mem':
            self.is_addressing = True
        elif self.address[0] == 'rm' and self.address[1] != 'reg':
            self.is_addressing = True
        else:
            self.is_addressing = False

        return True

    @property
    def unique_name(self):
        # s = ''
        # for address in self.address:
        #     if address:
        #         s += '_%s' % address
        # return s + '_' + self.origin_type
        return f'_{self.origin_addr}{self.origin_type}'

    def unique_sized_names(self, operand_size):
        return self.unique_name + '_' + self.type[operand_size]

    def support_operand_size(self, operand_size):
        if not self.type[operand_size]:
            return False
        if self.type[operand_size][0] == 'x':
            return False
        return True


class OperandFormatList:
    """
    To specify the format of all operands.
    """
    def __init__(self):
        self.operands = []
        self.hidden_operands = []
        self.is_addressing = False

    def __str__(self):
        return self.unique_name()

    def __parse_operand(self, node, indicator):
        all_operands = node.getElementsByTagName(indicator)
        if not all_operands:
            return

        for operand in all_operands:
            operands = self.operands
            displayed = True
            if operand.hasAttribute('displayed') and operand.getAttribute('displayed') == 'no':
                operands = self.hidden_operands
                displayed = False

            op_format = OperandFormat(indicator, displayed)
            if not op_format.parse(operand):
                continue

            if op_format.is_addressing:
                self.is_addressing = True
            operands.append(op_format)

    def parse(self, node):
        self.__parse_operand(node, 'dst')
        self.__parse_operand(node, 'src')

    def unique_sized_names(self, operand_size):
        return self.unique_name() + '_' + self.type[operand_size]

    def unique_name(self):
        s = ''
        operand: OperandFormat
        for operand in self.operands:
            if operand:
                s += operand.unique_name
        return s

    def support_operand_size(self, operand_size):
        for operand in self.operands + self.hidden_operands:
            if not operand.support_operand_size(operand_size):
                return False
        return True


class InstructionBase:
    def __init__(self, pri_opcd):
        self.mnemonic = ''          # mnemonic of instruction
        self.description = ''       # description
        self.opcodes = [pri_opcd]   # opcodes, including the mandatory prefix

    def __str__(self):
        return self.opcode_str

    @property
    def opcode_str(self):
        s = ''
        for opcode in self.opcodes:
            s += '_%02X' % opcode
        return s

    def parse(self, node):
        return False


class InstrPrefix(InstructionBase):
    def __init__(self, pri_opcd):
        super(InstrPrefix, self).__init__(pri_opcd)

    def __str__(self):
        # type: () -> object
        return 'prefix' + super(InstrPrefix, self).__str__()

    def parse(self, node):
        return False

    @property
    def unique_name(self):
        return self.__str__


class Instruction(InstructionBase):
    opcd_ext = None  # type: int

    def __init__(self, pri_opcd):
        super(Instruction, self).__init__(pri_opcd)
        # mandatory prefix. It may be 0x66, 0xF2 or 0xF3
        self.prefix = ()
        # operands' format
        self.op_fmts = OperandFormatList()
        # opcode extension coded in R/M bits in MODR/M byte
        self.opcd_ext = -1
        # if alias
        self.alias = None
        # extra attribute, 'invd', etc.
        self.attr = None
        # in which extension, 'mmx', 'sse', etc.
        self.instr_ext = None
        # R = real/proteced/64, P = protected/64, E = 64 only, S = SMM
        self.run_mode = None
        # whether is documented. <entry.is_doc> or <entry.is_undoc>
        self.is_doc = True
        # documented in which part
        self.doc = None
        # -1 = N/A, 0 = R/M<-REG, 1 = REG<-R/M
        self.direction = -1
        # -1 = N/A, 0 = b, 1 = w/d
        self.op_size = -1
        # False=size regardless, True = size dependant
        self.ad_size = False
        # -1 = N/A, 0 = unsigned(0-ext), 1 = signed(1-ext)
        self.sign_ext = -1
        # indicates that the ModR/M byte contains a register operand and an r/m operand.
        self.rm = ''
        # test conditions
        self.tttn = -1
        # mod field in MODR/M byte: 'mem'=00,01,10, 'nomem'=11
        self.mod = None
        self.ring = None
        self.proc_start = 0

    def __str__(self):
        return (f'Instruction: prefix={self.prefix} opcode={self.opcode_str} opcd_ext={self.opcd_ext:02x}\n'
                f'    mnemonic={self.mnemonic} op_fmts={self.op_fmts} mod={self.mod}\n'
                f'    description={self.description}\n'
                f'    run_mode={self.run_mode} ring={self.ring} attr={self.attr} is_doc={self.is_doc}\n'
                f'    direction={self.direction:d} op_size={self.op_size:d} ad_size={self.ad_size}'
                f'    sign_ext={self.sign_ext} register={self.rm} tttn={self.tttn}')

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
            self.prefix = (prefix, )

        opcd_ext = node.getElementsByTagName('opcd_ext')
        if opcd_ext:
            self.opcd_ext = int(opcd_ext[0].childNodes[0].data)

        note = node.getElementsByTagName('note')
        if note:
            brief = note[0].getElementsByTagName('brief')[0]
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
            self.rm = node.getAttribute('r')

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
                logging.warning("Syntax has no body for %s. Skip it" % super().__str__)
                continue

            mnemonic = syntax.getElementsByTagName('mnem')[0]
            self.mnemonic = mnemonic.childNodes[0].data
            self.op_fmts.parse(syntax)

            if syntax.hasAttribute('mod'):
                self.mod = syntax.getAttribute('mod')
            elif node.hasAttribute('mod'):
                self.mod = node.getAttribute('mod')
            return True
        return False

    @property
    def is_addressing(self):
        return self.op_fmts.is_addressing

    def support_operand_size(self, operand_size):
        return self.op_fmts.support_operand_size(operand_size)

    @property
    def unique_name(self) -> str:
        return f'{self.mnemonic}{self.op_fmts}'

    def extract_z_register(self):
        new_inses = []
        for i in range(8):
            new_ins = copy.deepcopy(self)
            new_ins.opcodes[-1] += i
            new_ins.op_fmts[0].address = 'reg'
            new_ins.op_fmts[0].group = 'reg'
            new_ins.op_fmts[0].nr = i
            new_inses.append(new_ins)
        return new_inses


class InstructionSet:
    address_methods = {
        # (
        #  0: 'rm', 'mem', 'reg', 'imm', None
        #  1: "default", "reg", "seg", "ctrl", "debug", "test", "x87", "x87m", "mmx", "xmm"
        #  2: Reserved
        # )
        # Direct address. The instruction has no ModR/M byte;
        # the address of the operand is encoded in the instruction;
        # no base register, index register, or scaling factor can be applied (for example, far JMP (EA)).
        "A": ('mem', 'immA', None),

        # Memory addressed by DS:EAX, or by rAX in 64-bit mode (only0F01C8 MONITOR).
        "BA": ('mem', 'gen', 0),

        # Memory addressed by DS:eBX+AL, or by rBX+AL in 64-bit mode (only XLAT).
        # (This code changed from single B in revision 1.00)
        "BB": ('mem', 'gen', 3),

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
        "G": ('rm', 'reg', 'gen'),

        # The r/m field of the ModR/M byte always selects a general register, regardless of the mod field
        #  (for example, MOV (0F20)).
        "H": ('rm', 'rm', 'gen'),

        # Immediate data. The operand value is encoded in subsequent bytes of the instruction.
        "I": ('imm', None, None),

        # The instruction contains a relative offset to be added to the instruction pointer register
        #  (for example, JMP (E9), LOOP)).
        "J": ('imm', None, None),

        # The ModR/M byte may refer only to memory: mod != 11bin
        #  (BOUND, LEA,CALLF, JMPF, LES, LDS, LSS, LFS, LGS, CMPXCHG8B, CMPXCHG16B,F20FF0 LDDQU).
        "M": ('rm', 'mem', None),

        # The R/M field of the ModR/M byte selects a packed quadword MMXtechnology register.
        "N": ('rm', 'rm', 'mmx'),

        # The instruction has no ModR/M byte;
        # the offset of the operand is coded as a word, double word or quad word (depending on address size attribute) in the instruction.
        # No base register, index register, or scaling factor can be applied (only MOV  (A0, A1, A2, A3)).
        "O": ('imm', None, None),

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
        "X": ('mem', 'gen', 6),

        # Memory addressed by the ES:eDI or by RDI (only MOVS, CMPS, INS, STOS, andSCAS).
        # In 64-bit mode, only 64-bit (RDI) and 32-bit (EDI) address sizes are supported.
        # In non-64-bit modes, only 32-bit (EDI) and 16-bit (DI) address sizes are supported.
        # The implicit ES segment register cannot be overriden by a segment prefix.
        "Y": ('mem', 'gen', 7),

        # The instruction has no ModR/M byte;
        # the three least-significant bits of the opcode byte selects a general-purpose register
        "Z": ('reg', 'gen', None),
        "Z0": ('reg', 'gen', 0),
        "Z1": ('reg', 'gen', 1),
        "Z2": ('reg', 'gen', 2),
        "Z3": ('reg', 'gen', 3),
        "Z4": ('reg', 'gen', 4),
        "Z5": ('reg', 'gen', 5),
        "Z6": ('reg', 'gen', 6),
        "Z7": ('reg', 'gen', 7),
    }

    # data types: default = u
    #  (u = unsigned integer, i = signed integer, f = single-precision float, d = double-precision float
    #   p = pointer, c = BCD encoded data, e = x87 FPU environment
    #   x = unsupported)
    data_type = ('u', 'i', 'f', 'd', 'p', 'c', 'e')
    data_size = ('8', '16', '32', '64', '128', '256', '48', '80')

    operand_types = {
        # Two one-word operands in memory or two double-word operands in memory, depending on operand-size attribute
        #  (only BOUND).
        "a": (('u', 16), ('u', 32), ('u', 32)),

        # Byte, regardless of operand-size attribute.
        "b": (('u', 8), ('u', 8), ('u', 8)),

        # Packed-BCD. Only x87 FPU instructions (for example, FBLD).
        "bcd": (('c', 80), ('c', 80), ('c', 80)),

        # Byte, sign-extended to the size of the destination operand.
        "bs": (('u', 8), ('u', 8), ('u', 8)),

        # (Byte, sign-extended to 64 bits.)
        "bsq": (('i', 8), ('i', 8), ('i', 8)),

        # Byte, sign-extended to the size of the stack pointer (for example, PUSH (6A)).
        "bss": (('i', 8), ('i', 8), ('i', 8)),

        # Doubleword, regardless of operand-size attribute.
        "d": (('u', 32), ('u', 32), ('u', 128)),

        # Doubleword-integer. Only x87 FPU instructions (for example, FIADD).
        "di": (('u', 32), ('u', 32), ('u', 128)),

        # Double-quadword, regardless of operand-size attribute (for example, CMPXCHG16B).
        "dq": (('u', 128), ('u', 128), ('u', 128)),

        # Doubleword, or quadword, promoted by REX.W in 64-bit mode (for example, MOVSXD).
        "dqp": (('u', 32), ('u', 32), ('u', 64)),

        # Double-real. Only x87 FPU instructions (for example, FADD).
        "dr": (('u', 64), ('u', 64), ('u', 64)),

        # Doubleword, sign-extended to 64 bits (for example, CALL (E8).
        "ds": (('s', 32), ('s', 32), ('s', 32)),

        # x87 FPU environment (for example, FSTENV).
        "e": (None, None, None),

        # Extended-real. Only x87 FPU instructions (for example, FLD).
        "er": (('u', 8), ('u', 16), ('u', 32)),

        # Quadword MMX technology data.
        "pi": (('u', 64), ('u', 64), ('u', 64)),

        # 128-bit packed double-precision floating-point data.
        "pd": (('d', 128), ('d', 128), ('d', 128)),

        # 128-bit packed single-precision floating-point data.
        "ps": (('f', 128), ('f', 128), ('f', 128)),

        # 64-bit packed single-precision floating-point data.
        "psq": (('f', 64), ('f', 64), ('f', 64)),

        # (80-bit far pointer.)
        "pt": (('p', 80), ('p', 80), ('p', 80)),

        # Quadword, regardless of operand-size attribute (for example, CALL (FF /2)).
        "q": (('u', 64), ('u', 64), ('u', 64)),

        # Qword-integer. Only x87 FPU instructions (for example, FILD).
        "qi": (('u', 64), ('u', 64), ('u', 64)),

        # Quadword, promoted by REX.W (for example, IRETQ).
        "qp": (('u', 64), ('u', 64), ('u', 64)),

        # 6-byte pseudo-descriptor, or 10-byte pseudo-descriptor in 64-bit mode (for example, SGDT).
        "s": (('x', 48), ('x', 48), ('x', 80)),

        # Scalar element of a 128-bit packed double-precision floating data.
        "sd": (('d', 128), ('d', 128), ('d', 128)),

        # Doubleword integer register (e. g., eax). (unused even by Intel?)
        "si": (('u', 32), ('u', 32), ('u', 32)),

        # Single-real. Only x87 FPU instructions (for example, FADD).
        "sr": (('u', 32), ('u', 32), ('u', 32)),

        # Scalar element of a 128-bit packed single-precision floating data.
        "ss": (('f', 128), ('f', 128), ('f', 128)),

        # x87 FPU state (for example, FSAVE).
        "st": (None, None, None),

        # x87 FPU and SIMD state (FXSAVE and FXRSTOR).
        "stx": (None, None, None),

        # 10-byte far pointer.
        "t": (('p', 80), ('p', 80), ('p', 80)),

        # Word, regardless of operand-size attribute (for example, ENTER).
        "w": (('u', 16), ('u', 16), ('u', 16)),

        # Word-integer. Only x87 FPU instructions (for example, FIADD).
        "wi": (('u', 16), ('u', 16), ('u', 16)),

        # Byte or u16, depending on operand-size attribute. (unused even by Intel?)
        "c": (('u', 8), ('u', 16), None),

        # 32-bit or 48-bit pointer, depending on operand-size attribute (for example, CALLF (9A).
        "p": (('p', 16), ('p', 32), None),

        # 32-bit or 48-bit pointer, depending on operand-size attribute,
        # or 80-bit far pointer, promoted by REX.W in 64-bit mode
        #  (for example,CALLF (FF /3)).
        "ptp": (('p', 16), ('p', 32), ('p', 64)),

        # Word or doubleword, depending on operand-size attribute (for example, INC (40), PUSH (50)).
        "v": (('u', 16), ('u', 32), None),

        # Word or doubleword, depending on operand-size attribute (for example, INC (40), PUSH (50)).
        "va": (('u', 16), ('u', 32), None),

        # Word or doubleword, depending on operand-size attribute,
        # or doubleword, sign-extended to 64 bits for 64-bit operand size.
        "vds": (('i', 16), ('i', 32), ('i', 32)),

        # Quadword (default) or u16 if operand-size prefix is used (for example, PUSH (50)).
        "vq": (('u', 16), ('u', 32), ('u', 64)),

        # Word or doubleword, depending on operand-size attribute, or quadword, promoted by REX.W in 64-bit mode.
        "vqp": (('u', 16), ('u', 32), ('u', 64)),

        # Word or doubleword sign extended to the size of the stack pointer (for example, PUSH (68)).
        "vs": (('i', 16), ('i', 32), ('i', 32)),

        # Word only, for.
        "wo": (('u', 16), None, None),

        # Word only, for.
        "wa": (('u', 16), None, None),

        # Doubleword only.
        "do": (None, ('u', 32), None),

        # Doubleword only.
        "da": (None, ('u', 32), None),
    }

    address_width = ['word', 'dword', 'qword']
    operand_width = ['byte', 'word', 'dword', 'qword', 'dqword']
    available_groups = ('gen', 'seg')
    ignore_entry = ['invd', 'undef', 'null']

    gen_b = ('AL', 'CL', 'DL', 'BH', 'AH', 'CH', 'DH', 'BH')
    gen_w = ('AX', 'CX', 'DX', 'BX', 'SP', 'BP', 'SI', 'DI')
    gen_d = ('EAX', 'ECX', 'EDX', 'EBX', 'ESP', 'EBP', 'ESI', 'EDI')
    gen_v = ('rAX', 'rCX', 'rDX', 'rBX', 'rSP', 'rBP', 'rSI', 'rDI')
    seg_v = ('ES', 'CS', 'SS', 'DS', 'FS', 'GS', None, None)
    ctl_v = ('CR0', None, 'CR2', 'CR3', 'CR4', None, None, None)
    dbg_v = ('DR0', 'DR1', 'DR2', 'DR3', None, None, 'DR6', 'DR7')

    registers = {
        # Two one-word operands in memory or two double-word operands in memory, depending on operand-size attribute
        #  (only BOUND).
        "a": {'gen': gen_b, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # Byte, regardless of operand-size attribute.
        "b": {'gen': gen_b, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # Packed-BCD. Only x87 FPU instructions (for example, FBLD).
        "bcd": {'gen': gen_b, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # Byte, sign-extended to the size of the destination operand.
        "bs": {'gen': gen_b, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # (Byte, sign-extended to 64 bits.)
        "bsq": {'gen': gen_b, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # Byte, sign-extended to the size of the stack pointer (for example, PUSH (6A)).
        "bss": {'gen': gen_b, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # Doubleword, regardless of operand-size attribute.
        "d": {'gen': gen_d, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # Doubleword-integer. Only x87 FPU instructions (for example, FIADD).
        "di": {'gen': gen_d, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # Double-quadword, regardless of operand-size attribute (for example, CMPXCHG16B).
        "dq": {'gen': gen_d, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # Doubleword, or quadword, promoted by REX.W in 64-bit mode (for example, MOVSXD).
        "dqp": {'gen': gen_d, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # Double-real. Only x87 FPU instructions (for example, FADD).
        "dr": {'gen': gen_d, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # Doubleword, sign-extended to 64 bits (for example, CALL (E8).
        "ds": {'gen': gen_d, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # x87 FPU environment (for example, FSTENV).
        "e": (None, None, None),

        # Extended-real. Only x87 FPU instructions (for example, FLD).
        "er": {'gen': gen_b, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # Quadword MMX technology data.
        "pi": {'gen': gen_b, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # 128-bit packed double-precision floating-point data.
        "pd": {'gen': gen_b, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # 128-bit packed single-precision floating-point data.
        "ps": {'gen': gen_b, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # 64-bit packed single-precision floating-point data.
        "psq": {'gen': gen_b, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # (80-bit far pointer.)
        "pt": {'gen': gen_b, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # Quadword, regardless of operand-size attribute (for example, CALL (FF /2)).
        "q": {'gen': gen_b, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # Qword-integer. Only x87 FPU instructions (for example, FILD).
        "qi": {'gen': gen_b, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # Quadword, promoted by REX.W (for example, IRETQ).
        "qp": {'gen': gen_b, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # 6-byte pseudo-descriptor, or 10-byte pseudo-descriptor in 64-bit mode (for example, SGDT).
        "s": {'gen': gen_b, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # Scalar element of a 128-bit packed double-precision floating data.
        "sd": {'gen': gen_b, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # Doubleword integer register (e. g., eax). (unused even by Intel?)
        "si": {'gen': gen_d, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # Single-real. Only x87 FPU instructions (for example, FADD).
        "sr": {'gen': gen_b, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # Scalar element of a 128-bit packed single-precision floating data.
        "ss": {'gen': gen_b, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # x87 FPU state (for example, FSAVE).
        "st": (None, None, None),

        # x87 FPU and SIMD state (FXSAVE and FXRSTOR).
        "stx": (None, None, None),

        # 10-byte far pointer.
        "t": {'gen': gen_b, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # Word, regardless of operand-size attribute (for example, ENTER).
        "w": {'gen': gen_w, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # Word-integer. Only x87 FPU instructions (for example, FIADD).
        "wi": {'gen': gen_w, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # Byte or u16, depending on operand-size attribute. (unused even by Intel?)
        "c": {'gen': gen_b, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # 32-bit or 48-bit pointer, depending on operand-size attribute (for example, CALLF (9A).
        "p": {'gen': gen_b, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # 32-bit or 48-bit pointer, depending on operand-size attribute,
        # or 80-bit far pointer, promoted by REX.W in 64-bit mode
        #  (for example,CALLF (FF /3)).
        "ptp": {'gen': gen_b, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # Word or doubleword, depending on operand-size attribute (for example, INC (40), PUSH (50)).
        "v": {'gen': gen_v, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # Word or doubleword, depending on operand-size attribute (for example, INC (40), PUSH (50)).
        "va": {'gen': gen_v, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # Word or doubleword, depending on operand-size attribute,
        # or doubleword, sign-extended to 64 bits for 64-bit operand size.
        "vds": {'gen': gen_v, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # Quadword (default) or u16 if operand-size prefix is used (for example, PUSH (50)).
        "vq": {'gen': gen_v, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # Word or doubleword, depending on operand-size attribute, or quadword, promoted by REX.W in 64-bit mode.
        "vqp": {'gen': gen_v, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # Word or doubleword sign extended to the size of the stack pointer (for example, PUSH (68)).
        "vs": {'gen': gen_v, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # Word only, for.
        "wo": {'gen': gen_w, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # Word only, for.
        "wa": {'gen': gen_w, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # Doubleword only.
        "do": {'gen': gen_d, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},

        # Doubleword only.
        "da": {'gen': gen_d, 'seg': seg_v, 'ctrl': ctl_v, 'debug': dbg_v},
    }

    not_support_ext = [
        "mmx",
        "sse1",
        "sse2",
        "sse3",
        "ssse3",
        "sse41",
        "sse42",
        "vmx",
        "smx",
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
            logging.info("Skip x87fpu prefixes for now (grp2=%s)", grp2)
            return None

        prefix = InstrPrefix(pri_opcd)
        all_syntax = entry.getElementsByTagName('syntax')
        if len(all_syntax) > 1:
            logging.warning("More than 1 syntax")

        syntax = all_syntax[0]
        if syntax:
            mnemonic = syntax.getElementsByTagName('mnem')
            if mnemonic:
                prefix.mnemonic = mnemonic[0].childNodes[0].data

            self.prefix_map[pri_opcd] = prefix

        return prefix

    def __parse_regular_instruction(self, entry, pri_opcd, flag):

        instruction = Instruction(pri_opcd)

        try:
            if instruction.parse(entry, flag):
                return instruction
        except X86Error as err:
            logging.error('Error while parsing instruction', err)
            return None

        return None

    def __insert_instruction(self, instruction):
        key = instruction.unique_name
        self.instructions[key] = instruction

    def __parse_entry(self, entry, pri_opcd, flag):

        if entry.getElementsByTagName('instr_ext'):
            instr_ext = entry.getElementsByTagName('instr_ext')[0].childNodes[0].data
            if instr_ext in InstructionSet.not_support_ext:
                return None

        # Skip Intel-64 instructions
        if entry.hasAttribute('mode') and entry.getAttribute('mode') == 'e':
            logging.info("Skip 64bit for now (pri_opcd=02%x)", pri_opcd)
            return None
        #
        # if entry.hasAttribute('doc_ref') or entry.hasAttribute('doc64_ref') or entry.hasAttribute('doc3264_ref'):
        #     return None

        if entry.getElementsByTagName('proc_start'):
            proc_start = entry.getElementsByTagName('proc_start')[0].childNodes[0].data
            if proc_start == '99':
                logging.info('Skip IA64 instruction (pri_opcd=02%x)', pri_opcd)
                return None
            if int(proc_start) > 4:
                logging.info('Skip Pentium instruction (pri_opcd=02%x)', pri_opcd)
                return

        is_undoc = False
        if entry.hasAttribute('is_undoc'):
            is_undoc = (entry.getAttribute('is_undoc') == 'yes')
        elif entry.hasAttribute('is_doc'):
            is_undoc = (entry.getAttribute('is_doc') != 'yes')
        if is_undoc:
            return None

        # Check prefix code. If yes, parse it as prefix
        if entry.getElementsByTagName('grp1') and entry.getElementsByTagName('grp1')[0].childNodes[0].data == 'prefix':
            logging.info("Parsing prefix code %02X" % pri_opcd)
            instruction = self.__parse_prefix(entry, pri_opcd, flag)
        else:
            instruction = self.__parse_regular_instruction(entry, pri_opcd, flag)

        if instruction:
            if isinstance(instruction, Instruction) and instruction.op_fmts.operands and instruction.op_fmts.operands[0].origin_addr == 'Z':
                for i in range(8):
                    sub_instruction = copy.deepcopy(instruction)
                    sub_instruction.opcodes[-1] = sub_instruction.opcodes[-1] + i
                    sub_instruction.op_fmts.operands[0].origin_addr = InstructionSet.registers[sub_instruction.op_fmts.operands[0].origin_type]['gen'][i]
                    sub_instruction.op_fmts.operands[0].address = ('reg', 'gen', i)
                    self.__insert_instruction(sub_instruction)
            else:
                self.__insert_instruction(instruction)

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

    def dump_file(self, outfile):
        for instruction in self.instructions:
            outfile.write('%s\n' % instruction)
