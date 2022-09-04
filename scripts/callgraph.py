import sys
import re

THREAD_PATTERN = re.compile(r'thread with id (\d+)')
# module_whitelist = ('dosbox', 'libSDL-1.2.0.dylib', 'libSDL_net-1.2.0.dylib')
module_whitelist = ('dosbox')


class MethodCalls:
    def __init__(self):
        self.direct_calls = set()
        self.indirect_calls = set()
        self.current_thread_id = 0
        self.current_node: str or None = None
        self.is_direct_call = False

    def add_direct_call(self, call):
        if call in self.indirect_calls:
            self.indirect_calls.remove(call)
        self.direct_calls.add(call)

    def add_indirect_call(self, call):
        if call not in self.direct_calls:
            self.indirect_calls.add(call)

    @staticmethod
    def is_allowed_module(node):
        method_info = node.split('`')
        if len(method_info) < 2:
            return False
        if method_info[0] not in module_whitelist:
            return False
        return True

    def add_call(self, node):
        is_allowed_module = self.is_allowed_module(node)

        if self.current_node is not None and is_allowed_module:
            if self.is_direct_call:
                self.add_direct_call((self.current_node, node))
            else:
                self.add_indirect_call((self.current_node, node))

        self.is_direct_call = is_allowed_module
        if is_allowed_module:
            self.current_node = node

    def add_line(self, line):
        self.is_direct_call = False
        self.current_node = None
        a = line.rsplit(' ', 1)
        segments = a[0].split(';')
        for node in segments[1:]:
            self.add_call(node)

    def parse_file(self, infile):
        for line in infile:
            self.add_line(line)

    def __repr__(self):
        return_str = 'direct calls:{'
        for call in self.direct_calls:
            return_str += f'{call[0]}->{call[1]}, '
        return_str += '} indirect_calls:{'
        for call in self.indirect_calls:
            return_str += f'{call[0]}..>{call[1]}, '
        return_str += '}'
        return return_str

    def print_dot_to_file(self, outfile):
        outfile.write('digraph {\n')
        for call in self.direct_calls:
            outfile.write(f'  "{call[0]}" -> "{call[1]}"\n')
        for call in self.indirect_calls:
            outfile.write(f'  "{call[0]}" -> "{call[1]}"\n')
        outfile.write('}')


def main(argv):
    method_calls = MethodCalls()
    with open(argv[1], 'rt') as infile:
        method_calls.parse_file(infile)
    with open(argv[2], 'wt') as outfile:
        method_calls.print_dot_to_file(outfile)


if __name__ == '__main__':
    main(sys.argv)
