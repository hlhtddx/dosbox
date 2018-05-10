from xml.dom.minidom import parse
import xml.dom.minidom
import copy
import sys

class operand_format:
    def __init__(self, ind, address, type, group, nr):
        self.ind = ind
        self.address = address
        self.type = type
        self.group = group
        self.nr = nr

class instrcution:
    def __init__(self):
        self.prefix = False
        self.opcodes = []
        self.operand_formats = []
        self.opcd_ext = -1
        self.mnemonic = ''
        self.description = ''
        self.attr = None
        self.is_doc = True
        self.doc = None
#        self.doc_ref = None
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
        for fmt in self.operand_formats:
            if fmt.group:
                s += '\t%s: %s%s group=%s nr=%d\n' % (fmt.ind, fmt.address, fmt.type, fmt.group, fmt.nr)
            else:
                s += '\t%s: %s%s\n' % (fmt.ind, fmt.address, fmt.type)
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

def insert_instruction(ins):
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

def operand_type(node, opt, ops):
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

        op_format = operand_format(opt, a, t, group, nr)

        if operand.hasAttribute('group'):
            op_format.group = operand.getAttribute('group')

        ops.append(op_format)

def parse_node(entry, po, flag):
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
        ins.prefix = True
        ins.opcodes.insert(0, prefix)

    opcd_ext = entry.getElementsByTagName('opcd_ext')
    if opcd_ext:
        ins.opcd_ext = int(opcd_ext[0].childNodes[0].data)

    mnemonic = syntax.getElementsByTagName('mnem')[0]
    ins.mnemonic = mnemonic.childNodes[0].data

    operand_type(syntax, 'dst', ins.operand_formats)
    operand_type(syntax, 'src', ins.operand_formats)

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

    insert_instruction(ins)

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