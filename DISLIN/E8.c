#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dislin.h"

#define PI acos(-1.0)
#define OFFSET PI/30

int main(void) {

    float* distances = malloc(8 * sizeof(float));
    for (int i = 0; i < 8; i++) {distances[i] = (float)(i + 1);}

    float* rings_x = malloc(30 * 8 * sizeof(float));
    float* rings_y = malloc(30 * 8 * sizeof(float));
    for (int i = 0; i < 30 * 8; i++) {
        if (i < 30) {
            rings_x[i] = distances[0] * cos(PI / 15 * i);
            rings_y[i] = distances[0] * sin(PI / 15 * i);}
        else if (i >= 30 && i < 2 * 30) {
            rings_x[i] = distances[1] * cos(PI / 15 * (i % 30) + OFFSET);
            rings_y[i] = distances[1] * sin(PI / 15 * (i % 30) + OFFSET);}
        else if (i >= 2 * 30 && i < 3 * 30) {
            rings_x[i] = distances[2] * cos(PI / 15 * (i % 30));
            rings_y[i] = distances[2] * sin(PI / 15 * (i % 30));}
        else if (i >= 3 * 30 && i < 4 * 30) {
            rings_x[i] = distances[3] * cos(PI / 15 * (i % 30) + OFFSET);
            rings_y[i] = distances[3] * sin(PI / 15 * (i % 30) + OFFSET);}
        else if (i >= 4 * 30 && i < 5 * 30) {
            rings_x[i] = distances[4] * cos(PI / 15 * (i % 30));
            rings_y[i] = distances[4] * sin(PI / 15 * (i % 30));}
        else if (i >= 6 * 30 && i < 6 * 30) {
            rings_x[i] = distances[5] * cos(PI / 15 * (i % 30) + OFFSET);
            rings_y[i] = distances[5] * sin(PI / 15 * (i % 30) + OFFSET);}
        else if (i >= 7 * 30 && i < 8 * 30) {
            rings_x[i] = distances[6] * cos(PI / 15 * (i % 30));
            rings_y[i] = distances[6] * sin(PI / 15 * (i % 30));}
        else {
            rings_x[i] = distances[7] * cos(PI / 15 * (i % 30) + OFFSET);
            rings_y[i] = distances[7] * sin(PI / 15 * (i % 30) + OFFSET);
        }
    }

    scrmod("revers");
    setpag("da4l");
    metafl("cons");
    disini();
    titlin("E8", 1);
    name("R-axis", "x");
    name("I-axis", "y");
    marker(21);
    hsymbl(20);
    qplsca(rings_x, rings_y, 30 * 8);

    free(distances);
    free(rings_x);
    free(rings_y);
    return 0;
}
