//gcc linked_list.c -o ll

#include <stdio.h>
#include <stdlib.h>

#define LL_SIZE 10

struct node{
  struct node *prev_node;
  struct node *nxt_node;
  int data;
};

struct node * linked_list;

int main(){

  linked_list = malloc(LL_SIZE * sizeof(struct node));

  for(int i = 0; i < LL_SIZE; i++){
    struct node item = {NULL, NULL, i};
    linked_list[i] = item;
  }

  for(int i = 0; i < LL_SIZE; i++){
    if(i == 0){
      linked_list[i].prev_node = NULL;
      linked_list[i].nxt_node = &linked_list[i + 1];
    }
    else if(i > 0 && i < LL_SIZE - 2){
      linked_list[i].prev_node = &linked_list[i - 1];
      linked_list[i].nxt_node = &linked_list[i + 1];
    }
    else{
      linked_list[i].prev_node = &linked_list[i - 1];
      linked_list[i].nxt_node = NULL;
    }
  }

  free(linked_list);

  return 0;
}
