//gcc generate.c -o g
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define DIM 8

void permute(float * array){
  
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

  return 0;
}
