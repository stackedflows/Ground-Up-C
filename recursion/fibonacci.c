#include <stdio.h>

void fib(int a, int b){
    int x = b;
    int y = b + a;
    printf("%d ", y);
    if( y < 100){
        fib(x, y);
    }else{
        return;
    }
}

int main (void){
  fib (0, 1);
  return 0;
}
