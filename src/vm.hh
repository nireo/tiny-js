#pragma once

#include "chunk.hh"

enum class run_result_t {
  Ok,
  CompileError,
  RuntimeError,
};

struct vm_t {
  run_result_t run() noexcept;

  uint8_t const *ip;
  chunk_t chunk;
};
