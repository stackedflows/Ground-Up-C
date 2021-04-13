#include <stdio.h>

void fib(int a, int b, int n){
    int count = n + 1;
    int x = b;
    int y = b + a;
    if( count < 40){
        fib(x, y, count);
        printf("%d ", x);
    }
}

int main (void){
  fib (0, 1, 0);
  return 0;
}
