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

void permutations(float base[], int index, int n, float target[][8])
{
    if (index >= n) {
        for(int i = 0; i < n; i++){
          target[count][i] = base[i];
          //printf("%f ", base[i]);
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
            permutations(base, index + 1, n, target);
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

  float root_system[240][8];

  // base vector permutations of E8 root system

  count = 0;
  float b1[8] = {1,1,0,0,0,0,0,0};
  float type_b1[28][8];
  permutations(b1, 0, 8, type_b1);
  for(int i = 0; i < 28; i++){
    for(int ii = 0; ii < 8; ii++){
        printf("%f ", type_b1[i][ii]);
      }
      printf("\n");
  }
  printf("\n");

  count = 0;
  float b2[8] = {1,-1,0,0,0,0,0,0};
  float type_b2[56][8];
  permutations(b2, 0, 8, type_b2);
  for(int i = 28; i < 84; i++){
    for(int ii = 0; ii < 8; ii++){
        printf("%f ", type_b2[i][ii]);
      }
      printf("\n");
  }
  printf("\n");

  count = 0;
  float b3[8] = {-1,-1,0,0,0,0,0,0};
  float type_b3[28][8];
  permutations(b3, 0, 8, type_b3);
    for(int i = 84; i < 112; i++){
      for(int ii = 0; ii < 8; ii++){
        printf("%f ", type_b3[i][ii]);
      }
      printf("\n");
  }
  printf("\n");

  count = 0;
  float b4[8] = {0.5,0.5,-0.5,-0.5,-0.5,-0.5,-0.5,-0.5};
  float type_b4[28][8];
  permutations(b4, 0, 8, type_b4);
  for(int i = 112; i < 140; i++){
    for(int ii = 0; ii < 8; ii++){
        printf("%f ", type_b4[i][ii]);
      }
      printf("\n");
  }
  printf("\n");

  count = 0;
  float b5[8] = {0.5,0.5,0.5,0.5,-0.5,-0.5,-0.5,-0.5};
  float type_b5[70][8];
  permutations(b5, 0, 8, type_b5);
  for(int i = 140; i < 210; i++){
    for(int ii = 0; ii < 8; ii++){
      printf("%f ", type_b5[i][ii]);
    }
    printf("\n");
  }
  printf("\n");

  count = 0;
  float b6[8] = {0.5,0.5,0.5,0.5,0.5,0.5,-0.5,-0.5};
  float type_b6[28][8];
  permutations(b6, 0, 8, type_b6);
  for(int i = 210; i < 238; i++){
    for(int ii = 0; ii < 8; ii++){
      printf("%f ", type_b6[i][ii]);
    }
    printf("\n");
  }
  printf("\n");

  float type_b7[8] = {0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5};
  float type_b8[8] = {-0.5,-0.5,-0.5,-0.5,-0.5,-0.5,-0.5,-0.5};


  for(int i = 0; i < 8; i++){
    root_system[238][i] = type_b7[i];
    root_system[239][i] = type_b8[i];
  }

  printf("test\n");

  for(int i = 0; i < 240; i++){
    if(i == 28)printf("\n");
    if(i == 84)printf("\n");
    if(i == 112)printf("\n");
    if(i == 140)printf("\n");
    if(i == 210)printf("\n");
    if(i == 238)printf("\n");
    if(i == 239)printf("\n");
    for(int ii = 0; ii < 8; ii++){
      //printf("%f ", root_system[i][ii]);
    }
    printf("\n");
  }

  printf("end\n");
  //

  printf("\n");

  //gcc combo.c -o c

  printf("\n");

  int distance_matrix[240][240];

  for(int i = 0; i < 240; i++){
    for(int ii = 0; ii < 240; ii++){
      float dist = (int)inner_product(root_system[i], root_system[ii]);
      if(dist == 2){
        distance_matrix[i][ii] = 1;
      }else{distance_matrix[i][ii] == 0;};
    }
  }

  printf("\n");

  printf("\n");

  printf("\n");

  printf("\n");

  return 0;
}
