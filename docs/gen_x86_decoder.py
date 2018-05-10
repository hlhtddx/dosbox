#!/bin/bin/python
# -*- coding: UTF-8 -*-

from xml.dom.minidom import parse
import xml.dom.minidom
import copy
import sys

address_methods = [
    # Mod R/M
    [
        "C",	#The reg field of the ModR/M byte selects a control register (only MOV (0F20, 0F22)).
        "D",	#The reg field of the ModR/M byte selects a debug register (only MOV (0F21, 0F23)).
        "E",	#A ModR/M byte follows the opcode and specifies the operand. The operand is either a general-purpose register or a memory address. If it is a memory address, the address is computed from a segment register and any of the following values: a base register, an index register, a scaling factor, or a displacement.
        "ES",	#(Implies original E). A ModR/M byte follows the opcode and specifies the operand. The operand is either a x87 FPU stack register or a memory address. If it is a memory address, the address is computed from a segment register and any of the following values: a base register, an index register, a scaling factor, or a displacement.
        "EST",	#(Implies original E). A ModR/M byte follows the opcode and specifies the x87FPU stack register.
        "G",	#The reg field of the ModR/M byte selects a general register (for example, AX (000)).
        "H",	#The r/m field of the ModR/M byte always selects a general register, regardless of the mod field (for example, MOV (0F20)).
        "M",	#The ModR/M byte may refer only to memory: mod != 11bin (BOUND, LEA,CALLF, JMPF, LES, LDS, LSS, LFS, LGS, CMPXCHG8B, CMPXCHG16B,F20FF0 LDDQU).
        "N",	#The R/M field of the ModR/M byte selects a packed quadword MMXtechnology register.
        "P",	#The reg field of the ModR/M byte selects a packed quadword MMXtechnology register.
        "Q",	#A ModR/M byte follows the opcode and specifies the operand. The operand is either an MMX technology register or a memory address. If it is a memory address, the address is computed from a segment register and any of the following values: a base register, an index register, a scaling factor, and a displacement.
        "R",	#The mod field of the ModR/M byte may refer only to a general register (onlyMOV (0F20-0F24, 0F26)).
        "S",	#The reg field of the ModR/M byte selects a segment register (only MOV (8C,8E)).
        "T",	#The reg field of the ModR/M byte selects a test register (only MOV (0F24,0F26)).
        "U",	#The R/M field of the ModR/M byte selects a 128-bit XMM register.
        "V",	#The reg field of the ModR/M byte selects a 128-bit XMM register.
        "W",	#A ModR/M byte follows the opcode and specifies the operand. The operand is either a 128-bit XMM register or a memory address. If it is a memory address, the address is computed from a segment register and any of the following values: a base register, an index register, a scaling factor, and a displacement
    ],
    # Register
    [
        "F",	#rFLAGS register.
        "SC",	#Stack operand, used by instructions which either push an operand to the stack or pop an operand from the stack. Pop-like instructions are, for example, POP, RET, IRET, LEAVE. Push-like are, for example, PUSH, CALL, INT. No Operand type is provided along with this method because it depends on source/destination operand(s).
    ],
    # Memory
    [
        "A",	#Direct address. The instruction has no ModR/M byte; the address of the operand is encoded in the instruction; no base register, index register, or scaling factor can be applied (for example, far JMP (EA)).
        "BA",	#Memory addressed by DS:EAX, or by rAX in 64-bit mode (only0F01C8 MONITOR).
        "BB",	#Memory addressed by DS:eBX+AL, or by rBX+AL in 64-bit mode (only XLAT). (This code changed from single B in revision 1.00)
        "BD",	#Memory addressed by DS:eDI or by RDI (only 0FF7 MASKMOVQ and660FF7 MASKMOVDQU) (This code changed from YD (introduced in 1.00) in revision 1.02)
        "X",	#Memory addressed by the DS:eSI or by RSI (only MOVS, CMPS, OUTS, andLODS). In 64-bit mode, only 64-bit (RSI) and 32-bit (ESI) address sizes are supported. In non-64-bit modes, only 32-bit (ESI) and 16-bit (SI) address sizes are supported.
        "Y",	#Memory addressed by the ES:eDI or by RDI (only MOVS, CMPS, INS, STOS, andSCAS). In 64-bit mode, only 64-bit (RDI) and 32-bit (EDI) address sizes are supported. In non-64-bit modes, only 32-bit (EDI) and 16-bit (DI) address sizes are supported. The implicit ES segment register cannot be overriden by a segment prefix.
    ],
    # Immediate
    [
        "I",	#Immediate data. The operand value is encoded in subsequent bytes of the instruction.
        "J",	#The instruction contains a relative offset to be added to the instruction pointer register (for example, JMP (E9), LOOP)).
        "O",	#The instruction has no ModR/M byte; the offset of the operand is coded as a word, double word or quad word (depending on address size attribute) in the instruction. No base register, index register, or scaling factor can be applied (only MOV  (A0, A1, A2, A3)).
    ],
    # Opcode extension
    [
        "Z",	#The instruction has no ModR/M byte; the three least-significant bits of the opcode byte selects a general-purpose register
    ],
]

operand_types = [
    #fixed size
    [
        "a",	#Two one-word operands in memory or two double-word operands in memory, depending on operand-size attribute (only BOUND).
        "b",	#Byte, regardless of operand-size attribute.
        "bcd",	#Packed-BCD. Only x87 FPU instructions (for example, FBLD).
        "bs",	#Byte, sign-extended to the size of the destination operand.
        "bsq",	#(Byte, sign-extended to 64 bits.)
        "bss",	#Byte, sign-extended to the size of the stack pointer (for example, PUSH (6A)).
        "d",	#Doubleword, regardless of operand-size attribute.
        "di",	#Doubleword-integer. Only x87 FPU instructions (for example, FIADD).
        "dq",	#Double-quadword, regardless of operand-size attribute (for example, CMPXCHG16B).
        "dqp",	#Doubleword, or quadword, promoted by REX.W in 64-bit mode (for example, MOVSXD).
        "dr",	#Double-real. Only x87 FPU instructions (for example, FADD).
        "ds",	#Doubleword, sign-extended to 64 bits (for example, CALL (E8).
        "e",	#x87 FPU environment (for example, FSTENV).
        "er",	#Extended-real. Only x87 FPU instructions (for example, FLD).
        "pi",	#Quadword MMX technology data.
        "pd",	#128-bit packed double-precision floating-point data.
        "ps",	#128-bit packed single-precision floating-point data.
        "psq",	#64-bit packed single-precision floating-point data.
        "pt",	#(80-bit far pointer.)
        "q",	#Quadword, regardless of operand-size attribute (for example, CALL (FF /2)).
        "qi",	#Qword-integer. Only x87 FPU instructions (for example, FILD).
        "qp",	#Quadword, promoted by REX.W (for example, IRETQ).
        "s",	#6-byte pseudo-descriptor, or 10-byte pseudo-descriptor in 64-bit mode (for example, SGDT).
        "sd",	#Scalar element of a 128-bit packed double-precision floating data.
        "si",	#Doubleword integer register (e. g., eax). (unused even by Intel?)
        "sr",	#Single-real. Only x87 FPU instructions (for example, FADD).
        "ss",	#Scalar element of a 128-bit packed single-precision floating data.
        "st",	#x87 FPU state (for example, FSAVE).
        "stx",	#x87 FPU and SIMD state (FXSAVE and FXRSTOR).
        "t",	#10-byte far pointer.
        "w",	#Word, regardless of operand-size attribute (for example, ENTER).
        "wi",	#Word-integer. Only x87 FPU instructions (for example, FIADD).
    ],
    # variant size
    [
        "c",	#Byte or word, depending on operand-size attribute. (unused even by Intel?)
        "p",	#32-bit or 48-bit pointer, depending on operand-size attribute (for example, CALLF (9A).
        "ptp",	#32-bit or 48-bit pointer, depending on operand-size attribute, or 80-bit far pointer, promoted by REX.W in 64-bit mode (for example,CALLF (FF /3)).
        "v",	#Word or doubleword, depending on operand-size attribute (for example, INC (40), PUSH (50)).
        "vds",	#Word or doubleword, depending on operand-size attribute, or doubleword, sign-extended to 64 bits for 64-bit operand size.
        "vq",	#Quadword (default) or word if operand-size prefix is used (for example, PUSH (50)).
        "vqp",	#Word or doubleword, depending on operand-size attribute, or quadword, promoted by REX.W in 64-bit mode.
        "vs",	#Word or doubleword sign extended to the size of the stack pointer (for example, PUSH (68)).
    ]
]

class OperandFormat:
    def __init__(self, ind, address, type, group, nr):
        self.ind = ind
        self.address = address
        self.type = type
        self.group = group
        self.nr = nr

    def __str__(self):
        if self.group:
            s = '\t%s: a:%s d:%s group=%s nr=%d\n' % (self.ind, self.address, self.type, self.group, self.nr)
        else:
            s = '\t%s: a:%s d:%s\n' % (self.ind, self.address, self.type)
        return s

class Instruction:
    def __init__(self):
        self.prefix = False
        self.opcodes = []
        self.operand_fmts = []
        self.opcd_ext = -1
        self.mnemonic = ''
        self.description = ''
        self.attr = None
        self.is_doc = True
        self.doc = None
        self.direction = -1
        self.op_size = -1
        self.sign_ext = False
        self.register = ''
        self.tttn = -1
        self.mode = None
        self.ring = None

    def __str__(self):
        s = 'opcode['
        for opcode in self.opcodes:
            s += '%02X,' % opcode
        s = s[:-1]
        s += ']\n'
        if self.opcd_ext >= 0:
            s += 'opcode_ext:%x\n' % self.opcd_ext
        s += 'mnemonic:%s\n' % self.mnemonic

        s += 'operand format[\n'
        for fmt in self.operand_fmts:
            s += str(fmt)
        s += ']\n'


        if self.opcd_ext >= 0:
            s += 'opcode_ext:%x\n' % self.opcd_ext

        s += 'description:%s\n' % self.description
        s += 'attr:%s\n' % self.attr
        s += 'is_doc:%s\n' % self.is_doc
        s += 'doc:%s\n' % self.doc
        s += 'direction:%s\n' % self.direction
        s += 'op_size:%s\n' % self.op_size
        s += 'sign_ext:%s\n' % self.sign_ext
        s += 'register:%s\n' % self.register
        s += 'tttn:%s\n' % self.tttn
        s += 'mode:%s\n' % self.mode
        s += 'ring:%s\n' % self.ring
        return s

mnemonic = {}
op_types = {}

root_node = [ None ] * 256

def OutputTable(opcodes, node):
    table_name = ''
    for opcode in opcodes:
        table_name += '_%02x' % opcode

    sys.stdout.write('state table%s[] = {' % table_name)

    index = 0
    for i in range(8):
        sys.stdout.write('\n\t\\\\ %02X\n\t' % i)
        for j in range(8):
            item = node[index]
            if not item:
                sys.stdout.write('Illegal, ')
            elif isinstance(item, list):
                sys.stdout.write('state%s_%02x, ' % (table_name, index))
            else:
                sys.stdout.write('%s, ' % item.mnemonic)
            index = index + 1
    print '\n};\n'

def WalkTable(opcodes, node):
    if not isinstance(node, list):
        raise TypeError
    for index in range(len(node)):
        if isinstance(node[index], list):
            WalkTable(opcodes + [index], node[index])
    OutputTable(opcodes, node)

def InsertInstruction(ins):
    sys.stdout.write('Insert ins: %s' % ins)
    node = root_node
    if ins.opcodes == [0x0f, 0x01, 0xc8]:
        pass

    # Check for opcode length
    pure_opcodes = tuple(ins.opcodes[1:] if ins.prefix else ins.opcodes)
    pure_opc_len = len(pure_opcodes)
    if pure_opcodes[0] == 0x0f:
        if pure_opcodes[1] == 0x38 or pure_opcodes[1] == 0x3a:
            if pure_opc_len > 3:
                ins.opcd_ext = -1
        else:
            if pure_opc_len > 2:
                ins.opcd_ext = -1

    if ins.opcd_ext >= 0:
        op_index = ins.opcd_ext
        op_path = ins.opcodes
    else:
        op_index = ins.opcodes[-1]
        op_path = ins.opcodes[:-1]

    for opcode in op_path:
        if not isinstance(node[opcode], list):
            new_node = [ node[opcode] ] * 256
            node[opcode] = new_node
        node = node[opcode]

    try:
        node[op_index]
    except AttributeError as err:
        print err

    if node[op_index]:
        sys.stdout.write(' replace ')
    # if ins.operands and ins.operands[0].startswith('Z'):
    #     for i in range(8):
    #         newins = copy.copy(ins)
    #         newins.po = newins.po + i
    #         op_maps[op_category][op_index + i] = newins
    #         print 'New Instruction: ', newins
    # else:
    node[op_index] = ins
    if ins.opcd_ext >= 0:
        node[0xc0 + op_index] = ins

    print ' inserted\n'

def ParseOperandFormat(node, opt, ops):
    operands = node.getElementsByTagName(opt)
    if not operands:
        return

    for operand in operands:
        if operand.hasAttribute('displayed') and operand.getAttribute('displayed') == 'no':
            return None

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

        if operand.hasAttribute('nr'):
            nr = int(operand.getAttribute('nr'))
        else:
            nr = -1

        if operand.hasAttribute('group'):
            group = operand.getAttribute('group')
        else:
            group = None

        op_format = OperandFormat(opt, a, t, group, nr)

        if operand.hasAttribute('group'):
            op_format.group = operand.getAttribute('group')

        ops.append(op_format)

def ParseEntry(entry, po, flag):
    #Skip undocumented instructions
#    if entry.hasAttribute('doc_ref') or entry.hasAttribute('doc64_ref'):
#        return

    #Skip Intel-64 instructions
    if entry.hasAttribute('mode') and entry.getAttribute('mode') == 'e':
        return

    #Skip prefix code
    if entry.getElementsByTagName('grp1') and entry.getElementsByTagName('grp1')[0].childNodes[0].data == 'prefix':
            return

    syntax = entry.getElementsByTagName('syntax')[0]
    #Skip invalid opcode
    if not syntax.childNodes:
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
    ins.mnemonic = mnemonic.childNodes[0].data

    ParseOperandFormat(syntax, 'dst', ins.operand_fmts)
    ParseOperandFormat(syntax, 'src', ins.operand_fmts)

    note = entry.getElementsByTagName('note')[0]
    brief = note.getElementsByTagName('brief')[0]

    ins.description = brief.childNodes[0].data

    if entry.hasAttribute('direction'):
        ins.direction = int(entry.getAttribute('direction'))

    if entry.hasAttribute('op_size'):
        ins.op_size = int(entry.getAttribute('op_size'))

    if entry.hasAttribute('r'):
        ins.register = entry.getAttribute('r')

    if entry.hasAttribute('doc'):
        ins.doc = entry.getAttribute('doc')

    if entry.hasAttribute('is_undoc'):
        ins.is_doc = (entry.getAttribute('is_undoc') != 'yes')

    if entry.hasAttribute('tttn'):
        ins.tttn = entry.getAttribute('tttn')

    if entry.hasAttribute('sign-ext'):
        ins.sign_ext = entry.getAttribute('sign-ext')

    if entry.hasAttribute('mode'):
        ins.mode = entry.getAttribute('mode')

    if entry.hasAttribute('ring'):
        ins.ring = entry.getAttribute('ring')

    if ins.description == 'Pop a Value from the Stack':
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

DOMTree = xml.dom.minidom.parse('x86reference.xml')
x86ref = DOMTree.documentElement

one_byte = x86ref.getElementsByTagName('one-byte')[0]
WalkInstructionNode(one_byte, None)

two_byte = x86ref.getElementsByTagName('two-byte')[0]
WalkInstructionNode(two_byte, 0x0f)

# for op_key in sorted(op_maps.keys()):
#     print 'op_map(%s) = %d' % (op_key, len(op_maps[op_key]))

#     sys.stdout.write('xxx tbl')
#     for b in op_key:
#         sys.stdout.write('_%02x' % b)
#     sys.stdout.write('[] = {\n')

#     for

WalkTable([], root_node)

for key in sorted(op_types.keys()):
    print 'Operand =', key

print 'Done'