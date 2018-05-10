#!/usr/bin/python
# -*- coding: UTF-8 -*-

from xml.dom.minidom import parse
import xml.dom.minidom
import copy
import sys

address_mode_mem_only = [ 0x00 << 6, 0x01 << 6, 0x02 << 6 ]
address_mode_reg_only = [ 0x03 << 6 ]
mandatory_prefixes = [ 0x66, 0xf2, 0xf3 ]
option_prefixes = []

ignore_entry = [ 'invd', 'undef', 'null' ]

gen_ext_b = [ 'AL', 'CL', 'DL', 'BL', 'AH', 'CH', 'DH', 'BH' ]
gen_ext_w = [ 'AX', 'CX', 'DX', 'BX', 'SP', 'BP', 'SI', 'DI' ]
gen_ext_d = [ 'EAX', 'ECX', 'EDX', 'EBX', 'ESP', 'EBP', 'ESI', 'EDI' ]
gen_ext_v = [ 'eAX', 'eCX', 'eDX', 'eBX', 'eSP', 'eBP', 'eSI', 'eDI' ]
seg_ext = [ 'ES', 'CS', 'SS', 'DS', 'FS', 'GS' ]

register_map = {}
register_map[('gen', 'b')] = gen_ext_b
register_map[('gen', 'w')] = gen_ext_w
register_map[('gen', 'd')] = gen_ext_d
register_map[('gen', 'v')] = gen_ext_v
register_map[('gen', 'vqp')] = gen_ext_v
register_map[('seg', 'w')] = seg_ext

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

address_methods = {
    "A" : [],#Direct address. The instruction has no ModR/M byte; the address of the operand is encoded in the instruction; no base register, index register, or scaling factor can be applied (for example, far JMP (EA)).
    "BA" : [],#Memory addressed by DS:EAX, or by rAX in 64-bit mode (only0F01C8 MONITOR).
    "BB" : [],#Memory addressed by DS:eBX+AL, or by rBX+AL in 64-bit mode (only XLAT). (This code changed from single B in revision 1.00)
    "BD" : [],#Memory addressed by DS:eDI or by RDI (only 0FF7 MASKMOVQ and660FF7 MASKMOVDQU) (This code changed from YD (introduced in 1.00) in revision 1.02)
    "C" : [],#The reg field of the ModR/M byte selects a control register (only MOV (0F20, 0F22)).
    "D" : [],#The reg field of the ModR/M byte selects a debug register (only MOV (0F21, 0F23)).
    "E" : [],#A ModR/M byte follows the opcode and specifies the operand. The operand is either a general-purpose register or a memory address. If it is a memory address, the address is computed from a segment register and any of the following values: a base register, an index register, a scaling factor, or a displacement.
    "ES" : [],#(Implies original E). A ModR/M byte follows the opcode and specifies the operand. The operand is either a x87 FPU stack register or a memory address. If it is a memory address, the address is computed from a segment register and any of the following values: a base register, an index register, a scaling factor, or a displacement.
    "EST" : [],#(Implies original E). A ModR/M byte follows the opcode and specifies the x87FPU stack register.
    "F" : [],#rFLAGS register.
    "G" : [],#The reg field of the ModR/M byte selects a general register (for example, AX (000)).
    "H" : [],#The r/m field of the ModR/M byte always selects a general register, regardless of the mod field (for example, MOV (0F20)).
    "I" : [],#Immediate data. The operand value is encoded in subsequent bytes of the instruction.
    "J" : [],#The instruction contains a relative offset to be added to the instruction pointer register (for example, JMP (E9), LOOP)).
    "M" : [],#The ModR/M byte may refer only to memory: mod != 11bin (BOUND, LEA,CALLF, JMPF, LES, LDS, LSS, LFS, LGS, CMPXCHG8B, CMPXCHG16B,F20FF0 LDDQU).
    "N" : [],#The R/M field of the ModR/M byte selects a packed quadword MMXtechnology register.
    "O" : [],#The instruction has no ModR/M byte; the offset of the operand is coded as a word, double word or quad word (depending on address size attribute) in the instruction. No base register, index register, or scaling factor can be applied (only MOV  (A0, A1, A2, A3)).
    "P" : [],#The reg field of the ModR/M byte selects a packed quadword MMXtechnology register.
    "Q" : [],#A ModR/M byte follows the opcode and specifies the operand. The operand is either an MMX technology register or a memory address. If it is a memory address, the address is computed from a segment register and any of the following values: a base register, an index register, a scaling factor, and a displacement.
    "R" : [],#The mod field of the ModR/M byte may refer only to a general register (onlyMOV (0F20-0F24, 0F26)).
    "S" : [],#The reg field of the ModR/M byte selects a segment register (only MOV (8C,8E)).
    "SC" : [],#Stack operand, used by instructions which either push an operand to the stack or pop an operand from the stack. Pop-like instructions are, for example, POP, RET, IRET, LEAVE. Push-like are, for example, PUSH, CALL, INT. No Operand type is provided along with this method because it depends on source/destination operand(s).
    "T" : [],#The reg field of the ModR/M byte selects a test register (only MOV (0F24,0F26)).
    "U" : [],#The R/M field of the ModR/M byte selects a 128-bit XMM register.
    "V" : [],#The reg field of the ModR/M byte selects a 128-bit XMM register.
    "W" : [],#A ModR/M byte follows the opcode and specifies the operand. The operand is either a 128-bit XMM register or a memory address. If it is a memory address, the address is computed from a segment register and any of the following values: a base register, an index register, a scaling factor, and a displacement
    "X" : [],#Memory addressed by the DS:eSI or by RSI (only MOVS, CMPS, OUTS, andLODS). In 64-bit mode, only 64-bit (RSI) and 32-bit (ESI) address sizes are supported. In non-64-bit modes, only 32-bit (ESI) and 16-bit (SI) address sizes are supported.
    "Y" : [],#Memory addressed by the ES:eDI or by RDI (only MOVS, CMPS, INS, STOS, andSCAS). In 64-bit mode, only 64-bit (RDI) and 32-bit (EDI) address sizes are supported. In non-64-bit modes, only 32-bit (EDI) and 16-bit (DI) address sizes are supported. The implicit ES segment register cannot be overriden by a segment prefix.
    "Z" : [],#The instruction has no ModR/M byte; the three least-significant bits of the opcode byte selects a general-purpose register
}

operand_types = {
    #fixed size byte
    "a" : [],	    #Two one-word operands in memory or two double-word operands in memory, depending on operand-size attribute (only BOUND).
    "b" : [],	    #Byte, regardless of operand-size attribute.
    "bcd" : [],	#Packed-BCD. Only x87 FPU instructions (for example, FBLD).
    "bs" : [],	#Byte, sign-extended to the size of the destination operand.
    "bsq" : [],	#(Byte, sign-extended to 64 bits.)
    "bss" : [],	#Byte, sign-extended to the size of the stack pointer (for example, PUSH (6A)).
    "d" : [],	    #Doubleword, regardless of operand-size attribute.
    "di" : [],	#Doubleword-integer. Only x87 FPU instructions (for example, FIADD).
    "dq" : [],	#Double-quadword, regardless of operand-size attribute (for example, CMPXCHG16B).
    "dqp" : [],	#Doubleword, or quadword, promoted by REX.W in 64-bit mode (for example, MOVSXD).
    "dr" : [],	#Double-real. Only x87 FPU instructions (for example, FADD).
    "ds" : [],	#Doubleword, sign-extended to 64 bits (for example, CALL (E8).
    "e" : [],	    #x87 FPU environment (for example, FSTENV).
    "er" : [],	#Extended-real. Only x87 FPU instructions (for example, FLD).
    "pi" : [],	#Quadword MMX technology data.
    "pd" : [],	#128-bit packed double-precision floating-point data.
    "ps" : [],	#128-bit packed single-precision floating-point data.
    "psq" : [],	#64-bit packed single-precision floating-point data.
    "pt" : [],	#(80-bit far pointer.)
    "q" : [],	    #Quadword, regardless of operand-size attribute (for example, CALL (FF /2)).
    "qi" : [],	#Qword-integer. Only x87 FPU instructions (for example, FILD).
    "qp" : [],	#Quadword, promoted by REX.W (for example, IRETQ).
    "s" : [],	    #6-byte pseudo-descriptor, or 10-byte pseudo-descriptor in 64-bit mode (for example, SGDT).
    "sd" : [],	#Scalar element of a 128-bit packed double-precision floating data.
    "si" : [],	#Doubleword integer register (e. g., eax). (unused even by Intel?)
    "sr" : [],	#Single-real. Only x87 FPU instructions (for example, FADD).
    "ss" : [],	#Scalar element of a 128-bit packed single-precision floating data.
    "st" : [],	#x87 FPU state (for example, FSAVE).
    "stx" : [],	#x87 FPU and SIMD state (FXSAVE and FXRSTOR).
    "t" : [],	    #10-byte far pointer.
    "w" : [],	    #Word, regardless of operand-size attribute (for example, ENTER).
    "wi" : [],	#Word-integer. Only x87 FPU instructions (for example, FIADD).
    "c" : [],	    #Byte or word, depending on operand-size attribute. (unused even by Intel?)
    "p" : [],	    #32-bit or 48-bit pointer, depending on operand-size attribute (for example, CALLF (9A).
    "ptp" : [],	#32-bit or 48-bit pointer, depending on operand-size attribute, or 80-bit far pointer, promoted by REX.W in 64-bit mode (for example,CALLF (FF /3)).
    "v" : [],	    #Word or doubleword, depending on operand-size attribute (for example, INC (40), PUSH (50)).
    "vds" : [],	#Word or doubleword, depending on operand-size attribute, or doubleword, sign-extended to 64 bits for 64-bit operand size.
    "vq" : [],	#Quadword (default) or word if operand-size prefix is used (for example, PUSH (50)).
    "vqp" : [],	#Word or doubleword, depending on operand-size attribute, or quadword, promoted by REX.W in 64-bit mode.
    "vs" : [],	#Word or doubleword sign extended to the size of the stack pointer (for example, PUSH (68)).
}

class OperandFormat:
    def __init__(self, ind, address, type, group, nr):
        self.ind = ind
        self.address = address
        self.type = type
        self.group = group
        self.nr = nr

    def __str__(self):
        return '\t%s: %s\n' % (self.ind, self.TypeName())

    def TypeName(self):
        if self.group:
            return register_map[(self.group, self.type)][self.nr]
        else:
            return self.address + self.type

class StateTransition:
    def __init__(self, base):
        self.base = tuple(base.opcodes) if base else ()
        self.link = [ base ] * 256

class InstrPrefix:
    def __init__(self, opcode):
        self.opcode = opcode
        self.mnemonic = ''

    def __str__(self):
        return 'Prefix(%02X)' % self.opcode

    def UniqueName(self):
        return '%02x' % self.opcode

class Instruction:
    def __init__(self):
        self.prefix = False
        self.opcodes = []
        self.operand_fmts = []
        self.opcd_ext = -1
        self.mnemonic = ''
        self.alias = None
        self.description = ''
        self.attr = None
        self.instr_ext = None
        self.is_doc = True
        self.doc = None
        self.direction = -1
        self.op_size = -1
        self.sign_ext = False
        self.register = ''
        self.tttn = -1
        self.mode = None
        self.mod = None
        self.ring = None

    def __str__(self):
        s = 'opcode['
        for opcode in self.opcodes:
            s += '%02X,' % opcode
        s = s[:-1]
        s += ']\n'
        if self.opcd_ext >= 0:
            s += 'opcode_ext:%x\n' % self.opcd_ext
        s += 'unique name:%s\n' % self.UniqueName()

        s += 'operand format[\n'
        for fmt in self.operand_fmts:
            s += str(fmt)
        s += ']\n'

        if self.mod:
            s += 'mod:%s\n' % self.mod

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

    def UniqueName(self):
        name = self.mnemonic

        if self.attr:
            name += '_%s' % self.attr

        for fmt in self.operand_fmts:
            name += '_%s' % fmt.TypeName()
        return name

    def ExtractRegZ(self):
        new_inses = []
        for i in range(8):
            new_ins = copy.deepcopy(self)
            new_ins.opcodes[-1] += i
            new_ins.operand_fmts[0].address = None
            new_ins.operand_fmts[0].group = 'gen'
            new_ins.operand_fmts[0].nr = i
            new_inses.append(new_ins)
        return new_inses

state_map = {}
instr_map = {}
prefix_map = {}

def InsertInstructionToTable(table, index, ins):
    instr = ins.UniqueName()
    if instr_map.has_key(instr) and ins != instr_map[instr] and not ins.alias:
        print ins, instr_map[instr]
        raise EnvironmentError()
    instr_map[instr] = ins

    node = table.link[index]
    if node:
        if isinstance(node, Instruction):
            if ins.mnemonic == node.mnemonic + 'd':
                print 'same instruction. skip it'
        elif isinstance(node, StateTransition):
            print 'List is replaced'
            state_map.pop(node.base)
            table.link[index] = ins
        else:
            print 'replaced'
            table.link[index] = ins
        return

    print 'inserted'
    table.link[index] = ins


def InsertInstruction(ins):
    sys.stdout.write('Insert ins: %s' % ins)

    # Check for opcode length
    opcd_ext = ins.opcd_ext
    pure_opcodes = tuple(ins.opcodes[1:] if ins.prefix else ins.opcodes)
    pure_opc_len = len(pure_opcodes)
    if pure_opcodes[0] == 0x0f:
        if pure_opc_len == 1:
            print "Malformat 0F with 1 byte"
            return

        if pure_opcodes[1] == 0x38 or pure_opcodes[1] == 0x3a:
            if pure_opc_len > 3:
                opcd_ext = -1
        else:
            if pure_opc_len > 2:
                opcd_ext = -1

    print "opcd_ext"
    # Check opcode extension type, mem/nomem/both
    opcd_ext_type = 0 # Both mem/nomem
    if ins.mod == 'mem':
        opcd_ext_type = 1 # mem
    elif ins.operand_fmts and ins.operand_fmts[0].address == 'M':
        opcd_ext_type = 1 # mem
    elif ins.mod == 'nomem':
        opcd_ext_type = 2 # nomem

    if opcd_ext >= 0:
        op_index = opcd_ext << 3
        op_path = ins.opcodes
    else:
        op_index = ins.opcodes[-1]
        op_path = ins.opcodes[:-1]

    print "opcd_ext=", opcd_ext
    print "op_path=", op_path
    print "op_index=", op_index

    if op_index == 0xc2:
        pass

    node = root_node
    opcodes = []
    for opcode in op_path:
        opcodes.append(opcode)
        item = node.link[opcode]
        if isinstance(item, Instruction) or item == None:
            new_node = StateTransition(item)
            if not item:
                new_node.base = tuple(opcodes)
            node.link[opcode] = new_node
            state_map[new_node.base] = new_node
            item = new_node
        elif isinstance(item, InstrPrefix):
            raise TypeError()
        node = item

    if ins.operand_fmts and ins.operand_fmts[0].address == 'Z':
        sys.stdout.write(' extract\n')
        new_inses = ins.ExtractRegZ()
        for newins in new_inses:
            sys.stdout.write('Insert newins: %s' % newins)
            InsertInstructionToTable(node, newins.opcodes[-1], newins)

    elif opcd_ext >= 0:
        # MEM
        if opcd_ext_type == 0 or opcd_ext_type == 1:
            for row in address_mode_mem_only:
                for rm in range(8):
                    real_op_index = row | op_index | rm
                    print "real_op_index(%02x, %02x, %02x, %02x)" % (real_op_index, row, op_index, rm)
                    InsertInstructionToTable(node, real_op_index, ins)

        #Not MEM
        if opcd_ext_type == 0 or opcd_ext_type == 2:
            for row in address_mode_reg_only:
                for rm in range(8):
                    real_op_index = row | op_index | rm
                    print "real_op_index(%02x, %02x, %02x, %02x)" % (real_op_index, row, op_index, rm)
                    InsertInstructionToTable(node, real_op_index, ins)

    else:
        InsertInstructionToTable(node, op_index, ins)

def ParseOperandFormat(node, opt, ops):
    operands = node.getElementsByTagName(opt)
    if not operands:
        return

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

        if operand.hasAttribute('group'):
            op_format.group = operand.getAttribute('group')

        ops.append(op_format)

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
        print "More than 1 syntax"

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
    #Skip Intel-64 instructions
    if entry.hasAttribute('mode') and entry.getAttribute('mode') == 'e':
        print "Skip 64bit for now", po
        return

    #Skip prefix code
    if entry.getElementsByTagName('grp1') and entry.getElementsByTagName('grp1')[0].childNodes[0].data == 'prefix':
        print "Parsing prefix code %02X" % po
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
            print 'Skip IA64 instruction', po
            return

    is_undoc = False
    if entry.hasAttribute('is_undoc'):
        is_undoc = (entry.getAttribute('is_undoc') == 'yes')
    elif entry.hasAttribute('is_doc'):
        is_undoc = (entry.getAttribute('is_doc') != 'yes')
    if is_undoc:
        return

    syntaxes = entry.getElementsByTagName('syntax')
    if len(syntaxes) > 1:
        print "More than 1 syntax"

    syntax = syntaxes[0]
    if syntax:
        #Skip invalid opcode
        if not syntax.childNodes:
            print "syntax no body", po
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

        ParseOperandFormat(syntax, 'dst', ins.operand_fmts)
        ParseOperandFormat(syntax, 'src', ins.operand_fmts)

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
            ins.mode = entry.getAttribute('mode')

        if entry.hasAttribute('ring'):
            ins.ring = entry.getAttribute('ring')

        if syntax.hasAttribute('mod'):
            ins.mod = syntax.getAttribute('mod')
        elif entry.hasAttribute('mod'):
            ins.mod = entry.getAttribute('mod')

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

def PreprocessPrefixes():
    for prefix in mandatory_prefixes:
        table = root_node.link[prefix]
        for index in range(len(table.link)):
            if index == prefix:
                continue
            if not table.link[index]:
                table.link[index] = root_node.link[index]

def OpcodeToPath(opcodes):
    path = ''
    for opcode in opcodes:
        path += '_%02x' % opcode
    return path

root_node = StateTransition( None )
state_map[()] = root_node

def WriteStatesDeclaration(output):
    output.write('\nenum OpState {\n')
    for key in sorted(state_map.keys()):
        output.write('\tST%s,\n' % OpcodeToPath(key))

    for key in sorted(option_prefixes):
        item = prefix_map[key]
        output.write('\tPR_%s,\n' % item.UniqueName())

    state_count = len(state_map) + len(prefix_map)
    instr_base = 0x1000
    while instr_base <= state_count:
        instr_base <<= 1

    output.write('\tI_ILLEGAL = 0x%x,\n' % instr_base)
    for key in sorted(instr_map.keys()):
        output.write('\tI_%s,\n' % key)

    output.write('};\n')

def WriteTransitStatesDeclaration(output):
    keys = sorted(state_map.keys())
    for key in keys:
        output.write('static const OpState table%s[];\n' % OpcodeToPath(key))
    output.write('static const OpState* const TableState[];\n')

def WriteTransitStatesDefinition(output):
    keys = sorted(state_map.keys())

    for key in keys:
        WriteTable(output, key, state_map[key])

    output.write('\nconst OpState* const %s::TableState[] = {\n' % class_name)
    for key in keys:
        output.write('\t%s::table%s,\n' % (class_name, OpcodeToPath(key)))
    for key in option_prefixes:
        output.write('\t%s::table%s,\n' % (class_name, OpcodeToPath(keys[0])))
    output.write('};\n')

def WriteTable(output, opcodes, node):
    path = OpcodeToPath(opcodes)
    output.write('const OpState %s::table%s[] = {' % (class_name, path))

    cols = 8

    for i in range(256 / cols):
        idx_row = i * cols
        output.write('\n\t// %02X\n\t' % idx_row)
        for j in range(cols):
            index = idx_row | j
            item = node.link[index]
            if not item:
                output.write('I_ILLEGAL, ')
            elif isinstance(item, StateTransition):
                output.write('ST%s, ' % OpcodeToPath(item.base))
            elif isinstance(item, InstrPrefix):
                output.write('PR_%s, ' % item.UniqueName())
            else:
                output.write('I_%s, ' % item.UniqueName())
    output.write('\n};\n')

def WritePrefixHandlersDeclaration(output):
    for key in sorted(prefix_map.keys()):
        prefix = prefix_map[key].UniqueName()
        output.write('''
static inline void Handle_Prefix_%s(OpState& state) {
};
''' % (prefix))

def WriteHandlersDeclaration(output):
    for key in sorted(instr_map.keys()):
        ins = instr_map[key]
        output.write('\n\n')
        output.write('/* %s:%s %s */\n' % (OpcodeToPath(ins.opcodes), ins.mnemonic, ins.description))
        output.write('inline void Handle_%s(Bit8u last, PhysPt &cseip) {\n' % key)
        output.write('};\n')

def WriteParseDeclaration(output):
    output.write('bool Parse(PhysPt &cseip);\n')

def WriteParseFuncBody(output):
    output.write('''
bool %s::Parse(PhysPt &cseip) {
    OpState state = ST;
    Bit8u insb = 0;
    while(state < I_ILLEGAL) {
        insb = Fetchb(cseip);
	    const OpState* table = TableState[ST];
        state = table[insb];

        switch(state) {
''' % class_name)

    for key in sorted(option_prefixes):
        prefix = prefix_map[key].UniqueName()
        output.write('''
        case PR_%s:
            Handle_Prefix_%s(state);
            break;
''' % (prefix, prefix))

    output.write('''
        default:
            break;
        }
    }
    switch(state) {
''')
    for key in sorted(instr_map):
        output.write('''
    case I_%s:
        Handle_%s(insb, cseip);
        break;
''' % (key, key))

    output.write('''
    default:
        break;
    }
}
''')

class_name = 'CpuRunnerX86'

def WriteDeclaration(output):
    WriteStatesDeclaration(output)
    output.write('class %s {\n' % class_name)
    output.write('private:\n')
    WriteTransitStatesDeclaration(output)
    WriteHandlersDeclaration(output)
    WritePrefixHandlersDeclaration(output)
    output.write('public:\n')
    WriteParseDeclaration(output)
    output.write('};\n')

def WriteDefinition(output):
    WriteTransitStatesDefinition(output)
    WriteParseFuncBody(output)

def WriteImports(output):
    output.write('''
    #ifndef PROJECT_CORE_LLVM_PARSE_H
    #define PROJECT_CORE_LLVM_PARSE_H
    #include "cpu.h"

    #if (!C_CORE_INLINE)
    #define LoadMb(off)        	mem_readb(off)
    #define LoadMw(off)        	mem_readw(off)
    #define LoadMd(off)        	mem_readd(off)
    #define SaveMb(off, val)	mem_writeb(off,val)
    #define SaveMw(off, val)	mem_writew(off,val)
    #define SaveMd(off, val)	mem_writed(off,val)
    #else
    #include "paging.h"
    #define LoadMb(off) 		mem_readb_inline(off)
    #define LoadMw(off) 		mem_readw_inline(off)
    #define LoadMd(off) 		mem_readd_inline(off)
    #define SaveMb(off, val)	mem_writeb_inline(off,val)
    #define SaveMw(off, val)	mem_writew_inline(off,val)
    #define SaveMd(off, val)	mem_writed_inline(off,val)
    #endif

    static inline Bit8u Fetchb(PhysPt cseip) {
    	Bit8u temp = LoadMb(cseip);
    	cseip += 1;
    	return temp;
    }

    static inline Bit16u Fetchw(PhysPt cseip) {
    	Bit16u temp = LoadMw(cseip);
    	cseip += 2;
    	return temp;
    }

    static inline Bit32u Fetchd(PhysPt cseip) {
    	Bit32u temp = LoadMd(cseip);
    	cseip += 4;
    	return temp;
    }

    static struct {
    	Bitu opcode_index;
    	PhysPt cseip;
    	PhysPt base_ds, base_ss;
    	SegNames base_val_ds;
    	bool rep_zero;
    	Bitu prefixes;
    } core;
    ''')

def WriteFooter(output):
    output.write('''
    #endif //PROJECT_CORE_LLVM_PARSE_H
    ''')

def main():
    DOMTree = xml.dom.minidom.parse('x86reference.xml')
    x86ref = DOMTree.documentElement

    one_byte = x86ref.getElementsByTagName('one-byte')[0]
    WalkInstructionNode(one_byte, None)

    two_byte = x86ref.getElementsByTagName('two-byte')[0]
    WalkInstructionNode(two_byte, 0x0f)

    if len(sys.argv) > 1:
        filename = sys.argv[1]
        output = open(filename, 'w+')
    else:
        output = sys.stdout

    PreprocessPrefixes()
    WriteImports(output)
    WriteDeclaration(output)
    WriteDefinition(output)
    WriteFooter(output)
    print 'Done'


if __name__ == '__main__':
    main()