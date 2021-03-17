#include <stdio.h>
#include <stdlib.h>

#define SIZE_queue
#define SIZE_list

int ** Queues;

float max_digit;

int max(int * array){
	min=max=array[0];
	for(i=1; i<n; i++){
		if(min>array[i]){
			min=array[i];  
		}
		if(max<array[i]){
			max=array[i];
		}
	}
	return max;
}

int main(void){
	int * unsorted = malloc(SIZE_list * sizeof(int));
	Queues = malloc(SIZE_queue * sizeof(SIZE_list));

	max_digit = (float)max(unsorted);
	dig_count = -1;
	while(max_digit > 1){
		max_digit = max_digit / 10;
		dig_count++;
	}
	for(int i = 0; i < unsorted; i++){
		for(ii = 1; ii <= 10; i++){
			if(unsorted[i] % ii == 0){
				insert(Queues[ii], unsorted[i]);
			} 
		}
	}
}
