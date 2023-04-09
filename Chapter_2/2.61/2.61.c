#include <stdio.h>
#include <assert.h>

int A(int x) {
  return !~x;
}

int B(int x) {
  return !x;
}

int C(int x) {
  return A(x | ~0xff);
}

int D(int x) {
  return B(x >> ((sizeof(int) - 1) << 3) & 0xff);
}

int main(int argc, char **argv) {
  int all_bit_one = ~0;
  int all_bit_zero = 0;
  int all_lsb_one = 0x123456ff;
  int all_msb_zero = 0x123456;

  assert(A(all_bit_one));
  assert(!B(all_bit_one));
  assert(C(all_bit_one));
  assert(!D(all_bit_one));

  assert(!A(all_bit_zero));
  assert(B(all_bit_zero));
  assert(!C(all_bit_zero));
  assert(D(all_bit_zero));

  assert(!A(all_lsb_one));
  assert(!B(all_lsb_one));
  assert(C(all_lsb_one));
  assert(!D(all_lsb_one));

  assert(!A(all_msb_zero));
  assert(!B(all_msb_zero));
  assert(!C(all_msb_zero));
  assert(D(all_msb_zero));

  return 0;
}
