#include "value.h"
#include "mem.h"
#include "lib.h"
#include <stdio.h>

void init_val_arr(val_arr_t *arr) {
  arr->values = NULL;
  arr->capacity = 0;
  arr->count = 0;
}

void write_val_arr(val_arr_t *arr, val_t val) {
  if (arr->capacity < arr->count + 1) {
    int old_cap = arr->capacity;
    arr->capacity = GROW_CAPACITY(old_cap);
    arr->values = GROW_ARRAY(val_t, arr->values, old_cap, arr->capacity);
  }

  arr->values[arr->count] = val;
  ++arr->count;
}

void free_val_arr(val_arr_t *arr) {
  FREE_ARRAY(val_t, arr->values, arr->capacity);
  init_val_arr(arr);
}

void print_val(val_t val) {
  printf("%g", val);
}
