#include <stdio.h>

void fib(int a, int b, int n, int max){
    int m = max;
    int count = n + 1;
    int x = b;
    int y = b + a;
    if( count < m){
        fib(x, y, count, m);
        printf("%d ", x);
    }
}

int main (void){
  fib (0, 1, 0, 40);
  return 0;
}
