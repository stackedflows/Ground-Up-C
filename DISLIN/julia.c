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

  int count = 0;
  for(int i = 0; i < J_STEPS; i++){
    if(_abs(julia_element_x[i], julia_element_y[i]) > r_lim[0]){
      break;
    }
    else if(_abs(julia_element_x[i], julia_element_y[i]) < r_lim[1]){
      break;
    }
    else{
      long double next_x = julia_x(julia_element_x[i], julia_element_y[i]);
      long double next_y = julia_y(julia_element_x[i], julia_element_y[i]);
      julia_element_x[i + 1] = next_x + const_x;
      julia_element_y[i + 1] = next_y + const_y;
    }
    count = i;
  }
  return count;
}

void plot_j(float * x, float * y, int points){
  scrmod ("revers");
  setpag ("da4l");
  metafl ("cons");
  disini ();
  pagera ();

  titlin ("Julia Set", 1);
  titlin ("Z = Z*Z - 0.8 + 0.156i", 3);

  name   ("R-axis", "x");
  name   ("I-axis", "y");

  graf(-1.5, 1.5, -1.5, 0.5, -1.5, 1.5, -1.5, 0.5);
  qplsca(x, y, J_STEPS * 2);
}

int main(void){
  //constants
  const_x = -0.8;
  const_y = 0.156;
  long double radius = _abs(const_x, const_y);
  r_lim = malloc(2 * sizeof(long double));
  r_lim[0] = 1.5320213637808087; //solves r_lim(r_lim - 1) = radius
  r_lim[1] = -0.5320213637808087;

  //plot contour of julia set
  long double * julia_set_x = malloc(100 * sizeof(long double));
  long double * julia_set_y = malloc(100 * sizeof(long double));
  julia_set_x[0] = 0.0;
  julia_set_y[0] = 0.0;

  for(int x = 0; x < 1000; x++){
    for(int y = 0; y < 1000; y++){

      if(julia_element(julia_set_x[x], julia_set_y[y] < 10)){

        count = count + 1;
      }
    }
  }

  plot_j(x, y, 100);

  //plot results
  //plot_j((float *)julia_element_x, (float *)julia_element_x);

  return 0;
}
