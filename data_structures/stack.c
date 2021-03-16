#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int * stack;
int count;

void push(int current, int count){
	if(count == SIZE){
		return;
	}
	else{
		count++;
		for(int i = 0; i < count; i++){
			stack[count - i] = stack[count - i - 1];
		}
		stack[0] = current;
	}
}

int pop(int count){
	if(count == 0){
		return;
	}
	else{
		int pop = stack[0];
		for(i = 0; i < count; i++){
			stack[i] = stack[i + 1];
		}
		count--;
	}
}

int main(void){
	
	count = 0;
	stack = malloc(SIZE * sizeof(int));

	return 0;
}
