#pragma once

#include <cstdint>
#include <string_view>
#include <vector>

namespace debug {
void disassemble_chunk(const std::vector<uint8_t> &chunks,
                       std::string_view name);
size_t disassemble_inst(const std::vector<uint8_t> &chunks, size_t offset);
}; // namespace debug
