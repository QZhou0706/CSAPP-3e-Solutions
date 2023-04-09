#include <stdio.h>
#include <assert.h>

typedef unsigned char* byte_pointer;

int int_shift_are_arithmetic1() {
  int x = 0xff << ((sizeof(int) - 1) << 3);
  return !~(x >> ((sizeof(int) - 1) << 3));
}

int int_shift_are_arithmetic2() {
  int num = -1;
  return !(num ^ (num >> 1));
}

int main(int argc, char **argv) {
  assert(int_shift_are_arithmetic1());
  assert(int_shift_are_arithmetic2());

  return 0;
}
