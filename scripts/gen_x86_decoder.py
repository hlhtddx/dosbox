#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

from optparse import OptionParser
from x86reference import InstructionSet, InstrPrefix, X86Error
import sys
import logging


address_size_specifiers = ('w', 'd')
operand_size_specifiers = ('w', 'd')
address_size_count = len(address_size_specifiers)
operand_size_count = len(operand_size_specifiers)

address_mode_mem_only = (0x00, 0x40, 0x80)
address_mode_reg_only = (0xc0, )


def switch_size_specifiers(s):
    return 1 - s


class State:
    pr_name = 'st'
    arg_call_list = 'insb'
    arg_decl_list = 'Bit8u insb'

    def __init__(self, opcode, parent=None, description= ''):
        self.opcode = opcode
        self.parent = parent
        self.description = description
        self.state_matrix = None
        self.mod = False
        self.extensions = {}

    def __str__(self):
        return self.unique_key

    @property
    def unique_key(self):
        return f'{self.pr_name}{self.unique_name}'

    @property
    def unique_name(self):
        if self.opcode == None:
            return ''
        if not self.parent:
            return f'{self.opcode:02X}'
        return f'{self.parent.unique_name}_{self.opcode:02X}'

    @property
    def handler_name(self):
        return 'handler_' + self.unique_key

    def generate_handler_declaration(self, context, output):
        context.write_non_indent_line(output, '')
        context.write_indent_line(output, f'inline bool {self.handler_name}({self.arg_decl_list});')

    def __generate_sub_state(self, context, output):
        context.write_non_indent_line(output, '')
        context.write_indent_line(output, 'switch(insb) {')

        for state in self.state_matrix:
            if state:
                state.generate_switch_case(context, output)

        context.write_non_indent_line(output, '')
        context.write_indent_line(output, 'default:')
        context.indent(True)
        context.write_indent_line(output, 'break;')
        context.indent(False)
        context.write_indent_line(output, '};')

    def __generate_extension_state(self, context, output):
        extensions = self.extensions

        context.write_non_indent_line(output, '')
        context.write_indent_line(output, 'Bit8u rmmod = Fetchb();')
        context.write_indent_line(output, 'Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);')

        if self.mod:
            context.write_indent_line(output, 'Bit8u mod = static_cast<Bit8u>(rmmod & 0xc0);')

        context.write_non_indent_line(output, '')
        context.write_indent_line(output, 'switch(rm) {')

        for (rm, ext) in extensions.items():
            context.write_indent_line(output, f'case 0x{rm:02X}:')
            context.indent(True)

            if 'all' in ext:
                state = ext['all']
                context.write_indent_line(output, f'return {state.handler_name}({state.arg_call_list});')
            else:
                for (key, state) in ext.items():
                    if key == 'nomem':
                        context.write_indent_line(output, f'if (mod == 0xc0)')
                    else:
                        context.write_indent_line(output, f'if (mod != 0xc0)')
                    context.indent(True)
                    context.write_indent_line(output, f'return {state.handler_name}({state.arg_call_list});')
                    context.indent(False)

            context.indent(False)

        context.write_non_indent_line(output, '')
        context.write_indent_line(output, 'default:')
        context.indent(True)
        context.write_indent_line(output, 'break;')
        context.indent(False)
        context.write_indent_line(output, '};')

    def generate_handler_definition(self, context, output):
        context.write_non_indent_line(output, '')
        context.write_indent_line(output, f'inline bool {context.class_name}::{self.handler_name}({self.arg_decl_list}) {{')
        context.indent(True)

        if self.state_matrix:
            self.__generate_sub_state(context, output)

        if self.extensions:
            self.__generate_extension_state(context, output)

        context.write_indent_line(output, 'return false;')

        context.indent(False)
        context.write_indent_line(output, '};')

    def generate_switch_case(self, context, output):
        context.write_indent_line(output, f'case 0x{self.opcode:02x}:')
        context.indent(True)

        if self.state_matrix:
            context.write_indent_line(output, 'insb = Fetchb();')
        context.write_indent_line(output, f'return {self.handler_name}({self.arg_call_list});')

        context.indent(False)

    def overwrite_transition(self, new_state, trigger):
        if not self.state_matrix:
            self.state_matrix = [None] * 256
        self.state_matrix[trigger] = new_state

    def add_transition(self, new_state, trigger):
        if self.state_matrix and self.state_matrix[trigger]:
            raise X86Error()
        self.overwrite_transition(new_state, trigger)

    def add_extension(self, opcd_ext, mod, state):
        if not opcd_ext in self.extensions:
            self.extensions[opcd_ext] = {}
        self.extensions[opcd_ext][mod] = state
        if mod in ('mem', 'nomem'):
            self.mod = True


class PrefixState(State):
    pr_name = 'pr'
    arg_call_list = ''
    arg_decl_list = ''

    def __init__(self, opcode, description):
        State.__init__(self, opcode, None, description)

    def generate_handler_declaration(self, context, output):
        context.write_non_indent_line(output, '')
        context.write_indent_line(output, f'inline bool {self.handler_name}({self.arg_decl_list});')

    def generate_handler_definition(self, context, output):
        context.write_non_indent_line(output, '')
        context.write_indent_line(output, f'inline bool {context.class_name}::{self.handler_name}({self.arg_decl_list}) {{')
        context.indent(True)

        context.write_indent_line(output, 'return true;')

        context.indent(False)
        context.write_indent_line(output, '};')

    def generate_switch_case(self, context, output):
        pass


class InstructionState(State):
    pr_name = 'in'
    address_types = set()
    data_types = set()

    def __init__(self, instruction, parent, description):
        State.__init__(self, instruction.opcodes[-1] if instruction.opcd_ext == -1 else instruction.opcd_ext, parent, description)
        self.instruction = instruction
        self.src_op_fmts = None
        self.dst_op_fmts = None
        for opt_fmt in instruction.op_fmts.operands:
            if opt_fmt.ind == 'src':
                self.src_op_fmts = opt_fmt
            elif opt_fmt.ind == 'dst':
                self.dst_op_fmts = opt_fmt

    @property
    def unique_name(self):
        name = f'{super().unique_name}_{self.instruction.mnemonic}'
        if self.dst_op_fmts:
            name += f'{self.dst_op_fmts}'
        if self.src_op_fmts:
            name += f'{self.src_op_fmts}'
        return name

    def generate_handler_declaration(self, context, output):
        instruction = self.instruction
        context.write_non_indent_line(output, '')
        context.write_indent_line(output, f'/* {self.unique_name} */')
        context.write_indent_line(output, f'inline bool {self.handler_name}({self.arg_decl_list});')

    def generate_handler_definition(self, context, output):
        instruction = self.instruction
        context.write_non_indent_line(output, '')
        context.write_indent_line(output, f'/* {self.unique_name}')
        context.write_indent_line(output, f' description: {instruction.description}')
        context.write_indent_line(output, f'*/')

        context.write_indent_line(output, f'inline bool {context.class_name}::{self.handler_name}({self.arg_decl_list}) {{')
        context.indent(True)

        context.write_indent_line(output, 'return true;')

        context.indent(False)
        context.write_indent_line(output, '}')


class StateTransitionGraph:
    """Contains all states and transitions between states"""
    mandatory_prefixes = [0x66, 0xf2, 0xf3]
    all_prefixes = mandatory_prefixes + [0x26, 0x2e, 0x36, 0x3e, 0x64, 0x65, 0x67, 0xf0]
    separator = '\t'
    class_name = 'CpuRunnerLLVM'
    base_class_name = 'CpuRunnerLLVMBase'

    def __init__(self):
        self.prefix_states = {}
        self.all_states = {}
        self.handlers = {}
        self.indention = ''

        # initialize the init states
        state = State(None, None, 'Init state')
        self.init_state = state
        self.__add_state(state)

    def __add_state(self, state):
        if state.unique_key in self.all_states:
            raise X86Error('Duplicated state' + state.unique_key)
        self.all_states[state.unique_key] = state

    def __parse_prefix(self, prefix):
        prefix_state = None

        logging.info('parsing prefix %02x', prefix)

        if prefix in [0x26, 0x2e, 0x36, 0x3e, 0x64, 0x65]:
            # Segment register override prefix
            prefix_state = PrefixState(prefix, 'Segment override prefix')

        elif prefix == 0xf0:
            # Lock prefix
            prefix_state = PrefixState(prefix, 'Lock prefix')

        elif prefix in [0xf2, 0xf3]:
            # Maybe Mandatory prefix or REP/REPZ/REPNZ prefix
            prefix_state = PrefixState(prefix, 'REP/REPZ/REPNZ prefix')

        elif prefix == 0x66:
            # Operand-size override prefix
            prefix_state = PrefixState(prefix, 'Operand-size override prefix')

        elif prefix == 0x67:
            # Address-size override prefix
            prefix_state = PrefixState(prefix, 'Address-size override prefix')

        if prefix_state and not prefix_state.unique_key in self.prefix_states:
            self.prefix_states[prefix_state.unique_key] = prefix_state

            if prefix in self.mandatory_prefixes:
                new_state = State(prefix, self.init_state)
                if not new_state.unique_key in self.all_states:
                    self.__add_state(new_state)
                self.init_state.overwrite_transition(new_state, prefix)

        return prefix_state

    def __insert_instruction_state(self, state, trigger, instruction):
        new_state = None

        if state.state_matrix and state.state_matrix[trigger]:
            old_state = state.state_matrix[trigger]
            key = old_state.unique_key
            old_instruction = old_state.instruction
            if old_instruction.mnemonic.startswith(instruction.mnemonic) or \
                    instruction.mnemonic.startswith(old_instruction.mnemonic) or \
                    old_instruction.description == instruction.description:
                logging.info(f'Same instruction {key} {old_instruction.mnemonic}={instruction.mnemonic}. Skip it')
                new_state = old_state
            else:
                logging.info(f'Overwrite existing state {key} = {instruction.mnemonic}')
                state.overwrite_transition(None, trigger)

        if not new_state:
            new_state = InstructionState(instruction, state, instruction.mnemonic)
            new_state.opcode = trigger
            logging.info(f'Create new state {new_state}')

            self.__add_state(new_state)
            #
            # if key in self.all_states:
            #     del new_state
            #     new_state = self.all_states[key]
            # else:
            #     self.all_states[key] = new_state

        assert new_state
        state.overwrite_transition(new_state, trigger)
        return True

    def __parse_instruction(self, instruction):

        if instruction.mnemonic in ('AAM', 'AAD'):
            return False

        if isinstance(instruction, InstrPrefix):
            return self.__parse_prefix(instruction.opcodes[0])

        if len(instruction.op_fmts.operands) > 2:
            pass

        logging.warning(f'Insert instruction '
                        f' : {instruction}')

        prefix = instruction.prefix
        opcd_ext = instruction.opcd_ext
        opcode_len = len(instruction.opcodes)

        if instruction.opcodes[0] == 0x0f:
            if opcode_len == 1:
                logging.error("Malformed 0F with 1 byte")
                return

            if instruction.opcodes[1] == 0x38 or instruction.opcodes[1] == 0x3a:
                if opcode_len > 3:
                    opcd_ext = -1
            else:
                if opcode_len > 2:
                    opcd_ext = -1

        op_index = instruction.opcodes[-1]
        op_path = instruction.opcodes[:-1]

        state = self.init_state
        if prefix:
            op_path.insert(0, prefix[0])

        # Create non-terminal states and transition
        for opcode in op_path:
            if state.state_matrix and state.state_matrix[opcode]:
                state = state.state_matrix[opcode]
            else:
                new_state = State(opcode, state, '')
                state.add_transition(new_state, opcode)
                state = new_state
                self.__add_state(state)

        # Extract Z register into multiple instruction handlers
        if instruction.op_fmts.operands and instruction.op_fmts.operands[0].origin_addr == 'Z':
            logging.info('Extract Z registers')
            for reg in range(8):
                self.__insert_instruction_state(state, op_index + reg, instruction)

        # Extract opcode extension into state transitions
        elif opcd_ext >= 0:
            if state.state_matrix and state.state_matrix[op_index]:
                base_state = state.state_matrix[op_index]
            else:
                base_state = State(op_index, state, '')
                state.add_transition(base_state, op_index)
                self.__add_state(base_state)

            new_state = InstructionState(instruction, base_state, instruction.mnemonic)
            mod = instruction.mod if instruction.mod in ('mem', 'nomem') else 'all'
            logging.info(f'add extension:{state} {base_state} + {opcd_ext} = {new_state}')
            base_state.add_extension(opcd_ext, mod, new_state)
            self.__add_state(new_state)

        # Convert single instruction handler
        else:
            self.__insert_instruction_state(state, op_index, instruction)

        return True

    def parse_instructions(self, instructions):
        for instruction in instructions.values():
            self.__parse_instruction(instruction)

    def dump(self):
        for key in sorted(self.prefix_states.keys()):
            logging.info(f'prefix[{key}] = {type(self.prefix_states[key])}')

        for key in sorted(self.all_states.keys()):
            logging.info(f'final[{key}] = {type(self.all_states[key])}')

    def __write_handler_definition(self, output):
        for key in sorted(self.prefix_states.keys()):
            self.prefix_states[key].generate_handler_definition(self, output)
        for key in sorted(self.all_states.keys()):
            self.all_states[key].generate_handler_definition(self, output)

    def __write_parse_prefix_definition(self, output):
        self.write_non_indent_line(output, '')
        self.write_indent_line(output, f'Bit8u {self.class_name}::ParsePrefix() {{')
        self.indent(True)

        self.write_indent_line(output, 'option_prefix.all_prefix = 0;')
        self.write_indent_line(output, 'mandatory_prefix = 0;')
        self.write_indent_line(output, 'bool expect_prefix = false;')
        self.write_indent_line(output, 'Bit8u insb = 0;')
        self.write_indent_line(output, 'do {')
        self.indent(True)

        self.write_indent_line(output, 'insb = Fetchb();')

        self.write_indent_line(output, 'switch (insb) {')

        for prefix in self.prefix_states.values():
            self.write_indent_line(output, f'case 0x{prefix.opcode:02x}:')
            self.indent(True)
            self.write_indent_line(output, f'{prefix.handler_name}();')

            if prefix.opcode in self.mandatory_prefixes:
                self.write_indent_line(output, 'mandatory_prefix = insb;')
            else:
                self.write_indent_line(output, 'mandatory_prefix = 0;')

            self.write_indent_line(output, 'break;')
            self.indent(False)

        self.write_indent_line(output, 'default:')
        self.indent(True)
        self.write_indent_line(output, 'expect_prefix = true;')
        self.write_indent_line(output, 'break;')
        self.indent(False)

        self.write_indent_line(output, '}')

        self.indent(False)
        self.write_indent_line(output, '} while (expect_prefix);')
        self.write_indent_line(output, 'return insb;')

        self.indent(False)
        self.write_indent_line(output, '}')
        self.write_non_indent_line(output, '')

    def __write_parse_opcode_switch(self, output, state):
        self.write_non_indent_line(output, '')
        self.write_indent_line(output, 'switch(insb) {')

        for substate in state.state_matrix:
            if substate:
                substate.generate_switch_case(output)

        self.write_indent_line(output, 'default:')
        self.indent(True)
        self.write_indent_line(output, 'return false;')
        self.indent(False)
        self.write_indent_line(output, '}')
        self.write_non_indent_line(output, '')

    def __write_parse_opcode_definition(self, output):
        self.write_non_indent_line(output, '')
        self.write_indent_line(output, f'bool {self.class_name}::Parse() {{')
        self.indent(True)
        self.write_indent_line(output, 'Bit8u insb = ParsePrefix();')

        self.write_indent_line(output, f'return {self.init_state.handler_name}(insb);')
        self.indent(False)
        self.write_indent_line(output, '}')

    def __write_parser_definition(self, output):
        self.__write_parse_prefix_definition(output)
        self.__write_parse_opcode_definition(output)

    def __write_definitions(self, output):
        self.__write_handler_definition(output)
        self.__write_parser_definition(output)

    def __write_references(self, output):
        self.write_indent_line(output, '#include "core_llvm_common.h"')
        self.write_non_indent_line(output, '')

    def __write_prefix_handler_declaration(self, output):
        for key in sorted(self.prefix_states.keys()):
            self.prefix_states[key].generate_handler_declaration(self, output)

    def __write_all_handler_declaration(self, output):
        for key in sorted(self.all_states.keys()):
            self.all_states[key].generate_handler_declaration(self, output)

    def __write_declarations(self, output):
        self.write_indent_line(output, f'class {self.class_name} : public {self.base_class_name} {{')

        # Write private declarations
        self.write_non_indent_line(output, '')
        self.write_indent_line(output, 'private:')

        self.indent(True)
        self.__write_prefix_handler_declaration(output)
        self.__write_all_handler_declaration(output)
        self.write_indent_line(output, 'Bit8u ParsePrefix();')
        self.indent(False)

        # Write public declarations
        self.write_non_indent_line(output, '')
        self.write_indent_line(output, 'public:')

        self.indent(True)
        self.write_indent_line(output, 'bool Parse();')
        self.indent(False)
        self.write_indent_line(output, f'}};')

    def __write_declaration(self, output):
        self.__write_references(output)
        self.write_non_indent_line(output, '#ifndef PROJECT_CORE_LLVM_H')
        self.write_non_indent_line(output, '#define PROJECT_CORE_LLVM_H')
        self.write_indent_line(output, 'namespace core_llvm {')
        self.write_non_indent_line(output, '')
        self.indent(True)

        self.__write_declarations(output)

        self.indent(False)
        self.write_non_indent_line(output, '')
        self.write_indent_line(output, '}')
        self.write_non_indent_line(output, '')
        self.write_non_indent_line(output, '#endif //PROJECT_CORE_LLVM_H')

    def __write_includes(self, output):
        self.write_indent_line(output, '#include "core_llvm_runner.h"')

    def __write_definition(self, output):
        self.__write_includes(output)
        self.write_indent_line(output, 'namespace core_llvm {')
        self.write_non_indent_line(output, '')
        self.indent(True)

        self.__write_definitions(output)

        self.indent(False)
        self.write_non_indent_line(output, '')
        self.write_indent_line(output, '}')
        self.write_non_indent_line(output, '')

    def write(self, header, source):
        self.__write_declaration(header)
        self.__write_definition(source)

    def write_indent_line(self, output, line):
        output.write(f'{self.indention}{line}\n')

    def write_non_indent_line(self, output, line):
        output.write(f'{line}\n')

    def indent(self, shift):
        if shift:
            self.indention += self.separator
        else:
            self.indention = self.indention[:-1]


def parse_options():
    parser = OptionParser()
    parser.add_option("-i", "--infile", dest="infile",
                      help="Read XML from FILE", metavar="FILE")
    parser.add_option("-o", "--header", dest="header",
                      help="Write runner header to FILE", metavar="FILE")
    parser.add_option("-s", "--source", dest="source",
                      help="Write runner source to FILE", metavar="FILE")
    parser.add_option("-l", "--logfile", dest="logfile",
                      help="Write logs to FILE", metavar="FILE")
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

    if options.header:
        header = open(options.header, 'w')
    else:
        header = sys.stderr

    if options.source:
        source = open(options.source, 'w')
    else:
        source = sys.stderr

    if options.logfile:
        logging.basicConfig(filename=options.logfile, level=logging.INFO)

    instructions = InstructionSet()
    instructions.parse_file(infile)
    infile.close()

    states = StateTransitionGraph()
    states.parse_instructions(instructions.instructions)
    states.dump()
    states.write(header, source)

    print('Done')


if __name__ == '__main__':
    main()

