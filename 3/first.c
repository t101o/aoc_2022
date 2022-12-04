#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/* Calculate the priority of an item.
   Returns the priority score.  
 */
int64_t
letter_priority(const char c)
{
  if (c >= 'A' && c <= 'Z')
    {
      return 'Z' + c + 2 - 2 * 'A';
    }
  else if (c >= 'a' && c <= 'z')
    {
      return c - 'a' + 1;
    }
}

/* Determine the common letter in a string split by the position mid.
   Returns the common letter.  
 */
char
common_letter(const char *s, const int64_t mid)
{
  int64_t pos = mid;
  for (size_t i = 0; i < mid; i++)
    {
      while (s[pos] != '\0')
	{
	  if (s[i] == s[pos])
	    {
	      return s[i];
	    }
	  pos++;
	}
      pos = mid;
    }
}


int
main(void)
{
  FILE *input = fopen("input.txt", "r");
  if (input == NULL)
    {
      exit(EXIT_FAILURE);
    }

  char s[256] = "";
  int64_t sum = 0;
  int64_t count = 0;

  while (fgets(s, 255, input))
    {
      count = strlen(s) - 1;
      int64_t mid = count / 2;
      char letter = common_letter(s, mid);
      int64_t val = letter_priority(letter);
      sum += val;
    }
  printf("%lld\n", sum);
  
  return 0;
}
