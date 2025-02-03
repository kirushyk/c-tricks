#include <assert.h>
#include <stdlib.h>

#define SWAP(a, b) \
  do { \
    a = a ^ b; \
    b = a ^ b; \
    a = a ^ b; \
  } while (0)

int
main (int argc, char *argv[])
{
  int a = 1;
  int b = 2;
  SWAP (a, b);
  assert (a == 2);
  assert (b == 1);
  SWAP (a, b);
  assert (a == 1);
  assert (b == 2);

  int c = 3;
  // Will not work for same memory location
  SWAP (c, c);
  assert (c == 0);

  return EXIT_SUCCESS;
}
