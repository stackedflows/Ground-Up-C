#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dislin.h"

#define PI acos(-1.0)
#define OFFSET PI/30

float * distances;
float * rings_x;
float * rings_y;

int main(void){

  scrmod("revers");
  setpag("da4l");
  metafl("cons");
  disini();

  graf(-10, 10, -10, 1, -10, 10, -10, 1);

  distances = malloc(8 * sizeof(float));
  for(int i = 0; i < 8; i++){
    distances[i] = (float)(i + 1);
  }

  rings_x = malloc(30 * 8 * sizeof(float));
  rings_y = malloc(30 * 8 * sizeof(float));
  for(int i = 0; i < 30 * 8; i++){
    if(i < 30){
      rings_x[i] = distances[0] * cos(PI / 15 * i);
      rings_y[i] = distances[0] * sin(PI / 15 * i);
      if(i > 0)rline(rings_x[i - 1], rings_y[i - 1], rings_x[i], rings_y[i]);
    }else if(i >= 30 && i < 2 * 30){
      rings_x[i] = distances[1] * cos(PI / 15 * (i % 30) + OFFSET);
      rings_y[i] = distances[1] * sin(PI / 15 * (i % 30) + OFFSET);
      if(i >= 31)rline(rings_x[i - 1], rings_y[i - 1], rings_x[i], rings_y[i]);
    }else if(i >= 2 * 30 && i < 3 * 30){
      rings_x[i] = distances[2] * cos(PI / 15 * (i % 30));
      rings_y[i] = distances[2] * sin(PI / 15 * (i % 30));
      if(i >= 61)rline(rings_x[i - 1], rings_y[i - 1], rings_x[i], rings_y[i]);
    }else if(i >= 3 * 30 && i < 4 * 30){
      rings_x[i] = distances[3] * cos(PI / 15 * (i % 30) + OFFSET);
      rings_y[i] = distances[3] * sin(PI / 15 * (i % 30) + OFFSET);
      if(i >= 91)rline(rings_x[i - 1], rings_y[i - 1], rings_x[i], rings_y[i]);
    }else if(i >= 4 * 30 && i < 5 * 30){
      rings_x[i] = distances[4] * cos(PI / 15 * (i % 30));
      rings_y[i] = distances[4] * sin(PI / 15 * (i % 30));
      if(i >= 121)rline(rings_x[i - 1], rings_y[i - 1], rings_x[i], rings_y[i]);
    }else if(i >= 5 * 30 && i < 6 * 30){
      rings_x[i] = distances[5] * cos(PI / 15 * (i % 30) + OFFSET);
      rings_y[i] = distances[5] * sin(PI / 15 * (i % 30) + OFFSET);
      if(i >= 151)rline(rings_x[i - 1], rings_y[i - 1], rings_x[i], rings_y[i]);
    }else if(i >= 6 * 30 && i < 7 * 30){
      rings_x[i] = distances[6] * cos(PI / 15 * (i % 30));
      rings_y[i] = distances[6] * sin(PI / 15 * (i % 30));
      if(i >= 181)rline(rings_x[i - 1], rings_y[i - 1], rings_x[i], rings_y[i]);
    }else{
      rings_x[i] = distances[7] * cos(PI / 15 * (i % 30) + OFFSET);
      rings_y[i] = distances[7] * sin(PI / 15 * (i % 30) + OFFSET);
      if(i >= 211)rline(rings_x[i - 1], rings_y[i - 1], rings_x[i], rings_y[i]);
    }
  }

  titlin("E8", 1);

  name("R-axis", "x");
  name("I-axis", "y");

  marker(21);
  hsymbl(15);

  qplsca(rings_x, rings_y, 30 * 8);

  return 0;
}
