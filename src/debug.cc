#include "debug.hh"
#include "opcode.hh"
#include <cstdio>
#include <iostream>

void debug::disassemble_chunk(const std::vector<uint8_t> &chunks,
                              std::string_view name) {
  std::cout << " == " << name << " ==\n";

  for (size_t offset = 0; offset < chunks.size();) {
    offset += debug::disassemble_inst(chunks, offset);
  }
}

static size_t simple_instruction(std::string_view name, size_t offset) {
  std::cout << name << '\n';
  return offset + 1;
}

size_t debug::disassemble_inst(const std::vector<uint8_t> &chunks,
                               size_t offset) {
  printf("%04lud", offset);

  OP inst = static_cast<OP>(chunks[offset]);
  switch (inst) {
  case OP::Return:
    return simple_instruction("OP_RETURN", offset);
  default:
    printf("unknown opcode %d\n", chunks[offset]);
    return offset + 1;
  }
}
