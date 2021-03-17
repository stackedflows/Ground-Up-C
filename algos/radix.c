#include <stdio.h>
#include <stdlib.h>

#define SIZEQ 10
#define SIZEL 10

int ** queues;

int * bubble(int * queue, int new_item){
  for(int i = 0; i < SIZEL; i++){
    int temp;
    if(new_item < queue[i]){
      temp = queue[i];
      queue[i] = new_item;
      for(int ii = 0; ii < i; ii++){
        queue[SIZEL - ii] = queue[SIZEL - ii - 1];
      }
    }else{
      queue[SIZEL] = new_item;
    }
  }
  return queue;
}

int max_digits(int num){
  int count = 0;
  float num_f = (float)num;
  while (num_f > 1) {
    count++;
    num_f = num_f / 10.0;
  }
  return count;
}

int get_max(int * unsorted){
  int max = unsorted[0];
  for(int i = 0; i < SIZEL; i++){
    int digits = max_digits(unsorted[i]);
    if(digits < max){
      current_max = digits;
    }
  }
  return max;
}

int main(void){
  int * to_sort = malloc(SIZEL * sizeof(int));
  int num_digits = get_max(to_sort);


  return 0;
}
