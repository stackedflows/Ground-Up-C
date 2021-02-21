#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dislin.h"

#define steps 100

long double julia_x(long double x, long double y){
  return x*x - y*y;
}
long double julia_y(long double x, long double y){
  return 2*x*y;
}

long double _abs(long double x, long double y){
  return sqrt((x * x) + (y * y));
}

int main(void){

  //generate jula set data for particular constant
  static long double const_x = -0.8;
  static long double const_y = 0.156;

  long double radius = _abs(const_x, const_y);

  static long double r_lim = 1.5320213176092827; //solves r_lim(r_lim - 1) = radius

  long double * julia_element_x = malloc(steps * sizeof(long double));
  long double * julia_element_y = malloc(steps * sizeof(long double));
  julia_element_x[0] = 0.0;
  julia_element_y[0] = 0.0;

  //generate julia set
  for(int i = 0; i < (int)steps; i++){
    if(_abs(julia_element_x[i], julia_element_y[i]) > r_lim){
      break;
    }
    else{
      long double next_x = julia_x(julia_element_x[i], julia_element_y[i]);
      long double next_y = julia_y(julia_element_x[i], julia_element_y[i]);
      julia_element_x[i + 1] = next_x + const_x;
      julia_element_y[i + 1] = next_y + const_y;

      printf("%Lf ; %Lf ;%d\n", next_x, next_y, i);
    }
  }

  free(julia_element_x);
  free(julia_element_y);

  return 0;
}

void plot(float * x, float * y){
  scrmod ("revers");
  setpag ("da4l");
  metafl ("cons");
  disini ();
  pagera ();

  titlin ("Julia Set", 1);
  titlin ("Z = Z*Z - 0.8 + 0.156i", 3);

  name   ("R-axis", "x");
  name   ("I-axis", "y");

  graf(-5.0, 5.0, -5.0, 1.0, -5.0, 5.0, -5.0, 1.0);

  qplsca(x, y, (int)steps * 2);
  disfin();
}
