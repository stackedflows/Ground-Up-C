/// to run ///
// clink -c E8
//./E8
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

  // conditions for base vectors of E8 root system
  // roots span eight dim space, 
  // linearly independent up untill -root
  // closed under reflection through perpendicular plane
  // if a,b are roots, then projection of b onto a is half integer or integer multiple of root
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

  // create root system from base system
  for(int i = 0; i < 8; i++){
    permutations(base_sys[i],0,8);
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

  //use eig.py to calculate eigenvectors of root system . . . after some fiddling, these vectors appear
  float re[8] = {0.438217070641, 0.205187681291,
     0.36459828198, 0.0124511903657,
     -0.0124511903657, -0.36459828198,
     -0.205187681291, -0.67645247517};

  float im[8] = {-0.118465163028, 0.404927414852,
    0.581970822973, 0.264896157496,
    0.501826483552, 0.345040496917,
    0.167997088796, 0.118465163028};

  //store locations of nodes in graph
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

  //graph the system
  scrmod("revers");
  setpag("da4l");
  metafl("cons");
  disini();

  graf(-1.2, 1.2, -1.2, 1.2, -1.2, 1.2, -1.2, 1);

  for(int i = 0; i < 240; i++){
    for(int ii = 0; ii < 240; ii++){
      int connect = distance_matrix[i][ii];
      if(connect == 1){
        rline(rings_x[i], rings_y[i], rings_x[ii], rings_y[ii]);
        distance_matrix[ii][i] = 0;
      }else{continue;}
    }
  }

  titlin("E8", 1);

  name("R-axis", "x");
  name("I-axis", "y");

  marker(21);
  hsymbl(15);

  qplsca(rings_x, rings_y, 240);

  return 0;
}
