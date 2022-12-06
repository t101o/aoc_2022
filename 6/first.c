#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int64_t
equal(const char c1, const char c2, const char c3, const char c4)
{
    return !((c1 == c2)
	     || (c1 == c3)
	     || (c1 == c4)
	     || (c2 == c3)
	     || (c2 == c4)
	     || (c3 == c4));
}

int
main(void)
{
  FILE *input = fopen("input.txt", "r");
  if (!input)
    {
      perror("*ERROR* ");
      exit(EXIT_FAILURE);
    }

  char marker[4] = {' ', ' ', ' ', ' '};
  char c = ' ';
  int64_t i = 0;
  while ((c = fgetc(input)) != EOF)
    {
      marker[i % 4] = c;
      if (i > 4 && equal(marker[0], marker[1], marker[2], marker[3]))
	{
	  printf("%c%c%c%c %lld\n",
		 marker[0],
		 marker[1],
		 marker[2],
		 marker[3],
		 i + 1);
	  break;
	}
      i++;
    }
  fclose(input);
  return 0;
}
