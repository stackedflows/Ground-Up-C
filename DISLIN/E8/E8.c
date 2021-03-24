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
          printf("%f ", base[i]);
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

void combine(int lower, int higher, float system_in[][8], float system_out[][8]){
  for(int i = lower; i < higher; i++){
    for(int ii = 0; ii < 8; ii++){
      system_out[i][ii] = system_in[i][ii];
    }
  }
}

// function to list all distances from one node to others

float inner_product(float * vector_0, float * vector_1){
  int i = 7;
  float sum = 0;
  while(i != -1){
    sum = sum + (vector_0[i] - vector_1[i]) * (vector_0[i] - vector_1[i]);
    i--;
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
  float type_b1[28][8];
  permutations(b1, 0, 8, type_b1);
  printf("\n");
  
  count = 0;
  float b2[8] = {1,-1,0,0,0,0,0,0};
  float type_b2[56][8];
  permutations(b2, 0, 8, type_b2);
  printf("\n");

  count = 0;
  float b3[8] = {-1,-1,0,0,0,0,0,0};
  float type_b3[28][8];
  permutations(b3, 0, 8, type_b3);
  printf("\n");

  count = 0;
  float b4[8] = {0.5,0.5,-0.5,-0.5,-0.5,-0.5,-0.5,-0.5};
  float type_b4[28][8];
  permutations(b4, 0, 8, type_b4);
  printf("\n");

  count = 0;
  float b5[8] = {0.5,0.5,0.5,0.5,-0.5,-0.5,-0.5,-0.5};
  float type_b5[70][8];
  permutations(b5, 0, 8, type_b5);
  printf("\n");

  count = 0;
  float b6[8] = {0.5,0.5,0.5,0.5,0.5,0.5,-0.5,-0.5};
  float type_b6[28][8];
  permutations(b6, 0, 8, type_b6);
  printf("\n");

  float type_b7[8] = {0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5};
  float type_b8[8] = {-0.5,-0.5,-0.5,-0.5,-0.5,-0.5,-0.5,-0.5};

  //combine above into single matrix

  float root_system[240][8];

  combine(0, 28, type_b1, root_system);
  combine(28, 84, type_b2, root_system);
  combine(84, 112, type_b3, root_system);
  combine(112, 140, type_b4, root_system);
  combine(140, 210, type_b5, root_system);
  combine(210, 238, type_b6, root_system);
  for(int i = 0; i < 8; i++){
    root_system[238][i] = type_b7[i];
    root_system[239][i] = type_b8[i];
  }

  //

  float * current_distances = malloc(240 * sizeof(float));

  for(int i = 0; i < 240; i++){
    current_distances[i] = inner_product(root_system[0], root_system[i]);
  }

  return 0;
}
