#include <assert.h>
#include <stdlib.h>

// Hamming weight is the number of set bits in a number, i.e., the number of 1s in the binary representation of the
// number, see also op POPCNT instruction in x86 and ARM.
int
number_of_set_bits (unsigned int n)
{
  int count = 0;
  while (n) {
    count += n & 1;
    n >>= 1;
  }
  return count;
}

// Brian Kernighan's algorithm: iteratively clear the lowest set bit in n and increment the count until n is zero.
int
number_of_set_bits_bk (unsigned int n)
{
  int count = 0;
  while (n) {
    n &= (n - 1); // Removes the lowest set bit
    count++;
  }
  return count;
}

int
main (int argc, char *argv[])
{
  for (unsigned int i = 0; i < 10000; i++) {
    assert (number_of_set_bits (i) == number_of_set_bits_bk (i));
  }

  return EXIT_SUCCESS;
}
