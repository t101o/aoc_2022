#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int64_t action_score(const char c)
{
  switch (c) {
  case 'A':
  case 'X':
    return 1;
    break;
  case 'B':
  case 'Y':
    return 2;
    break;
  case 'C':
  case 'Z':
    return 3;
    break;
  default:
    return 0;
    break;
  }
}

int64_t round_score(const char c1, const char c2)
{
  int64_t sum = 0;
  int64_t c1_score = action_score(c1);
  int64_t c2_score = action_score(c2);
  if (c2_score % 3 == c1_score - 1) {
    sum += 0;
  } else if (c1_score == c2_score) {
    sum += 3;
  } else {
    sum += 6;
  }

  return sum + c2_score;
}

int main(void)
{
  FILE *input = fopen("input.txt", "r");
  if (!input) {
    exit(EXIT_FAILURE);
  }
  int64_t score = 0;
  char c1 = ' ';
  char c2 = ' ';
  char c;

  while ((c = fgetc(input)) != EOF) {
    
    if (c == '\n' && c1 != ' ' && c2 != ' ') {  
      score += round_score(c1, c2);
      c1 = ' ';
      c2 = ' ';
    } else if (c1 == ' ') {
      c1 = c;
    } else if (c2 == ' ') {
      c2 = c;
    }
  }

  printf("%lld\n", score);
  return 0;
}
