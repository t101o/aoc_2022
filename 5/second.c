#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* Stack, which represents a stack of crates.
 */
struct stack
{
  char crate;
  struct stack *next;
};

/* Pops the first element off the stack.
   Returns a pointer to the first element.
*/
char
pop(struct stack **s)
{
  struct stack *t = *s;
  char c = t->crate;
  *s = (*s)->next;
  free(t);
  return c;
}

/* Push a crate onto the stack.
   Returns NULL if fails, otherwise the pointer to the first element.
*/
struct stack *
push(char crate, struct stack *s)
{
  struct stack *t = malloc(sizeof(struct stack));
  if (t == NULL) { return NULL; }
  t->crate = crate;
  t->next = s;
  s = t;
  return s;
}

/* Pushes a string of crates to the stack.
   Returns the top of the stack.
*/
struct stack *
push_string(const char *crate_string, struct stack *s)
{
  int64_t i = 0;
  while (crate_string[i] != '\0')
    {
      s = push(crate_string[i], s);
      i++;
    }
  return s;
}

void
move(const int64_t count, struct stack **from, struct stack **to)
{
  struct stack *last = NULL;
  struct stack *first = *from;
  for (int64_t i = 0; i < count; i++)
    {
      last = *from;
      *from = (*from)->next;
    }
  last->next = *to;
  *to = first;
}

int
main(void)
{
  FILE *input = fopen("input.txt", "r");
  if (!input) { exit(EXIT_FAILURE); }
  char s[100] = "";
  struct stack *stacks[9] = { NULL };
  /* Initialising stacks.*/  
  stacks[0] = push_string("VCDRZGBW", stacks[0]);
  stacks[1] = push_string("GWFCBSTV", stacks[1]);
  stacks[2] = push_string("CBSNW", stacks[2]);
  stacks[3] = push_string("QGMNJVCP", stacks[3]);
  stacks[4] = push_string("TSLFDHB", stacks[4]);
  stacks[5] = push_string("JVTWMN", stacks[5]);
  stacks[6] = push_string("PFLCSTG", stacks[6]);
  stacks[7] = push_string("BDZ", stacks[7]);
  stacks[8] = push_string("MNZW", stacks[8]);

  printf("%c\n", stacks[0]->crate);
  
  while (fgets(s, 99, input))
    {
      int64_t count = 0;
      int64_t from = 0;
      int64_t to = 0;
      sscanf(s, "%*s %lld %*s %lld %*s %lld ", &count, &from, &to);
      //      printf("Count: %lld\nFrom: %lld\tTo: %lld\n", count, from, to);

      move(count, stacks + from - 1, stacks + to - 1);
    }

  for (int64_t i = 0; i < 9; i++)
    {
      printf("%c", stacks[i]->crate);
    }
  printf("\n");
  
  return 0;
}
