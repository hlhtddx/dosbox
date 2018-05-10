#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

from optparse import OptionParser
from x86reference import InstructionSet
import copy
import sys
import logging


address_size_specifiers = ('w', 'd')
operand_size_specifiers = ('w', 'd')


def switch_size_specifiers(c):
    return 'd' if c == 'w' else 'd'


class State:
    def __init__(self, addr_size_spec, oper_size_spec, terminate=False):
        self.addr_size_spec = addr_size_spec
        self.oper_size_spec = oper_size_spec
        self.opcodes = []
        self.state_map = StateTransitionMap()
        self.terminate = terminate
        self.handler = None

    @property
    def key(self):
        return tuple([self.addr_size_spec, self.oper_size_spec] + self.opcodes)


class StateTransition:
    def __init__(self, src_state, dst_state, trigger):
        self.src_state = src_state
        self.dst_state = dst_state
        self.trigger = trigger


class Handler:
    def __init__(self, pr_name):
        self.pr_name = pr_name
        self.description = ''

    def __str__(self):
        return self.unique_name

    @property
    def unique_name(self):
        pass

    def generate_definition(self, output):
        pass


class PrefixHandler(Handler):
    def __init__(self, opcode):
        super(Handler, self).__init__('prx')
        self.opcode = opcode

    @property
    def unique_name(self):
        pass

    def generate_definition(self, output):
        pass


class InstrHandler(Handler):
    def __init__(self, instruction):
        super(Handler, self).__init__('ins')
        self.instruction = instruction
        self.op_fmts = [opt_fmt.address for opt_fmt in instruction.op_fmts.operands]

    @property
    def unique_name(self):
        name = self.instruction.mnemonic
        for op_fmt in self.op_fmts:
            name += '_%s' % op_fmt
        return name

    def generate_definition(self, output):
        # Output definition
        output.write('''
            template<typename addr_size, typename oper_size> OpState {}(Bit8u last, PhysPt &cseip) {{
'''.format(self.unique_name))
        # Output body


        # Output foot
        output.write('''
            }
''')


class StateTransitionMap:
    """The state map with 256 elements indicates next state"""
    def __init__(self):
        self.link = [None] * 256


class StateTransitionGraph:
    """Contains all states and transitions between states"""
    mandatory_prefixes = [0x66, 0xf2, 0xf3]

    def __init__(self):
        self.state_map = {}
        self.transition_set = set()

        # initialize the init states
        self.init_states = []
        for addr_size in address_size_specifiers:
            for oper_size in operand_size_specifiers:
                state = State(addr_size, oper_size)
                self.init_states.append(state)
                self.state_map[state.key] = state

        # initialize states for mandatory prefixes
        for addr_size in address_size_specifiers:
            for oper_size in operand_size_specifiers:
                for prefix in StateTransitionGraph.mandatory_prefixes:
                    state = State(addr_size, oper_size)
                    state.opcodes.append(prefix)
                    self.state_map[state.key] = state

    def parse_prefixes(self, prefixes):
        for (key, state) in self.state_map.items():
            addr_size_spec = key[0]
            oper_size_spec = key[1]

            for prefix in prefixes:
                transition = None

                if prefix in [0x26, 0x2e, 0x36, 0x3e, 0x64, 0x65]:
                    # Segment register override prefix
                    # Add handlers
                    new_state = self.state_map[(addr_size_spec, oper_size_spec)]
                    new_state.handler = PrefixHandler(prefix)
                    new_state.handler.description = 'Segment override prefix'
                    transition = StateTransition(state, new_state, prefix)

                elif prefix == 0xf0:
                    # Lock prefix
                    # Add handlers
                    new_state = self.state_map[(addr_size_spec, oper_size_spec)]
                    new_state.handler = PrefixHandler(prefix)
                    new_state.handler.description = 'Lock prefix'
                    transition = StateTransition(state, new_state, prefix)

                elif prefix in [0xf2, 0xf3]:
                    # Maybe Mandatory prefix or REP/REPZ/REPNZ prefix
                    # Add MP states and handlers
                    new_state = self.state_map[(addr_size_spec, oper_size_spec, prefix)]
                    new_state.handler = PrefixHandler(prefix)
                    new_state.handler.description = 'REP/REPZ/REPNZ prefix'
                    transition = StateTransition(state, new_state, prefix)

                elif prefix == 0x66:
                    # Operand-size override prefix
                    # Add MP states
                    oper_size_spec = switch_size_specifiers(oper_size_spec)
                    new_state = self.state_map[(addr_size_spec, oper_size_spec, prefix)]
                    transition = StateTransition(state, new_state, prefix)

                elif prefix == 0x67:
                    # Address-size override prefix
                    # Add MP states
                    addr_size_spec = switch_size_specifiers(addr_size_spec)
                    new_state = self.state_map[(addr_size_spec, oper_size_spec)]
                    transition = StateTransition(state, new_state, prefix)

                if transition:
                    self.transition_set.add(transition)

    def __parse_instruction_with_size(self, instruction, address_size, operand_size):
        logging.debug('Insert instruction(addr_size=%s opsize=%s : %s' % (address_size, operand_size, instruction))
        prefix = instruction.prefix
        opcd_ext = instruction.opcd_ext
        opcode_len = len(instruction.opcodes)

        if instruction.opcodes[0] == 0x0f:
            if opcode_len == 1:
                logging.error("Malformat 0F with 1 byte")
                return

            if instruction.opcodes[1] == 0x38 or instruction.opcodes[1] == 0x3a:
                if opcode_len > 3:
                    opcd_ext = -1
            else:
                if opcode_len > 2:
                    opcd_ext = -1

        opcd_ext_type = 0  # Both mem/nomem
        if instruction.mod == 'mem':
            opcd_ext_type = 1  # mem
        elif instruction.operand_fmts and instruction.operand_fmts[0].address == 'M':
            opcd_ext_type = 1  # mem
        elif instruction.mod == 'nomem':
            opcd_ext_type = 2  # nomem

        if opcd_ext >= 0:
            op_index = opcd_ext << 3
            op_path = instruction.opcodes
        else:
            op_index = instruction.opcodes[-1]
            op_path = instruction.opcodes[:-1]

        init_state_key = (address_size, operand_size) if prefix == -1 else (address_size, operand_size, prefix)

        state = self.state_map[init_state_key]
        opcodes = copy.copy(init_state_key)

        # Create non-terminal states and transition
        for opcode in op_path:
            opcodes.append(opcode)
            # Skip states already in map
            if tuple(opcodes) in self.state_map:
                assert (not self.state_map[new_state.key].terminate)
                continue

            new_state = State(address_size, operand_size)
            new_state.opcodes = opcodes
            self.state_map[new_state.key] = new_state
            transition = StateTransition(state, new_state, opcode)
            self.transition_set.add(transition)
            state = new_state

        if instruction.op_fmts.operands[0] == ('reg', 'reg', None):
            logging.info('Extract Z registers')
            new_inses = instruction.extract_z_register()
            for newins in new_inses:
                sys.stdout.write('Insert newins: %s' % newins)
                InsertInstructionToTable(node, newins.opcodes[-1], newins)

        elif opcd_ext >= 0:
            # MEM
            if opcd_ext_type == 0 or opcd_ext_type == 1:
                for row in address_mode_mem_only:
                    for rm in range(8):
                        real_op_index = row | op_index | rm
                        print("real_op_index(%02x, %02x, %02x, %02x)" % (real_op_index, row, op_index, rm))
                        InsertInstructionToTable(node, real_op_index, instruction)

            # Not MEM
            if opcd_ext_type == 0 or opcd_ext_type == 2:
                for row in address_mode_reg_only:
                    for rm in range(8):
                        real_op_index = row | op_index | rm
                        print("real_op_index(%02x, %02x, %02x, %02x)" % (real_op_index, row, op_index, rm))
                        InsertInstructionToTable(node, real_op_index, instruction)

        else:
            InsertInstructionToTable(node, op_index, instruction)



    def __parse_instruction(self, instruction):

        for addr_size in address_size_specifiers:
            for oper_size in operand_size_specifiers:
                self.__parse_instruction_with_size(instruction, addr_size, oper_size)


    def parse_instructions(self, instructions):
        for instruction in instructions:
            self.__parse_instruction(instruction)

    def write(self, outfile):
        pass


def InsertInstructionToTable(table, index, ins):
    instr = ins.unique_name
    if instr in instr_map and ins != instr_map[instr] and not ins.alias:
        print("Duplicated instructions\n")
        print(ins, '\n', instr_map[instr])
        raise EnvironmentError()
    instr_map[instr] = ins

    node = table.link[index]
    if node:
        if isinstance(node, Instruction):
            if ins.mnemonic == node.mnemonic + 'd':
                print('same instruction. skip it')
        elif isinstance(node, StateTransitionMap):
            print('List is replaced')
            state_map.pop(('byte', 'word'), (node.base))
            table.link[index] = ins
        else:
            print('replaced')
            table.link[index] = ins
        return

    print('inserted')
    table.link[index] = ins


def InsertInstruction(ins):
    sys.stdout.write('Insert ins: %s' % ins)

    # Check for opcode length
    opcd_ext = ins.opcd_ext
    pure_opcodes = tuple(ins.opcodes[1:] if ins.prefix else ins.opcodes)
    pure_opc_len = len(pure_opcodes)
    if pure_opcodes[0] == 0x0f:
        if pure_opc_len == 1:
            print("Malformat 0F with 1 byte")
            return

        if pure_opcodes[1] == 0x38 or pure_opcodes[1] == 0x3a:
            if pure_opc_len > 3:
                opcd_ext = -1
        else:
            if pure_opc_len > 2:
                opcd_ext = -1

    print("opcd_ext")
    # Check opcode extension type, mem/nomem/both
    opcd_ext_type = 0  # Both mem/nomem
    if ins.mod == 'mem':
        opcd_ext_type = 1  # mem
    elif ins.operand_fmts and ins.operand_fmts[0].address == 'M':
        opcd_ext_type = 1  # mem
    elif ins.mod == 'nomem':
        opcd_ext_type = 2  # nomem

    if opcd_ext >= 0:
        op_index = opcd_ext << 3
        op_path = ins.opcodes
    else:
        op_index = ins.opcodes[-1]
        op_path = ins.opcodes[:-1]

    print("opcd_ext=", opcd_ext)
    print("op_path=", op_path)
    print("op_index=", op_index)

    if op_index == 0xc2:
        pass

    node = root_node
    opcodes = []
    for opcode in op_path:
        opcodes.append(opcode)
        item = node.link[opcode]
        if isinstance(item, Instruction) or item == None:
            new_node = StateTransitionMap(item)
            if not item:
                new_node.base = tuple(opcodes)
            node.link[opcode] = new_node
            state_map[(operand_size_specifiers[0], address_size_specifiers[0]), new_node.base] = new_node
            item = new_node
        elif isinstance(item, InstrPrefix):
            raise TypeError()
        node = item

    if ins.operand_fmts and ins.operand_fmts[0].address == 'Z':
        sys.stdout.write(' extract\n')
        new_inses = ins.extract_z_register()
        for newins in new_inses:
            sys.stdout.write('Insert newins: %s' % newins)
            InsertInstructionToTable(node, newins.opcodes[-1], newins)

    elif opcd_ext >= 0:
        # MEM
        if opcd_ext_type == 0 or opcd_ext_type == 1:
            for row in address_mode_mem_only:
                for rm in range(8):
                    real_op_index = row | op_index | rm
                    print("real_op_index(%02x, %02x, %02x, %02x)" % (real_op_index, row, op_index, rm))
                    InsertInstructionToTable(node, real_op_index, ins)

        # Not MEM
        if opcd_ext_type == 0 or opcd_ext_type == 2:
            for row in address_mode_reg_only:
                for rm in range(8):
                    real_op_index = row | op_index | rm
                    print("real_op_index(%02x, %02x, %02x, %02x)" % (real_op_index, row, op_index, rm))
                    InsertInstructionToTable(node, real_op_index, ins)

    else:
        InsertInstructionToTable(node, op_index, ins)


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


for oper_size in operand_size_specifiers:
    for addr_size in address_size_specifiers:
        root_node = StateTransitionMap(None)
        state_map[((oper_size, addr_size),())] = root_node


def WriteStatesDeclaration(output):
    output.write('enum OpState {\n')
    for key in sorted(state_map.keys()):
        output.write('\tST_%s_%s%s,\n' % (key[0][0], key[0][1], OpcodeToPath(key[1])))

    for key in sorted(option_prefixes):
        item = prefix_map[key]
        output.write('\tPR_%s,\n' % item.unique_name)

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
        output.write('static const OpState table_%s_%s_%s[];\n' % (key[0][0], key[0][1],OpcodeToPath(key[1])))
    output.write('static const OpState* const TableState[];\n')


def WriteTransitStatesDefinition(output):
    keys = sorted(state_map.keys())

    for key in keys:
        WriteTable(output, key, state_map[key])

    output.write('\nconst OpState* const %s::TableState[] = {\n' % class_name)
    for key in keys:
        output.write('\t%s::table_%s_%s%s,\n' % (class_name, key[0][0], key[0][1],OpcodeToPath(key[1])))
    for key in option_prefixes:
        output.write('\t%s::table_%s_%s%s,\n' % (class_name, operand_size_specifiers[0], address_size_specifiers[0], OpcodeToPath(keys[0][1])))
    output.write('};\n')


def WriteTable(output, opcodes, node):
    path = OpcodeToPath(opcodes[1])
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
            elif isinstance(item, StateTransitionMap):
                output.write('ST%s, ' % OpcodeToPath(item.base))
            elif isinstance(item, InstrPrefix):
                output.write('PR_%s, ' % item.unique_name)
            else:
                output.write('I_%s, ' % item.unique_name)
    output.write('\n};\n')


def WritePrefixHandlersDeclaration(output):
    for key in sorted(prefix_map.keys()):
        prefix = prefix_map[key].unique_name
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
        prefix = prefix_map[key].unique_name
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
    output.write('''#ifndef PROJECT_CORE_LLVM_H
#define PROJECT_CORE_LLVM_H
#include "core_llvm_common.h"
''')


def WriteFooter(output):
    output.write('''
#endif //PROJECT_CORE_LLVM_H
''')


def parse_options():
    parser = OptionParser()
    parser.add_option("-i", "--infile", dest="infile",
                      help="Read XML from FILE", metavar="FILE")
    parser.add_option("-o", "--outfile", dest="outfile",
                      help="Write runner header to FILE", metavar="FILE")
    parser.add_option("-q", "--quiet",
                      action="store_false", dest="verbose", default=True,
                      help="don't print status messages to stdout")

    return parser.parse_args()


def main():
    (options, args) = parse_options()

    if options.infile:
        infile = open(options.infile, 'r')
    else:
        infile = sys.stdin

    if options.outfile:
        outfile = open(options.outfile, 'w')
    else:
        outfile = sys.stderr

    instructions = InstructionSet()
    instructions.parse_file(infile)
    infile.close()

    states = StateTransitionGraph()
    states.parse_instructions(instructions)
    states.write(outfile)

    PreprocessPrefixes()
    WriteImports(outfile)
    WriteDeclaration(outfile)
    WriteDefinition(outfile)
    WriteFooter(outfile)
    print('Done')


if __name__ == '__main__':
    main()

