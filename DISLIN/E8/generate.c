//gcc generate.c -o g
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define DIM 8

int * count;

int shouldSwap(float str[], int start, int curr)
{
    for (int i = start; i < curr; i++)
        if (str[i] == str[curr])
            return 0;
    return 1;
}

void findPermutations(float str[], int index, int n)
{
    if (index >= n) {
        for(int i = 0; i < n; i++){
          printf("%f ", str[i]);
        }
        count[0]++;
        return;
    }
    printf("\n");
    for (int i = index; i < n; i++) {
        int check = shouldSwap(str, index, i);
        if (check) {
            int temp_0 = str[index];
            int temp_1 = str[i];
            str[index] = temp_1;
            str[i] = temp_0;
            findPermutations(str, index + 1, n);
            int temp_2 = str[index];
            int temp_3 = str[i];
            str[index] = temp_3;
            str[i] = temp_2;
        }
    }
}


int main(void){

  count = malloc(sizeof(int));
  count[0] = 0;

  float b1[DIM] = {2,2,0,0,0,0,0,0};
  float b2[DIM] = {2,-2,0,0,0,0,0,0};
  float b3[DIM] = {-2,-2,0,0,0,0,0,0};

  float ** type_b1 = malloc(28 * sizeof(float *));
  float ** type_b2 = malloc(56 * sizeof(float *));
  float ** type_b3 = malloc(56 * sizeof(float *));

  float b4[DIM] = {1,1,-1,-1,-1,-1,-1,-1};
  float b5[DIM] = {1,1,1,1,-1,-1,-1,-1};
  float b6[DIM] = {1,1,1,1,1,1,-1,-1};

  float ** type_b4 = malloc(28 * sizeof(float *));
  float ** type_b5 = malloc(56 * sizeof(float *));
  float ** type_b6 = malloc(28 * sizeof(float *));

  float b7[DIM] = {1,1,1,1,1,1,1,1};
  float b8[DIM] = {-1,-1,-1,-1,-1,-1,-1,-1};

  findPermutations(b1, 0, 8);

  printf("\n%d\n", count[0]);
  return 0;
}
