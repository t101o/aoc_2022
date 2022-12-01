#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdint.h>

struct elf {
  int64_t calories;
};

struct node {
  struct elf *e;
  struct node *next;
  struct node *prev;
};
  
int main(void)
{
  FILE *f = fopen("input.txt", "r");
  struct node *list = NULL;
  int64_t sum = 0;
  if (f) {
    char s[100];
    while (fgets(s, sizeof s, f) != NULL) {
      if (strcmp(s, "\n") == 0) {
	// printf("%s\n", s);
	struct elf *e = malloc(sizeof(struct elf));
	e->calories = sum;
	if (!list) {
	  list = malloc(sizeof(struct node));
	  list->next = NULL;
	  list->prev = NULL;
	  list->e = e;
	} else {
	  list->next = malloc(sizeof(struct node));
	  struct node *current = list->next;
	  current->prev = list;
	  current->next = NULL;
	  current->e = e;
	  list = current;
	}
	sum = 0;
      } else {
	sum += atoi(s);
      }
    }
  }
  fclose(f);
  
  int64_t max = 0;
  while (list) {
    if (list->e->calories > max) {
      max = list->e->calories;
    }
    list = list->prev;
  }

  printf("%lld\n", max);
  
  return 0;
}
