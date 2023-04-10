#pragma once

#include <vector>
#include <cstdint>
#include <string_view>

namespace debug {
void disassemble_chunk(const std::vector<uint8_t> &chunks, std::string_view name);
int disassemble_inst(const std::vector<uint8_t> &chunks, size_t offset);
};
