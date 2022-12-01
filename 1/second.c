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
  
  int64_t max1 = 0;
  int64_t max2 = 0;
  int64_t max3 = 0;
  while (list) {
    if (list->e->calories > max1) {
      max3 = max2;
      max2 = max1;
      max1 = list->e->calories;
    } else if (list->e->calories > max2) {
      max3 = max2;
      max2 = list->e->calories;
    } else if (list->e->calories > max3) {
      max3 = list->e->calories;
    }
    list = list->prev;
  }

  printf("%lld\n", max1 + max2 + max3);
  
  return 0;
}
