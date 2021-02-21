#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dislin.h"

#define J_STEPS 10

//generate jula set data for particular constant
static long double const_x;
static long double const_y;
long double * r_lim;

long double julia_x(long double x, long double y){
  return x * x - y * y;
}
long double julia_y(long double x, long double y){
  return 2 * x * y;
}

long double _abs(long double x, long double y){
  return sqrt(x * x + y * y);
}

int julia_element(long double x, long double y){
  long double * julia_element_x = malloc(J_STEPS * sizeof(long double));
  long double * julia_element_y = malloc(J_STEPS * sizeof(long double));
  julia_element_x[0] = x;
  julia_element_y[0] = y;

  int iteration_count = 0;
  for(int i = 1; i < J_STEPS; i++){
    if(_abs(julia_element_x[i], julia_element_y[i]) > r_lim[0]){
      break;
    }
    else if(_abs(julia_element_x[i], julia_element_y[i]) < r_lim[1]){
      break;
    }
    else{
      long double next_x = julia_x(julia_element_x[i], julia_element_y[i]);
      long double next_y = julia_y(julia_element_x[i], julia_element_y[i]);
      julia_element_x[i] = next_x + const_x;
      julia_element_y[i] = next_y + const_y;
      iteration_count++;
    }
  }
  free(julia_element_x);
  free(julia_element_y);
  return iteration_count;
}

int main(void){

  //constants
  const_x = -0.8;
  const_y = 0.156;
  long double radius = _abs(const_x, const_y);
  r_lim = malloc(2 * sizeof(long double));
  r_lim[0] = 1.5320213637808087; //solves r_lim(r_lim - 1) = radius
  r_lim[1] = -0.5320213637808087;

  //1000 points on the contour
  int POINTS = 1000;

  long double * julia_set_x = malloc(POINTS * sizeof(long double));
  long double * julia_set_y = malloc(POINTS * sizeof(long double));

  long double init_x = -1.5;
  long double init_y = -1.5;
  long double step = 0.003;
  int count = 0;
  for(int x = 0; x < POINTS; x++){
    init_x = (long double)(init_x + step);
    init_y = -1.5;
    for(int y = 0; y < POINTS; y++){
      init_y = (long double)(init_y + step);
      int current_julia = julia_element(init_x, init_y);
      if(current_julia < 10 && count < POINTS){
        julia_set_x[count] = init_x;
        julia_set_y[count] = init_y;
      }
    }
    count++;
  }

  scrmod("revers");
  setpag("da4l");
  metafl("cons");
  disini();
  pagera();

  titlin("Julia Set", 1);
  titlin("F(Z) = Z*Z - 0.8 + 0.156i", 3);

  name("R-axis", "x");
  name("I-axis", "y");

  qplsca(julia_set_x, julia_set_y, POINTS);

  free(julia_set_x);
  free(julia_set_y);

  return 0;
}
