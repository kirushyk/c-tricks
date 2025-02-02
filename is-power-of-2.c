#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

bool
is_power_of_2 (int n)
{
  return n > 0 && (n & (n - 1)) == 0;
}

int
main (int argc, char *argv[])
{
  assert (is_power_of_2 (1));
  assert (is_power_of_2 (2));
  assert (is_power_of_2 (4));
  assert (is_power_of_2 (8));

  assert (!is_power_of_2 (0));
  assert (!is_power_of_2 (3));
  assert (!is_power_of_2 (5));
  assert (!is_power_of_2 (7));
  assert (!is_power_of_2 (9));

  return EXIT_SUCCESS;
}
