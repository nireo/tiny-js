#pragma once

#include "value.h"

struct chunk_t {
  size_t add_constant(val_t val) {
    constants.emplace_back(val);
    return constants.size() - 1;
  }

  std::vector<uint8_t> code;
  val_vec_t constants;
};
