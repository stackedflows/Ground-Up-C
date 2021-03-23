//gcc functions.c -o f
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define DIM 8
#define BASE_SIZE 240

float ** base;

float inner_product(float * vector_0, float * vector_1){
  int i = DIM - 1;
  float sum = 0;
  while(i != -1){
    sum = sum + (vector_0[i] * vector_1[i]);
    i--;
  }return sum;
}

float * current_row;

void connections_row(float ** base, int index){
  float current_min_dist = 100;
  for(int i = 0; i < BASE_SIZE; i++){
    current_row[i] = 0; //clear current row
    if(i == index){continue;}
    else{
      float dist = inner_product(base[i], base[index]);
      if(dist < current_min_dist){current_min_dist = dist;}
    }
  }
  for(int i = 0; i < BASE_SIZE; i++){
    if(i == index){continue;}
    float dist = inner_product(base[i], base[index]);
    if(dist == current_min_dist){current_row[i] = 1;} // 1 => connection
  }
}

float ** connection_matrix;

int main(void){
  base = malloc(BASE_SIZE * sizeof(float *));
  current_row = malloc(BASE_SIZE * sizeof(float));
  connection_matrix = malloc(BASE_SIZE * BASE_SIZE * sizeof(float));

  for(int i = 0; i < BASE_SIZE; i++){
    connections_row(base, i);
    connection_matrix[i] = current_row;
  }
  return 0;
}
