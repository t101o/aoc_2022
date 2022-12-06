#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int64_t
equal(char **c, size_t size)
{
  for (size_t i = 0; i < size - 1; i++)
    {
      for (size_t j = i + 1; j < size; j++)
	{
	  if ((*c)[i] == (*c)[j]) { return 0; }
	}
    }
  return 1;
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
  size_t size = 14;
  char *marker = malloc(sizeof(char) * size);
  memset(marker, 0, size);
  char c = ' ';
  int64_t i = 0;
  while ((c = fgetc(input)) != EOF)
    {
      marker[i % size] = c;
      if (i > size && equal(&marker, size))
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
