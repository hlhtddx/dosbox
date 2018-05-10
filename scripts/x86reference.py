#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

import xml.dom.minidom
import copy
import sys
import logging

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

    def unique_sized_names(self, operand_size):
        return self.unique_name() + '_' + self.type[operand_size]

    def unique_name(self):
        s = ''
        for operands in self.operands:
            if operands:
                s += '%s_' % operands
        return s + self.origin_type


class InstructionBase:
    def __init__(self):
        self.mnemonic = ''      # mnemonic of instruction
        self.description = ''  # description
        self.opcodes = []       # opcodes, including the mandatory prefix

    def __str__(self):
        s = ''
        for opcode in self.opcodes:
            s += '_%02X' % opcode
        return s


class InstrPrefix(InstructionBase):
    def __init__(self, opcode):
        self.opcodes.append(opcode)

    def __str__(self):
        return 'prefix' + super.__str__()

    def unique_name(self):
        return self.__str__()


class Instruction(InstructionBase):
    def __init__(self):
        self.prefix = False  # mandatory prefix
        self.operand_fmts = []  # operands
        self.opcd_ext = -1  # opcode extension coded in R/M bits in MODR/M byte
        self.alias = None  # if alias
        self.attr = None  # extra attribute, 'invd', etc.
        self.instr_ext = None  # in which extension, mmx, sse, etc.
        self.run_mode = None  # R = real/proteced/64, P = protected/64, E = 64 only, S = SMM
        self.is_doc = True  # whether is documented. <entry.is_doc> or <entry.is_undoc>
        self.doc = None  # documented in which part
        self.direction = -1  # -1 = N/A, 0 = R/M<-REG, 1 = REG<-R/M
        self.op_size = -1  # -1 = N/A, 0 = b, 1 = w/d
        self.ad_size = False  # False=size regardless, True = size dependant
        self.sign_ext = -1  # -1 = N/A, 0 = unsigned(0-ext), 1 = signed(1-ext)
        self.register = ''  # indicates that the ModR/M byte contains a register operand and an r/m operand.
        self.tttn = -1  # test conditions
        self.mod = None  # mod field in MODR/M byte: 'mem'=00,01,10, 'nomem'=11
        self.ring = None

    def __str__(self):
        s = 'opcode['
        for opcode in self.opcodes:
            s += '%02X,' % opcode
        s = s[:-1]
        s += ']\n'
        if self.opcd_ext >= 0:
            s += 'opcode_ext:%x\n' % self.opcd_ext
        s += 'unique name:%s\n' % self.unique_name()

        s += 'operand format[\n'
        for fmt in self.operand_fmts:
            s += str(fmt)
        s += ']\n'

        if self.mod:
            s += 'mod:%s\n' % self.mod

        if self.opcd_ext >= 0:
            s += 'opcode_ext:%x\n' % self.opcd_ext

        s += 'description:%s\n' % self.description
        s += 'mode:%s\n' % self.run_mode
        s += 'attr:%s\n' % self.attr
        s += 'is_doc:%s\n' % self.is_doc
        s += 'doc:%s\n' % self.doc
        s += 'direction:%s\n' % self.direction
        s += 'op_size:%s\n' % self.op_size
        s += 'sign_ext:%s\n' % self.sign_ext
        s += 'register:%s\n' % self.register
        s += 'tttn:%s\n' % self.tttn
        s += 'ring:%s\n' % self.ring
        return s

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



def ParseOperandFormat(node, opt, ops):
    operands = node.getElementsByTagName(opt)
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

        op_format = OperandFormat(opt, a, t, group, nr)
        is_addressing = is_addressing or op_format.is_addressing()
        ops.append(op_format)

    return is_addressing

def ParsePrefix(entry, po, flag):
    if flag:
        raise TypeError

    if entry.hasAttribute('attr'):
        attr = entry.getAttribute('attr')
        if attr in ignore_entry:
            return

    grp2 = entry.getElementsByTagName('grp2')
    if grp2 and grp2[0].childNodes[0].data == 'x87fpu':
        return

    syntaxes = entry.getElementsByTagName('syntax')
    if len(syntaxes) > 1:
        print("More than 1 syntax")

    syntax = syntaxes[0]
    if syntax:
        prefix = InstrPrefix(po)
        mnemonic = syntax.getElementsByTagName('mnem')
        if mnemonic:
            prefix.mnemonic = (mnemonic[0].childNodes[0].data)
        prefix_map[po] = prefix
        if not po in mandatory_prefixes and not po in option_prefixes:
            option_prefixes.append(po)
            root_node.link[po] = prefix


def ParseEntry(entry, po, flag):
    syntaxes = entry.getElementsByTagName('syntax')
    if len(syntaxes) > 1:
        print("More than 1 syntax")

    syntax = syntaxes[0]
    if syntax:
        # Skip invalid opcode
        if not syntax.childNodes:
            print("syntax no body", po)
            return

        ins = Instruction()
        ins.opcodes.append(po)

        # Check secondary_opcode
        sec_opcd = entry.getElementsByTagName('sec_opcd')
        if sec_opcd:
            so = int(sec_opcd[0].childNodes[0].data, base=16)
            ins.opcodes.append(so)

        # Check 0F escape
        if flag:
            ins.opcodes.insert(0, flag)

        # Check mandatory prefix
        pref = entry.getElementsByTagName('pref')
        if pref:
            prefix = int(pref[0].childNodes[0].data, base=16)
            ins.prefix = True
            ins.opcodes.insert(0, prefix)

        opcd_ext = entry.getElementsByTagName('opcd_ext')
        if opcd_ext:
            ins.opcd_ext = int(opcd_ext[0].childNodes[0].data)

        mnemonic = syntax.getElementsByTagName('mnem')[0]
        ins.mnemonic = (mnemonic.childNodes[0].data)

        ins.is_addressing = ParseOperandFormat(syntax, 'dst', ins.operand_fmts)
        ins.is_addressing = ins.is_addressing or ParseOperandFormat(syntax, 'src', ins.operand_fmts)

        note = entry.getElementsByTagName('note')[0]
        brief = note.getElementsByTagName('brief')[0]

        ins.description = brief.childNodes[0].data

        if entry.hasAttribute('alias'):
            ins.alias = entry.getAttribute('alias')

        if entry.hasAttribute('attr'):
            ins.attr = entry.getAttribute('attr')

        if ins.attr in ignore_entry:
            return

        if entry.hasAttribute('direction'):
            ins.direction = int(entry.getAttribute('direction'))

        if entry.hasAttribute('op_size'):
            ins.op_size = int(entry.getAttribute('op_size'))

        if entry.hasAttribute('r'):
            ins.register = entry.getAttribute('r')

        if entry.hasAttribute('tttn'):
            ins.tttn = entry.getAttribute('tttn')

        if entry.hasAttribute('sign-ext'):
            ins.sign_ext = entry.getAttribute('sign-ext')

        if entry.hasAttribute('mode'):
            ins.run_mode = entry.getAttribute('mode')

        if entry.hasAttribute('ring'):
            ins.ring = entry.getAttribute('ring')

        if syntax.hasAttribute('mod'):
            ins.mod = syntax.getAttribute('mod')
        elif entry.hasAttribute('mod'):
            ins.mod = entry.getAttribute('mod')
        # Skip Intel-64 instructions
        if entry.hasAttribute('mode') and entry.getAttribute('mode') == 'e':
            print("Skip 64bit for now", po)
            return

        # Skip prefix code
        if entry.getElementsByTagName('grp1') and entry.getElementsByTagName('grp1')[0].childNodes[0].data == 'prefix':
            print("Parsing prefix code %02X" % po)
            ParsePrefix(entry, po, flag)
            return

        if entry.hasAttribute('instr_ext'):
            instr_ext = entry.getAttribute('instr_ext')
            if instr_ext in not_support_ext:
                return

        if entry.hasAttribute('doc'):
            return

        if entry.getElementsByTagName('proc_start'):
            proc_start = entry.getElementsByTagName('proc_start')[0].childNodes[0].data
            if proc_start == '99':
                print('Skip IA64 instruction', po)
                return

        is_undoc = False
        if entry.hasAttribute('is_undoc'):
            is_undoc = (entry.getAttribute('is_undoc') == 'yes')
        elif entry.hasAttribute('is_doc'):
            is_undoc = (entry.getAttribute('is_doc') != 'yes')
        if is_undoc:
            return

        InsertInstruction(ins)


def WalkInstructionNode(node, flag):
    ops = node.getElementsByTagName('pri_opcd')
    for op in ops:
        po = int(op.getAttribute('value'), base=16)
        if po >= 0xd8 and po < 0xe0:
            continue

        entries = op.getElementsByTagName('entry')
        for entry in entries:
            ParseEntry(entry, po, flag)


DOMTree = xml.dom.minidom.parse(infile)
x86ref = DOMTree.documentElement

one_byte = x86ref.getElementsByTagName('one-byte')[0]
WalkInstructionNode(one_byte, None)

two_byte = x86ref.getElementsByTagName('two-byte')[0]
WalkInstructionNode(two_byte, 0x0f)
