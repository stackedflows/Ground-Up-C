#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dislin.h"

#define steps 1e6

long double julia_x(long double x, long double y){
  return x*x - y*y;
}
long double julia_y(long double x, long double y){
  return 2*x*y;
}

long double _abs(long double x, long double y){
  return sqrt(x * x + y * y);
}

int main(void){

  //generate jula set data for particular constant
  static long double const_x = -0.8;
  static long double const_y = 0.156;

  long double radius = _abs(const_x, const_y);

  static long double r_lim = 1.5320213176092827; //solves r_lim(r_lim - 1) = radius

  long double ** julia_set = malloc(steps * sizeof(long double *));
  long double * julia_element = malloc(2 * sizeof(long double));

  long double current_x = 0.0;
  long double current_y = 0.0;
  for(int i = 0; i < (int)steps; i++){
    if(_abs(current_x, current_y) > r_lim){
      break;
    }
    else{
      long double julia_i_x = julia_x(current_x, current_y);
      current_x = julia_i_x + const_x;
      julia_element[0] = current_x;

      long double julia_i_y = julia_y(current_x, current_y);
      current_y = julia_i_y + const_y;
      julia_element[1] = current_y;

      julia_set[i] = julia_element;
    }
    printf("%d\n", i);
  }

  //graph julia set
  disini();
  messag("test", 10, 10);
  disfin();

  free(julia_set);
  free(julia_element);

  return 0;
}
