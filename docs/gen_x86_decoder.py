from xml.dom.minidom import parse
import xml.dom.minidom
import copy
import sys

class instrcution:
    def __init__(self):
        self.opcodes = []
        self.operand_formats = []
        self.mnemonic = ''
        self.description = ''
        self.op_ext = -1

    def __str__(self):
        s = 'opcode['
        for opcode in self.opcodes:
            s += '%02x, ' % opcode
        s += ']'
        if self.op_ext >= 0:
            s += ' opcode_ext:%x' % self.op_ext
        s += ' mnemonic:%s description:%s' % (self.mnemonic, self.description)
        return s

mnemonic = {}
op_types = {}

root_node = [ None ] * 256

def output_table(opcodes, node):
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
                sys.stdout.write('state_illegal, ')
            elif isinstance(item, list):
                sys.stdout.write('state%s_%02x, ' % (table_name, index))
            else:
                sys.stdout.write('%s, ' % item.mnemonic)
            index = index + 1
    print '\n};\n'

def walk_table(opcodes, node):
    if not isinstance(node, list):
        raise TypeError
    for index in range(len(node)):
        if isinstance(node[index], list):
            walk_table(opcodes + [index], node[index])
    output_table(opcodes, node)

def insert_ins(ins):
    sys.stdout.write('Insert ins: %s' % ins)
    node = root_node
    if len(ins.opcodes) >= 3 and ins.opcodes[0] == 0x0f and ins.opcodes[1] == 0x01 and ins.opcodes[2] == 0xc8:
        pass

    if ins.op_ext >= 0:
        op_index = ins.op_ext
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
    if ins.op_ext >= 0:
        node[0xc0 + op_index] = ins
    print ' inserted\n'

def operand_type(node, opt):
    ops = []
    operands = node.getElementsByTagName(opt)
    if not operands:
        return

    for operand in operands:
        if operand.hasAttribute('displayed') and operand.getAttribute('displayed') == 'no':
            return None
        has_addr = operand.hasAttribute('address')
        has_type =operand.hasAttribute('type')

        op = None
        address = operand.getElementsByTagName('a')
        type = operand.getElementsByTagName('t')
        if address and type:
            op = '%s%s' % (address[0].childNodes[0].data, type[0].childNodes[0].data)
        elif has_addr and has_type:
            op = '%s%s' % (operand.getAttribute('address'), operand.getAttribute('type'))
        elif has_addr or has_type:
            op = operand.childNodes[0].data

        if op:
            op_types[op] = 1
            ops.append(op)

    return ops

def parse_node(entry, po, flag):
    #Skip undocumented instructions
    if entry.hasAttribute('doc_ref') or entry.hasAttribute('doc64_ref'):
        return

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
    ins = instrcution()
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
        ins.opcodes.insert(0, prefix)

    opcd_ext = entry.getElementsByTagName('opcd_ext')
    if opcd_ext:
        ins.op_ext = int(opcd_ext[0].childNodes[0].data, base=16)

    mnemonic = syntax.getElementsByTagName('mnem')[0]
    ins.mnemonic = mnemonic.childNodes[0].data

    dst = operand_type(syntax, 'dst')
    if dst:
        ins.operand_formats += dst

    src = operand_type(syntax, 'src')
    if src:
        ins.operand_formats += src

    note = entry.getElementsByTagName('note')[0]
    brief = note.getElementsByTagName('brief')[0]

    ins.description = brief.childNodes[0].data


    if ins.description == 'Pop a Value from the Stack':
        return

    insert_ins(ins)

def walk_instruction_set(node, flag):
    ops = node.getElementsByTagName('pri_opcd')
    for op in ops:
        po = int(op.getAttribute('value'), base=16)
        if po >= 0xd8 and po < 0xe0:
            continue

        entries = op.getElementsByTagName('entry')
        for entry in entries:
            parse_node(entry, po, flag)

DOMTree = xml.dom.minidom.parse('x86reference.xml')
x86ref = DOMTree.documentElement

one_byte = x86ref.getElementsByTagName('one-byte')[0]
walk_instruction_set(one_byte, None)

two_byte = x86ref.getElementsByTagName('two-byte')[0]
walk_instruction_set(two_byte, 0x0f)

# for op_key in sorted(op_maps.keys()):
#     print 'op_map(%s) = %d' % (op_key, len(op_maps[op_key]))

#     sys.stdout.write('xxx tbl')
#     for b in op_key:
#         sys.stdout.write('_%02x' % b)
#     sys.stdout.write('[] = {\n')

#     for

walk_table([], root_node)

for key in sorted(op_types.keys()):
    print 'Operand =', key

print 'Done'