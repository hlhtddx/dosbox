#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

from optparse import OptionParser
from typing import Tuple

from x86reference import InstructionSet, InstrPrefix, Instruction, X86Error
import copy
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


class HandlerParam:
    def __init__(self, opt_fmt, operand_size):
        self.address = opt_fmt.address
        operand_type = opt_fmt.type[operand_size]
        if operand_type:
            self.data_type = operand_type[0]
            self.data_size = operand_type[1]

    @property
    def address_string(self):
        s = ''
        for address in self.address:
            if address:
                s += f'_{address}'
        return s

    def __str__(self):
        return self.address_string + f'_{self.data_type}{self.data_size}'


class State:
    opcodes: Tuple

    def __init__(self, pr_name, address_size, operand_size):
        self.pr_name = pr_name
        self.description = ''
        self.address_size = address_size
        self.operand_size = operand_size
        self.state_matrix = [None] * 256

    def __str__(self):
        return self.unique_key

    @property
    def terminate(self):
        return False

    @property
    def has_handler(self):
        return False

    @property
    def unique_key(self):
        return f'{self.pr_name}_{self.unique_name}'

    @property
    def unique_name(self):
        return self.__hash__()

    @property
    def label_name(self):
        return self.unique_key

    @property
    def table_name(self):
        return 'table_' + self.unique_key

    @property
    def handler_name(self):
        return 'handler_' + self.unique_key

    @property
    def handler_implement(self):
        return 'handler_' + self.unique_key

    def generate_state_table(self, context, output):
        output.write(f'{context.indention}const OpState {context.class_name}::{self.table_name}[] = {{')
        context.indent(True)

        cols = 8
        for i in range(len(self.state_matrix) // cols):
            idx_row = i * cols
            output.write('\n')
            output.write(f'{context.indention}// {idx_row:02X}\n')
            output.write(f'{context.indention}')
            for j in range(cols):
                index = idx_row | j
                state = self.state_matrix[index]
                if state:
                    output.write(f'{state.label_name}, ')
                else:
                    output.write(f'in_illegal, ')

        context.indent(False)
        output.write(f'{context.indention}\n}};')
        output.write('\n')

    def generate_definition(self, context, output):
        pass

    def overwrite_transition(self, new_state, trigger):
        self.state_matrix[trigger] = new_state

    def add_transition(self, new_state, trigger):
        if self.state_matrix[trigger]:
            raise X86Error()
        self.overwrite_transition(new_state, trigger)


class IntermediateState(State):
    prefix_name = 'st'

    def __init__(self, address_size, operand_size, opcodes=()):
        State.__init__(self, self.prefix_name, address_size, operand_size)
        assert isinstance(opcodes, tuple)
        self.opcodes = opcodes

    @staticmethod
    def get_unique_key(address_size, operand_size, opcodes):
        return f'{IntermediateState.prefix_name}_{IntermediateState.get_unique_name(address_size, operand_size, opcodes)}'

    @staticmethod
    def get_unique_name(address_size, operand_size, opcodes):
        s = f'{address_size_specifiers[address_size]}_{operand_size_specifiers[operand_size]}'
        for opcode in opcodes:
            s += f'_{opcode:02X}'
        return s

    @property
    def unique_name(self):
        return self.get_unique_name(self.address_size, self.operand_size, self.opcodes)

    def generate_definition(self, context, output):
        pass


class PrefixState(State):
    prefix_name = 'pr'

    def __init__(self, address_size, operand_size, opcode, next_state, description):
        State.__init__(self, self.prefix_name, address_size, operand_size)
        self.opcode = opcode
        self.next_state = next_state
        self.description = description

    @property
    def has_handler(self):
        return True

    @staticmethod
    def get_unique_key(address_size, operand_size, opcode):
        return f'{IntermediateState.prefix_name}_{IntermediateState.get_unique_name(address_size, operand_size, opcode)}'

    @staticmethod
    def get_unique_name(address_size, operand_size, opcode):
        s = f'{address_size_specifiers[address_size]}_{operand_size_specifiers[operand_size]}_{opcode:02X}'
        return s

    @property
    def unique_name(self):
        return self.get_unique_name(self.address_size, self.operand_size, self.opcode)

    def generate_definition(self, context, output):
        output.write('\n')
        output.write(f'{context.indention}static inline OpState {self.handler_name}() {{\n')
        context.indent(True)

        output.write(f'{context.indention}// TODO\n')
        output.write(f'{context.indention}return {self.next_state.label_name};\n')

        context.indent(False)
        output.write(f'{context.indention}}};\n')


class InstructionState(State):
    prefix_name = 'in'
    address_types = set()
    data_types = set()

    def __init__(self, instruction, address_size, operand_size):
        State.__init__(self, self.prefix_name, address_size, operand_size)
        self.instruction = instruction
        self.src_op_fmts = None
        self.dst_op_fmts = None
        for opt_fmt in instruction.op_fmts.operands:
            if opt_fmt.ind == 'src' and opt_fmt.type[operand_size]:
                self.src_op_fmts = HandlerParam(opt_fmt, operand_size)
                self.address_types.add(f't{self.src_op_fmts.address_string}')
                self.data_types.add(f't_{self.src_op_fmts.data_type}{self.src_op_fmts.data_size}')
            elif opt_fmt.ind == 'dst' and opt_fmt.type[operand_size]:
                self.dst_op_fmts = HandlerParam(opt_fmt, operand_size)
                self.address_types.add(f't{self.dst_op_fmts.address_string}')
                self.data_types.add(f't_{self.dst_op_fmts.data_type}{self.dst_op_fmts.data_size}')

    @property
    def terminate(self):
        return True

    @property
    def has_handler(self):
        return True

    @property
    def unique_name(self):
        name = self.instruction.mnemonic
        if self.instruction.is_addressing:
            name += f'_{address_size_specifiers[self.address_size]}'
        if self.dst_op_fmts:
            name += f'{self.dst_op_fmts}'
        if self.src_op_fmts:
            name += f'{self.src_op_fmts}'
        return name

    @property
    def handler_name(self):
        s = f'handler_{self.instruction.mnemonic}'

        if self.instruction.is_addressing:
            s += f'_{address_size_specifiers[self.address_size]}'

        if self.dst_op_fmts:
            s += f'{self.dst_op_fmts.address_string}_{self.dst_op_fmts.data_type}{self.dst_op_fmts.data_size}'

        if self.src_op_fmts:
            s += f'{self.src_op_fmts.address_string}_{self.src_op_fmts.data_type}{self.src_op_fmts.data_size}'

        return s

    @property
    def handler_implement(self):
        return self.handler_name()

    def generate_declaration(self, context, output):
        instruction = self.instruction
        output.write('\n')
        output.write(f'{context.indention}/* {instruction.mnemonic}({instruction.prefix}_{instruction.opcodes}) : {instruction.description} */\n')
        output.write(f'{context.indention}inline bool {self.handler_name}'
                     f'(Bit8u last, PhysPt &cseip) {{\n')
        context.indent(True)

        output.write(f'{context.indention}return true;\n')

        context.indent(False)
        output.write(f'{context.indention}}}\n')

    def generate_definition(self, context, output):
        pass
        # instruction = self.instruction
        # output.write('\n')
        # output.write(f'{context.indention}/* {instruction.mnemonic} : {instruction.description} */\n')
        # output.write(f'{context.indention}template<typename addr, typename dst_type'
        #              f', typename src_type>\n')
        # output.write(f'{context.indention}inline bool {self.handler_implement}'
        #              f'<addr, dst_type, src_type>'
        #              f'(Bit8u last, PhysPt &cseip) {{\n')
        # context.indent(True)
        #
        # output.write(f'{context.indention}return true;\n')
        #
        # context.indent(False)
        # output.write(f'{context.indention}}}\n')



class StateTransitionGraph:
    """Contains all states and transitions between states"""
    mandatory_prefixes = [0x66, 0xf2, 0xf3]
    all_prefixes = mandatory_prefixes + [0x26, 0x2e, 0x36, 0x3e, 0x64, 0x65, 0x67, 0xf0]
    seperator = '\t'
    class_name = 'CpuRunnerX86'

    def __init__(self):
        self.prefix_state_map = {}
        self.interm_state_map = {}
        self.final_state_map = {}
        self.transition_set = set()
        self.handlers = {}
        self.indention = ''

        # initialize the init states
        self.init_states = []
        for address_size in range(address_size_count):
            for operand_size in range(operand_size_count):
                state = IntermediateState(address_size, operand_size)
                self.init_states.append(state)
                self.interm_state_map[state.unique_key] = state

        # initialize states for mandatory prefixes
        for address_size in range(address_size_count):
            for operand_size in range(operand_size_count):
                for prefix in StateTransitionGraph.mandatory_prefixes:
                    state = IntermediateState(address_size, operand_size, (prefix,))
                    self.interm_state_map[state.unique_key] = state

        self.parse_prefixes(self.all_prefixes)

    def parse_prefixes(self, prefixes):
        for state in self.init_states:
            addr_size_spec = state.address_size
            oper_size_spec = state.operand_size

            for prefix in prefixes:
                new_state = None

                if prefix in [0x26, 0x2e, 0x36, 0x3e, 0x64, 0x65]:
                    # Segment register override prefix
                    # Add handlers
                    next_state = self.interm_state_map[IntermediateState.get_unique_key(addr_size_spec, oper_size_spec, ())]
                    new_state = PrefixState(addr_size_spec, oper_size_spec, prefix, next_state, 'Segment override prefix')

                elif prefix == 0xf0:
                    # Lock prefix
                    # Add handlers
                    next_state = self.interm_state_map[IntermediateState.get_unique_key(addr_size_spec, oper_size_spec, ())]
                    new_state = PrefixState(addr_size_spec, oper_size_spec, prefix, next_state, 'Lock prefix')

                elif prefix in [0xf2, 0xf3]:
                    # Maybe Mandatory prefix or REP/REPZ/REPNZ prefix
                    # Add MP states and handlers
                    next_state = self.interm_state_map[IntermediateState.get_unique_key(addr_size_spec, oper_size_spec, (prefix,))]
                    new_state = PrefixState(addr_size_spec, oper_size_spec, prefix, next_state, 'REP/REPZ/REPNZ prefix')

                elif prefix == 0x66:
                    # Operand-size override prefix
                    # Add MP states
                    oper_size_spec = switch_size_specifiers(oper_size_spec)
                    next_state = self.interm_state_map[IntermediateState.get_unique_key(addr_size_spec, oper_size_spec, (prefix,))]

                elif prefix == 0x67:
                    # Address-size override prefix
                    # Add MP states
                    addr_size_spec = switch_size_specifiers(addr_size_spec)
                    next_state = self.interm_state_map[IntermediateState.get_unique_key(addr_size_spec, oper_size_spec, ())]

                if new_state:
                    state.add_transition(new_state, prefix)
                    self.prefix_state_map[new_state.unique_key] = new_state
                elif next_state:
                    state.add_transition(next_state, prefix)

    def __parse_prefix(self, prefix, address_size, operand_size):
        pass

    def __parse_instruction_with_size(self, instruction, address_size, operand_size):
        if isinstance(instruction, InstrPrefix):
            return self.__parse_prefix(instruction, address_size, operand_size)

        if len(instruction.op_fmts.operands) > 2:
            pass

        logging.warning(f'Insert instruction '
                        f'address_size={address_size_specifiers[address_size]} '
                        f'operand_size={operand_size_specifiers[operand_size]} '
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

        opcd_ext_type = 0  # Both mem/nomem
        if instruction.mod == 'mem':
            opcd_ext_type = 1  # mem
        elif instruction.op_fmts.operands and instruction.op_fmts.operands[0].address == 'M':
            opcd_ext_type = 1  # mem
        elif instruction.mod == 'nomem':
            opcd_ext_type = 2  # nomem

        if opcd_ext >= 0:
            op_index = opcd_ext << 3
            op_path = instruction.opcodes
        else:
            op_index = instruction.opcodes[-1]
            op_path = instruction.opcodes[:-1]

        init_state_key = IntermediateState.get_unique_key(address_size, operand_size, prefix)
        opcodes = []

        state = self.interm_state_map[init_state_key]

        # Create non-terminal states and transition
        for opcode in op_path:
            opcodes.append(opcode)
            # Skip states already in map
            new_key = IntermediateState.get_unique_key(address_size, operand_size, opcodes)
            if new_key in self.interm_state_map:
                state = self.interm_state_map[new_key]
                assert isinstance(state, IntermediateState)
                continue

            new_state = IntermediateState(address_size, operand_size, tuple(opcodes))
            self.interm_state_map[new_key] = new_state
            state.add_transition(new_state, opcode)
            state = new_state

        # Extract Z register into multiple instruction handlers
        if instruction.op_fmts.operands and instruction.op_fmts.operands[0] == ('reg', 'reg', None):
            logging.info('Extract Z registers')
            for reg in range(8):
                self.__insert_instruction_state(state, op_index + reg, instruction, address_size, operand_size)

        # Extract opcode extension into state transitions
        elif opcd_ext >= 0:
            # MEM
            if opcd_ext_type == 0 or opcd_ext_type == 1:
                for row in address_mode_mem_only:
                    for rm in range(8):
                        real_op_index = row | op_index | rm
                        logging.debug("real_op_index(%02x, %02x, %02x, %02x)" % (real_op_index, row, op_index, rm))
                        self.__insert_instruction_state(state, real_op_index, instruction, address_size, operand_size)

            # Not MEM
            if opcd_ext_type == 0 or opcd_ext_type == 2:
                for row in address_mode_reg_only:
                    for rm in range(8):
                        real_op_index = row | op_index | rm
                        logging.debug("real_op_index(%02x, %02x, %02x, %02x)" % (real_op_index, row, op_index, rm))
                        self.__insert_instruction_state(state, real_op_index, instruction, address_size, operand_size)

        # Convert single instruction handler
        else:
            self.__insert_instruction_state(state, op_index, instruction, address_size, operand_size)

    def __insert_instruction_state(self, state, trigger, instruction, address_size, operand_size):
        # The instruction is not to access memory address
        if not instruction.is_addressing and address_size != 0:
            address_size = 0

        # The instruction is not effected by operand size override
        if instruction.op_size == 0 and operand_size != 0:
            operand_size = 0

        # The instruction is not effected by operand size override
        elif instruction.op_size == -1 and operand_size != 0:
            operand_size = 0

        elif not instruction.support_operand_size(operand_size):
            return False

        new_state = None

        if state.state_matrix[trigger]:
            old_state = state.state_matrix[trigger]
            key = old_state.unique_key
            assert old_state.terminate
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
            new_state = InstructionState(instruction, address_size, operand_size)
            key = new_state.unique_key
            logging.info(f'Create new state {key}')

            if key in self.final_state_map:
                del new_state
                new_state = self.final_state_map[key]
            else:
                self.final_state_map[key] = new_state

        assert new_state
        state.overwrite_transition(new_state, trigger)
        return True

    def __parse_instruction(self, instruction):
        if instruction.mnemonic in ('AAM', 'AAD'):
            return False

        for address_size in range(address_size_count):
            for operand_size in range(operand_size_count):
                self.__parse_instruction_with_size(instruction, address_size, operand_size)

        return True

    def parse_instructions(self, instructions):
        for instruction in instructions.values():
            self.__parse_instruction(instruction)

    def dump(self):
        for key in sorted(self.interm_state_map.keys()):
            logging.info(f'state[{key}] = {self.interm_state_map[key]}')

        for key in sorted(self.prefix_state_map.keys()):
            logging.info(f'prefix[{key}] = {self.prefix_state_map[key]}')

        for key in sorted(self.final_state_map.keys()):
            logging.info(f'final[{key}] = {self.final_state_map[key]}')

        for transition in self.transition_set:
            logging.info(f'transition : {transition.handler}')

    def write_state_declaration(self, output):
        output.write('enum OpState {\n')
        self.indent(True)

        for state in self.interm_state_map.values():
            output.write(f'{self.indention}{state.label_name},\n')

        for state in self.prefix_state_map.values():
            output.write(f'{self.indention}{state.label_name},\n')

        state_count = len(self.interm_state_map) + len(self.prefix_state_map)
        instr_base = 0x1000
        while instr_base <= state_count:
            instr_base <<= 1

        output.write('\tin_illegal = 0x%x,\n' % instr_base)

        for state in self.final_state_map.values():
            output.write(f'{self.indention}{state.label_name},\n')

        self.indent(False)
        output.write('};\n')

    def write_state_map_declaration(self, output):
        for state in self.interm_state_map.values():
            output.write(f'{self.indention}static const OpState {state.table_name}[];\n')
        for state in self.prefix_state_map.values():
            output.write(f'{self.indention}static const OpState {state.table_name}[];\n')
        output.write(f'{self.indention}static const OpState* const AllStateTable[];\n')

    def write_state_map_definition(self, output):
        for state in self.interm_state_map.values():
            state.generate_state_table(self, output)

        for state in self.prefix_state_map.values():
            state.generate_state_table(self, output)

        output.write('\n')
        output.write(f'{self.indention}const OpState* const {self.class_name}::AllStateTable[] = {{\n')
        self.indent(True)

        for state in self.interm_state_map.values():
            output.write(f'{self.indention}{self.class_name}::{state.table_name},\n')

        for state in self.prefix_state_map.values():
            output.write(f'{self.indention}{self.class_name}::{state.table_name},\n')

        self.indent(False)
        output.write(f'{self.indention}}};\n')

    def write_prefix_handler_declaration(self, output):
        for state in self.prefix_state_map.values():
            state.generate_definition(self, output)

    def write_handler_declaration(self, output):
        for state in self.final_state_map.values():
            state.generate_declaration(self, output)

    def write_handler_definition(self, output):
        for state in self.final_state_map.values():
            state.generate_definition(self, output)

    def write_parser_definition(self, output):
        output.write('\n')
        output.write(f'{self.indention}bool {self.class_name}::Parse(PhysPt &cseip) {{\n')
        self.indent(True)
        output.write(f'{self.indention}OpState state = mInitState;\n')
        output.write(f'{self.indention}Bit8u insb = 0;\n')
        output.write(f'{self.indention}do {{\n')
        self.indent(True)
        output.write(f'{self.indention}insb = Fetchb(cseip);\n')
        output.write(f'{self.indention}const OpState* table = AllStateTable[state];\n')
        output.write(f'{self.indention}state = table[insb];\n')

        output.write('\n')
        output.write(f'{self.indention}switch(state) {{\n')

        for state in self.prefix_state_map.values():
            output.write(f'{self.indention}// {state.description}\n')
            output.write(f'{self.indention}case {state.label_name}:\n')
            self.indent(True)
            output.write(f'{self.indention}state = {state.handler_name}();\n')
            output.write(f'{self.indention}break;\n')
            self.indent(False)

        output.write('\n')
        output.write(f'{self.indention}default:\n')
        self.indent(True)
        output.write(f'{self.indention}break;\n')
        self.indent(False)
        output.write(f'{self.indention}}}\n')
        self.indent(False)
        output.write(f'{self.indention}}} while(state < in_illegal);\n')

        output.write('\n')
        output.write(f'{self.indention}switch(state) {{\n')
        for state in self.final_state_map.values():
            output.write(f'{self.indention}case {state.label_name}:\n')
            self.indent(True)
            output.write(f'{self.indention}return {state.handler_name}(insb, cseip);\n')
            self.indent(False)

        output.write(f'{self.indention}default:\n')
        self.indent(True)
        output.write(f'{self.indention}break;\n')
        self.indent(False)
        output.write(f'{self.indention}}}\n')
        output.write(f'{self.indention}return false;\n')
        self.indent(False)
        output.write(f'{self.indention}}}\n')

    def write_declarations(self, output):
        self.write_state_declaration(output)
        output.write(f'{self.indention}struct {self.class_name} {{\n')
        self.indent(True)
        output.write(f'{self.indention}OpState mInitState;\n')

        output.write('\n')
        self.write_state_map_declaration(output)
        self.write_prefix_handler_declaration(output)
        self.indent(False)

        self.indent(True)
        output.write(f'{self.indention}bool Parse(PhysPt &cseip);\n')
        self.indent(False)
        output.write(f'{self.indention}}};\n')
        self.write_handler_declaration(output)

    def write_definitions(self, output):
        self.write_state_map_definition(output)
        self.write_handler_definition(output)
        self.write_parser_definition(output)

    def write_template(self, outfile):
        for address in ('addr_d', 'addr_w'):
            outfile.write(f'{self.indention}class {address} {{\n')
            outfile.write(f'{self.indention}public:\n')
            self.indent(True)
            self.indent(False)
            outfile.write(f'{self.indention}}};\n')
            outfile.write('\n')

        for address_type in InstructionState.address_types:
            outfile.write(f'{self.indention}template<typename T>class {address_type} {{\n')
            outfile.write(f'{self.indention}public:\n')
            self.indent(True)
            outfile.write(f'{self.indention}T& GetSource() {{}}\n')
            outfile.write(f'{self.indention}T& GetTarget() {{}}\n')
            self.indent(False)
            outfile.write(f'{self.indention}}};\n')
            outfile.write('\n')

        for data_type in InstructionState.data_types:
            outfile.write(f'{self.indention}typedef int {data_type};\n')
            outfile.write('\n')

    def write_imports(self, output):
        output.write(f'{self.indention}#ifndef PROJECT_CORE_LLVM_H\n')
        output.write(f'{self.indention}#define PROJECT_CORE_LLVM_H\n')
        output.write(f'{self.indention}#include "core_llvm_common.h"\n')
        output.write(f'{self.indention}namespace core_llvm {{\n')

    def write_footer(self, output):
        output.write(f'{self.indention}}}\n')
        output.write(f'{self.indention}#endif //PROJECT_CORE_LLVM_H\n')

    def write_include(self, output):
        output.write(f'{self.indention}#include "core_llvm_runner.h"\n')
        output.write(f'{self.indention}namespace core_llvm {{\n')

    def write_source_footer(self, output):
        output.write(f'{self.indention}}}\n')

    def write_header(self, output):
        self.write_imports(output)
        self.write_template(output)
        self.write_declarations(output)
        self.write_footer(output)

    def write_source(self, output):
        self.write_include(output)
        self.write_definitions(output)
        self.write_source_footer(output)

    def write(self, header, source):
        self.write_header(header)

        self.write_source(header)

    def indent(self, shift):
        if shift:
            self.indention += self.seperator
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

