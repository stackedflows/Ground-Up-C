#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dislin.h"

#define STEPS 10000

long double julia_x(long double x, long double y){
  return x*x - y*y;
}
long double julia_y(long double x, long double y){
  return 2*x*y + ;
}

long double _abs(long double x, long double y){
  return sqrt((x * x) + (y * y));
}

void plot_j(float * x, float * y){
  scrmod ("revers");
  setpag ("da4l");
  metafl ("cons");
  disini ();
  pagera ();

  titlin ("Julia Set", 1);
  titlin ("Z = Z*Z - 0.8 + 0.156i", 3);

  name   ("R-axis", "x");
  name   ("I-axis", "y");

  graf(-100.0, 100.0, -100.0, 10, -100.0, 10, -100.0, 100.0);

  qplsca(x, y, STEPS);
}

int main(void){

  //generate jula set data for particular constant
  static long double const_x = -0.8;
  static long double const_y = 0.156;

  long double radius = _abs(const_x, const_y);

  static long double r_lim = 1.5320213176092827; //solves r_lim(r_lim - 1) = radius

  long double * julia_element_x = malloc(STEPS * sizeof(long double));
  long double * julia_element_y = malloc(STEPS * sizeof(long double));
  julia_element_x[0] = 0.0;
  julia_element_y[0] = 0.0;

  for(int i = 0; i < STEPS; i++){
    if(_abs(julia_element_x[i], julia_element_y[i]) > r_lim){
      break;
    }
    else{
      long double next_x = julia_x(julia_element_x[i], julia_element_y[i]);
      long double next_y = julia_y(julia_element_x[i], julia_element_y[i]);
      julia_element_x[i + 1] = next_x + const_x;
      julia_element_y[i + 1] = next_y + const_y;

    }
  }

  //plot results
  //plot_j((float *)julia_element_x, (float *)julia_element_x);

  free(julia_element_x);
  free(julia_element_y);

  return 0;
}
