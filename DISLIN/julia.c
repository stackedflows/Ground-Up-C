#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include "dislin.h"

long double julia_x(long double x, long double y){
  return x*x - y*y;
}
long double julia_y(long double x, long double y){
  return 2*x*y;
}

void main(){

  long double radius;

  long double const_x = -0.8;
  long double const_y = 0.156;

  radius = sqrt(const_y * const_y + const_x * const_x);


  //disini();
  //messag("test", 10, 10);
  //disfin();

  printf("%f\n", (double)radius);
}
