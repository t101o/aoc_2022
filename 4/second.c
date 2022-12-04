#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

struct area
{
  int64_t lower_bound;
  int64_t upper_bound;
};

int64_t overlaps(struct area a1, struct area a2)
{
  return (a1.lower_bound <= a2.upper_bound
	  && a2.lower_bound <= a1.upper_bound);
}

int
main(void)
{
  FILE *input = fopen("input.txt", "r");
  if (!input)
    {
      exit(EXIT_FAILURE);
    }

  char s[100] = "";
  struct area elves[2];
  int64_t count = 0;
  while (fgets(s, 99, input))
    {
      sscanf(s, "%ld %ld %ld %ld",
	     &elves[0].lower_bound,
	     &elves[0].upper_bound,
	     &elves[1].lower_bound,
	     &elves[1].upper_bound);
      printf("%ld %ld %ld %ld\n",
	     elves[0].lower_bound,
	     elves[0].upper_bound,
	     elves[1].lower_bound,
	     elves[1].upper_bound);
      count += overlaps(elves[0], elves[1]);
    }
  printf("%lld\n", count);
  return 0;
}
