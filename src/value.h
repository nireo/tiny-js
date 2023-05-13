#ifndef JS_VALUE_H
#define JS_VALUE_H

typedef double val_t;

typedef struct {
  int capacity;
  int count;
  val_t *values;
} val_arr_t;

void init_val_arr(val_arr_t *arr);
void write_val_arr(val_arr_t *arr, val_t value);
void free_val_arr(val_arr_t *arr);
void print_val(val_t val);

#endif
