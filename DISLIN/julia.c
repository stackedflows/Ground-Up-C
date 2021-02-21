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

int main(void){
  //constants
  const_x = -0.8;
  const_y = 0.156;
  long double radius = _abs(const_x, const_y);
  r_lim = malloc(2 * sizeof(long double));
  r_lim[0] = 1.5320213637808087; //solves r_lim(r_lim - 1) = radius
  r_lim[1] = -0.5320213637808087;

  //1000 points on the contour
  static int POINTS = 1000;

  float * julia_set_x = malloc(POINTS * sizeof(float));
  float * julia_set_y = malloc(POINTS * sizeof(float));

  //plot julia contour between -1.5, 1.5
  int count = 0;
  long double temp_x = -1.5;
  for(int x = 0; x < POINTS; x++){
    temp_x = temp_x + 0.001;
    long double temp_y = -1.5;
    for(int y = 0; y < POINTS; y++){
      temp_y = temp_y + 0.001;
      if(julia_element(temp_x, temp_y) < 10){
        julia_set_x[count] = (float)temp_x;
        julia_set_y[count] = (float)temp_y;
        count = count + 1;
        printf("%f\n", julia_set_x[count]);
      }
    }
  }

  for(int i = 0; i < POINTS; i++){
    printf("x: %f, y: %f\n", julia_set_x[i], julia_set_y[i]);
  }

  scrmod ("revers");
  setpag ("da4l");
  metafl ("cons");
  disini ();
  pagera ();

  titlin ("Julia Set", 1);
  titlin ("F(Z) = Z*Z - 0.8 + 0.156i", 3);

  name   ("R-axis", "x");
  name   ("I-axis", "y");


  qplsca(julia_set_x, julia_set_y, POINTS);

  return 0;
}
