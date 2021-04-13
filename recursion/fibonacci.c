#include <stdio.h>

void fib(int a, int b){
    int x = b;
    int y = b + a;
    printf("%d\n", y);
    if( y < 10){
        fib(x, y);
    }else{
        return;
    }
}

int main (void){
  fib (0, 1);
  return 0;
}
