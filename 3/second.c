#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void letter_count(int64_t *table, const char *s);
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

/* Determine the common letter for a group.  
   Returns the common letters priority.  
 */
int64_t
common_letter_priority (const char *s1, const char *s2, const char *s3)
{
  int64_t letters[52] = {0};

  letter_count(letters, s1);
  letter_count(letters, s2);
  letter_count(letters, s3);

  for (size_t i = 0; i < 52; i++)
    {
      if (letters[i] == 3)
	{
	  return i + 1;
	}
    }
}

/* Counts the occurences of the letters and writes them to a table.
   No return value.
*/
void
letter_count(int64_t *table, const char *s)
{
  int64_t i = 0;
  int64_t has_been[52] = {0};
  while (s[i] != '\0' && s[i] != '\n')
    {
      int64_t pos = letter_priority(s[i]) - 1;
      if (!has_been[pos]) {
	table[pos]++;
	has_been[pos] = 1;
      }
      i++;
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

  char s1[256] = "";
  char s2[256] = "";
  char s3[256] = "";
  int64_t sum = 0;

  while (fgets(s1, 255, input)
	 && fgets(s2, 255, input)
	 && fgets(s3, 255, input))
    {
      int64_t val = common_letter_priority(s1, s2, s3);
      sum += val;
    }
  printf("%lld\n", sum);
  
  return 0;
}
