#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// points to stack head
int * stack;
int count;

// creates new member of stack, pushes the others down
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
		return;
	}
}

// removes member of stack, pulls others up
int pop(int count){
	if(count == 0){
		return 0;
	}
	else{
		int pop = stack[0];
		for(i = 0; i < count; i++){
			stack[i] = stack[i + 1];
		}
		count--;
		return pop;
	}
}

int main(void){
	
	count = 0;
	stack = malloc(SIZE * sizeof(int));
	//do stuff
	free(stack);
	return 0;
}
