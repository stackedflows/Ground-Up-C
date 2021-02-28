#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dislin.h"

static long double constant_x;
static long double constant_y;
static long double r_limit;

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
  long double current_iteration_x = (long double)x;
  long double current_iteration_y = (long double)y;
  int i = 0;
  while(i < max_steps && _abs(current_iteration_x, current_iteration_y) < r_limit){
    long double x_temporary = julia_x(current_iteration_x, current_iteration_y);
    current_iteration_y = julia_y(current_iteration_x, current_iteration_y) + constant_y;
    current_iteration_x = x_temporary + constant_x;
    i++;
  }
  return i;
}

int main(void){

  constant_x =  -0.61803398875;
  constant_y = 0.0;
  long double radius = _abs(constant_x, constant_y);
  r_limit = 2.0;

  static int julia_limit = 1000;

  int POINTS = 10000;
  long double scale = 0.04;

  float * julia_set_x = malloc(POINTS * sizeof(float));
  float * julia_set_y = malloc(POINTS * sizeof(float));

  int current_x = 0;
  int count = 0;
  for(int i = 0; i < POINTS; i++){
    if(i % 100 == 0){
      current_x++;
    }

    float _x = (float)(-2.0 + current_x * scale);
    float _y = (float)(-2.0 + (i % 100) * scale);

    if(julia_element(_x, _y, julia_limit) == julia_limit){
      julia_set_x[i] = _x;
      julia_set_y[i] = _y;
      count++;
    }else{
      julia_set_x[i] = 0.0;
      julia_set_y[i] = 0.0;
    }
  }

  scrmod("revers");
  setpag("da4l");
  metafl("cons");
  disini();

  titlin("Mandlebrot", 1);
  titlin("F(Z) = Z*Z - phi", 3);

  name("R-axis", "x");
  name("I-axis", "y");

  marker(21);
  hsymbl(20);

  qplsca(julia_set_x, julia_set_y, 6 * count);

  free(julia_set_x);
  free(julia_set_y);
  return 0;
}
