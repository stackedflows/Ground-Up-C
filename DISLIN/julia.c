#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dislin.h"

//generate jula set data for particular constant
static long double const_x;
static long double const_y;
static long double r_lim;

long double julia_x(long double x, long double y){
  return x * x - y * y;
}
long double julia_y(long double x, long double y){
  return 2 * x * y;
}

long double _abs(long double x, long double y){
  return sqrt(x * x + y * y);
}

int julia_element(float x, float y, int max_steps){
  long double iter_x = (long double)x;
  long double iter_y = (long double)y;
  int i = 0;
  while(i < max_steps && _abs(iter_x, iter_y) < r_lim){
    long double x_temp = julia_x(iter_x, iter_y);
    iter_y = julia_y(iter_x, iter_y) + const_y;
    iter_x = x_temp + const_x;
    i++;
  }
  return i;
}

int main(void){
  //constants
  const_x = -0.61803398875; //1 - golden ratio
  const_y = 0.0;
  long double radius = _abs(const_x, const_y);
  r_lim = 2; //solves r_lim(r_lim - 1) = radius

  static int julia_lim = 1000;

  //establish grid and scale factor
  int POINTS = 10000;
  long double scale = 0.04;

  //generate julia subset of grid
  float * julia_set_x = malloc(POINTS * sizeof(float));
  float * julia_set_y = malloc(POINTS * sizeof(float));

  int current_x = 0;
  int count = 0;
  for(int i = 0; i < POINTS; i++){
    if(i % 100 == 0){
      current_x++;
    }

    float _x = (float)(-2 + current_x * scale);
    float _y = (float)(-2 + (i % 100) * scale);

    if(julia_element(_x, _y, julia_lim) == julia_lim){
      julia_set_x[i] = _x;
      julia_set_y[i] = _y;
      count++;
    }else{
      julia_set_x[i] = 0.0;
      julia_set_y[i] = 0.0;
    }
  }

  //draw julia set
  scrmod("revers");
  setpag("da4l");
  metafl("cons");
  disini();

  titlin("Julia Set", 1);
  titlin("F(Z) = Z*Z - 0.61803398875", 3);

  name("R-axis", "x");
  name("I-axis", "y");

  qplsca(julia_set_x, julia_set_y, 6 * count);

  free(julia_set_x);
  free(julia_set_y);
  return 0;
}
