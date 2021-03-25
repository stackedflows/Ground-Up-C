//gcc combo.c -o c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// method to generate all permutations of a set with repeated elements

int count = 0;

int shouldSwap(float base[], int start, int curr)
{
    for (int i = start; i < curr; i++)
        if (base[i] == base[curr])
            return 0;
    return 1;
}

float root_sys[240][8];

void permutations(float base[], int index, int n)
{
    if (index >= n) {
        for(int i = 0; i < n; i++){
          root_sys[count][i] = base[i];
        }
        count++;
        printf("\n");
        return;
    }

    for (int i = index; i < n; i++) {
        int check = shouldSwap(base, index, i);
        if (check) {
            float temp_0 = base[index];
            float temp_1 = base[i];
            base[index] = temp_1;
            base[i] = temp_0;
            permutations(base, index + 1, n);
            float temp_2 = base[index];
            float temp_3 = base[i];
            base[index] = temp_3;
            base[i] = temp_2;
        }
    }
}

// function to list all distances from one node to others

float inner_product(float * vect_0, float * vect_1){
  float sum = 0;
  for(int i = 0; i < 8; i++){
    sum = sum + ((vect_0[i] - vect_1[i]) * (vect_0[i] - vect_1[i]));
  }return sum;
}

float min(float * array){
    float curr = 100;
    for(int i = 0; i < 240; i++){
      if(array[i] < curr && array[i] != 0){
        curr = array[i];
      }
    }return curr;
}

//

void print_p(float arr[][8], int size){
  for(int i = 0; i < size; i++){
    for(int ii = 0; ii < 8; ii++){
      printf("%f ", arr[i][ii]);
    }
    printf("\n");
  }
}

int main(void){

  // base vector permutations of E8 root system

  count = 0;
  float b1[8] = {1,1,0,0,0,0,0,0};
  permutations(b1, 0, 8);

  float b2[8] = {1,-1,0,0,0,0,0,0};
  permutations(b2, 0, 8);

  float b3[8] = {-1,-1,0,0,0,0,0,0};
  permutations(b3, 0, 8);

  float b4[8] = {0.5,0.5,-0.5,-0.5,-0.5,-0.5,-0.5,-0.5};
  permutations(b4, 0, 8);

  float b5[8] = {0.5,0.5,0.5,0.5,-0.5,-0.5,-0.5,-0.5};
  permutations(b5, 0, 8);

  float b6[8] = {0.5,0.5,0.5,0.5,0.5,0.5,-0.5,-0.5};
  permutations(b6, 0, 8);

  float b7[8] = {0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5};
  float b8[8] = {-0.5,-0.5,-0.5,-0.5,-0.5,-0.5,-0.5,-0.5};

  for(int i = 0; i < 8; i++){
    root_sys[238][i] = b7[i];
    root_sys[239][i] = b8[i];
  }

  printf("\n");

  //gcc combo.c -o c

  printf("\n");

  int distance_matrix[240][240];

  for(int i = 0; i < 240; i++){
    int c_count = 0;
    int dist_m = 100;
    for(int ii = 0; ii < 240; ii++){
      float dist = (int)inner_product(root_sys[i], root_sys[ii]);
      if(dist == 2){
        distance_matrix[i][ii] = 1;
        c_count++;
      }else{distance_matrix[i][ii] == 0;};
    }
  }

  return 0;
}
