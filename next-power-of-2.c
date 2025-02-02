#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

uint32_t
next_power_of_2_naive (uint32_t n)
{
  uint32_t p = 1;
  while (p < n)
    p *= 2;
  return p;
}

uint32_t
next_power_of_2 (uint32_t n)
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
  assert (next_power_of_2_naive (0) == 1);
  assert (next_power_of_2 (0) == 1);
  assert (next_power_of_2_naive (1) == 1);
  assert (next_power_of_2 (1) == 1);
  assert (next_power_of_2_naive (2) == 2);
  assert (next_power_of_2 (2) == 2);
  assert (next_power_of_2_naive (500) == 512);
  assert (next_power_of_2 (500) == 512);
  assert (next_power_of_2_naive (600) == 1024);
  assert (next_power_of_2 (600) == 1024);
  assert (next_power_of_2_naive (65535) == 65536);
  assert (next_power_of_2 (65535) == 65536);
  assert (next_power_of_2_naive (65536) == 65536);
  assert (next_power_of_2 (65536) == 65536);
  for (uint32_t i = 0; i < 10000; i++) {
    assert (next_power_of_2_naive (i) == next_power_of_2 (i));
  }
  return EXIT_SUCCESS;
}
