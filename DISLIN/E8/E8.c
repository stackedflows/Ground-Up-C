// to run
//  clink -c Ex8
// ./e8
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dislin.h"

// method to generate all permutations of a set with repeated elements: the root system
float root_sys[240][8];

int count = 0;

int shouldSwap(float base[], int start, int curr)
{
    for (int i = start; i < curr; i++)
        if (base[i] == base[curr])
            return 0;
    return 1;
}

void permutations(float base[], int index, int n)
{
    if (index >= n) {
        for(int i = 0; i < n; i++){
          root_sys[count][i] = base[i];
        }
        count++;
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

float inner_product_plus(float * vect_0, float * vect_1){
  float sum = 0;
  for(int i = 0; i < 8; i++){
    sum = sum + (vect_0[i] * vect_1[i]);
  }return sum;
}

//

int main(void){

  // base vector permutations of E8 root system

  float base_sys[8][8] = {
    {1,1,0,0,0,0,0,0},
    {1,-1,0,0,0,0,0,0},
    {-1,-1,0,0,0,0,0,0},
    {0.5,0.5,-0.5,-0.5,-0.5,-0.5,-0.5,-0.5},
    {0.5,0.5,0.5,0.5,-0.5,-0.5,-0.5,-0.5},
    {0.5,0.5,0.5,0.5,0.5,0.5,-0.5,-0.5},
    {0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5},
    {-0.5,-0.5,-0.5,-0.5,-0.5,-0.5,-0.5,-0.5}
  };

  count = 0;

  for(int i = 0; i < 8; i++){
    permutations(base_sys[i],0,8);
  }

  for(int i = 0; i < 240; i++){
    for(int ii = 0; ii < 8; ii++){
      printf("%f ", root_sys[i][ii]);
    }
    printf("\n");
  }

 //calculating distances between all roots, outputting correspondence matrix

  int distance_matrix[240][240];
  for(int i = 0; i < 240; i++){
    int dist_m = 100;
    for(int ii = 0; ii < 240; ii++){
      float dist = inner_product(root_sys[i], root_sys[ii]);
      if(dist == 2){ //connecting distance in E8
        distance_matrix[i][ii] = 1;
      }else{distance_matrix[i][ii] == 0;};
    }
  }
  //use eig.py to calculate eigenvectors of root system

  //clink -c Ex8
  float re[8] = {};
  float im[8] = {};


  float rings_x[240];
  float rings_y[240];

  for(int i = 0; i < 240; i++){
    float current_point[8];
    for(int ii = 0; ii < 8; ii++){
      current_point[ii] = root_sys[i][ii];
    }
    rings_x[i] = inner_product_plus(current_point, re);
    rings_y[i] = inner_product_plus(current_point, im);
  }

  printf("\n");

  //graph the system

  scrmod("revers");
  setpag("da4l");
  metafl("cons");
  disini();

  graf(-2, 2, -2, 2, -2, 2, -2, 1);

  titlin("E8", 1);

  name("R-axis", "x");
  name("I-axis", "y");

  marker(21);
  hsymbl(15);

  qplsca(rings_x, rings_y, 240);

  return 0;
}

