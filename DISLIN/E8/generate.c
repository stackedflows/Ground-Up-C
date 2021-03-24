//gcc generate.c -o g
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define DIM 8

//heaps algorithm for total permutations
void heaps_permute(float * array, int size, int n){
  if(size == 1){
    for(int i = 0; i < n; i++){
      printf("%f ",array[i]);
    }
  }
  printf("\n");
  for(int i = 0; i < size; i++){
    heaps_permute(array, size - 1, n);
    if(size % 2 == 0){
      float temp_0 = array[0];
      float temp_1 = array[size - 1];
      array[0] = temp_1;
      array[size - 1] = temp_0;
    }else{
      float temp_2 = array[i];
      float temp_3 = array[size - 1];
      array[i] = temp_3;
      array[size - 1] = temp_2;
    }
  }
}

int main(void){

  float b1[DIM] = {2,2,0,0,0,0,0,0};
  float b2[DIM] = {2,-2,0,0,0,0,0,0};
  float b3[DIM] = {-2,-2,0,0,0,0,0,0};

  float ** type_b1 = malloc(28 * sizeof(float *));
  float ** type_b2 = malloc(56 * sizeof(float *));
  float ** type_b3 = malloc(56 * sizeof(float *));

  float b4[DIM] = {1,1,-1,-1,-1,-1,-1,-1};
  float b5[DIM] = {1,1,1,1,-1,-1,-1,-1};
  float b6[DIM] = {1,1,1,1,1,1,-1,-1};

  float ** type_b4 = malloc(28 * sizeof(float *));
  float ** type_b5 = malloc(56 * sizeof(float *));
  float ** type_b6 = malloc(28 * sizeof(float *));

  float b7[DIM] = {1,1,1,1,1,1,1,1};
  float b8[DIM] = {-1,-1,-1,-1,-1,-1,-1,-1};

  heaps_permute(b1, 8, 8);

  return 0;
}
