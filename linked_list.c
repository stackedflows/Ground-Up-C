//gcc linked_list.c -o ll

#include <stdio.h>
#include <stdlib.h>

#define LL_SIZE 10

struct node{
  struct node *next_node;
  struct node *prev_node;
  int data;
};

struct node * head = NULL;

void insert(int data){
  struct node * temp;
  temp = (struct node *)malloc(sizeof(struct node));
  temp -> data = data;

  if(head == NULL){
    head = temp;
    head -> next_node = NULL;
  }

  temp -> next_node = head;
  head -> prev_node = temp -> next_node;

  head = temp;
}

int main(){

  insert(6);
  insert(4);
  insert(3);

  printf("%d\n", head -> data);
  printf("%d\n", head -> next_node -> data);
  printf("%d\n", head -> next_node -> prev_node -> data);

  return 0;
}
