//gcc linked_list.c -o ll

#include <stdio.h>
#include <stdlib.h>

#define LL_SIZE 10

struct node{
  struct node *prev_node;
  struct node *nxt_node;
  int data;
};

int main(){
  struct node * ll = malloc(LL_SIZE * sizeof(struct node));

  for(int i = 0; i < LL_SIZE; i++){
    struct node item = {NULL, NULL, i};
    ll[i] = item;
  }

  for(int i = 0; i < LL_SIZE; i++){
    if(i == 0){
      ll[i].prev_node = NULL;
      ll[i].nxt_node = &ll[i + 1];
    }
    else if(i > 0 && i < LL_SIZE - 2){
      ll[i].prev_node = &ll[i - 1];
      ll[i].nxt_node = &ll[i + 1];
    }
    else{
      ll[i].prev_node = &ll[i - 1];
      ll[i].nxt_node = NULL;
    }
  }

  return 0;
}
