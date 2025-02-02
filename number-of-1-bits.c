#include <assert.h>
#include <stdlib.h>

int
hamming_weight (unsigned int n)
{
  int count = 0;
  while (n) {
    count += n & 1;
    n >>= 1;
  }
  return count;
}

int
hamming_weight_bk (unsigned int n)
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
    assert (hamming_weight (i) == hamming_weight_bk (i));
  }

  return EXIT_SUCCESS;
}
