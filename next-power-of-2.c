#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

uint32_t
naive_np2 (uint32_t n)
{
  uint32_t p = 1;
  while (p < n)
    p *= 2;
  return p;
}

uint32_t
np2 (uint32_t n)
{
  if (n == 0)
    return 1;
  n--;
  n |= n >> 1;
  n |= n >> 2;
  n |= n >> 4;
  n |= n >> 8;
  n |= n >> 16;
  return n + 1;
}

int
main (int argc, char *argv[])
{
  assert (naive_np2 (0) == 1);
  assert (np2 (0) == 1);
  assert (naive_np2 (1) == 1);
  assert (np2 (1) == 1);
  assert (naive_np2 (2) == 2);
  assert (np2 (2) == 2);
  assert (naive_np2 (500) == 512);
  assert (np2 (500) == 512);
  assert (naive_np2 (600) == 1024);
  assert (np2 (600) == 1024);
  assert (naive_np2 (65535) == 65536);
  assert (np2 (65535) == 65536);
  assert (naive_np2 (65536) == 65536);
  assert (np2 (65536) == 65536);
  return EXIT_SUCCESS;
}
