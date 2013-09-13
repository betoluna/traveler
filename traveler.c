/* type a single string on a line containig a set of state abbreviations 
   separated by spaces, print them in order one per line, compute the 
   percentage of the US visited */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INPUTSIZE 256
#define STATES 50

struct node *insert(struct node *, char *);
void print(struct node *);
static float percent(int);

// a linked list node
struct node {
  char *value;
  struct node *next;
};
    
int main(int argc, char **argv) {
  char buf[INPUTSIZE]; // the incoming string from stdin
  
  printf("Enter the states you have visited:\n");
  char *p = fgets(buf, INPUTSIZE, stdin);
  char *s = strstr(buf, "\n");
  if(s == NULL) {
    printf("Invalid input. Maximum valid input is %d characters.\n", INPUTSIZE);

    return -1;
  }

  *s = '\0';
  struct node *head;

  s = strtok(buf, " ");
  while(s != NULL) {
    char *token = s; // current token in input
    head = insert(head, token); // insert token in sorted list
    s = strtok(NULL, " "); // locate the next token
  }

  print(head);

  return 0;
} // end main

// insert string --if it's not already there, into sorted list
struct node *insert(struct node *head, char *new_val) {
  // if list is empty 
  if(head == NULL) {
    head = malloc(sizeof(struct node)); // check for NULL after call to malloc
    head->value = new_val;
    head->next = NULL;
    return head;
  } 

  // if incoming val is less than val at head, insert at front.    
  if(strcmp(new_val, head->value) < 0) {
    struct node *new_head = malloc(sizeof(struct node));  //check for NULL afterward
    new_head->value = new_val;
    new_head->next = head;
    return new_head;
  }

  // must traverse list to find proper location to insert
  struct node *current = head;
  struct node *previous = NULL;
  // while new_val is greater than value pointed to by current
  while(current != NULL && strcmp(current->value, new_val) <= 0) {
    // Don't allow duplicates. If new_val is found, do nothing.
    if(strcmp(current->value, new_val) == 0)
      return;

    previous = current;
    current = current->next;
  }

  // insert when proper position found
  struct node *new_node = malloc(sizeof(struct node));
  new_node->value = new_val;
  new_node->next = current; // may or may not be NULL
  previous->next = new_node; // insert after previous
  
  return head;
} // END insert()

void print(struct node *head) {
  struct node *temp = head;
  int visited = 0;
  char c, *val;
  while(temp != NULL) {
    val = temp->value;
    while(*val) {
      c = *val;
      if(islower(c))
	c = toupper(c);
      putchar(c);
      *val++;
    }
    temp = temp->next;
    visited++;
    printf("\n");
  }
 
  printf("You have visited %.0f%% of the United States.\n", percent(visited));
}

static float percent(int visited) {
  return (float)visited / STATES * 100;
}

