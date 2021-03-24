//gcc generate.c -o g
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define DIM 8

int count = 0;

int shouldSwap(float str[], int start, int curr)
{
    for (int i = start; i < curr; i++)
        if (str[i] == str[curr])
            return 0;
    return 1;
}

void permutations(float base[], int index, int n, float target[][8])
{
    if (index >= n) {
        for(int i = 0; i < n; i++){
          target[count][i] = base[i];
        }
        count++;
        return;
    }

    for (int i = index; i < n; i++) {
        int check = shouldSwap(base, index, i);
        if (check) {
            int temp_0 = base[index];
            int temp_1 = base[i];
            base[index] = temp_1;
            base[i] = temp_0;
            permutations(base, index + 1, n, target);
            int temp_2 = base[index];
            int temp_3 = base[i];
            base[index] = temp_3;
            base[i] = temp_2;
        }
    }
}

int main(void){

  count = 0;
  float b1[DIM] = {2,2,0,0,0,0,0,0};
  float type_b1[28][8];
  permutations(b1, 0, 8, type_b1);


  count = 0;
  float b2[DIM] = {2,-2,0,0,0,0,0,0};
  float type_b2[56][8];
  permutations(b2, 0, 8, type_b2);

  count = 0;
  float b3[DIM] = {-2,-2,0,0,0,0,0,0};
  float type_b3[28][8];
  permutations(b3, 0, 8, type_b3);

  count = 0;
  float b4[DIM] = {1,1,-1,-1,-1,-1,-1,-1};
  float type_b4[28][8];
  permutations(b4, 0, 8, type_b4);

  count = 0;
  float b5[DIM] = {1,1,1,1,-1,-1,-1,-1};
  float type_b5[70][8];
  permutations(b5, 0, 8, type_b5);

  count = 0;
  float b6[DIM] = {1,1,1,1,1,1,-1,-1};
  float type_b6[28][8];
  permutations(b6, 0, 8, type_b6);

  float type_b7[DIM] = {1,1,1,1,1,1,1,1};
  float type_b8[DIM] = {-1,-1,-1,-1,-1,-1,-1,-1};

  return 0;
}
