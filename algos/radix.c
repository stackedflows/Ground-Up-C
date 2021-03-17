#include <stdio.h>
#include <stdlib.h>

#define SIZE_queue
#define SIZE_list

int ** Queues;

float max_digit;

int num_digits(int digit){
	int digit = digit;
	dig_count = -1;
	while(digit > 1){
		digit = digit / 10;
		dig_count++;
	}
}

int main(void){
	int * unsorted = malloc(SIZE_list * sizeof(int));
	Queues = malloc(SIZE_queue * sizeof(SIZE_list));

	for(int i = 0; i < unsorted; i++){
		for(ii = 1; ii <= 10; i++){
			int dig_count = num_digits(unsorted[i]);
			if(unsorted[i] % ii == 0 && dig_count > ii){
				insert(Queues[ii], unsorted[i]);
			} 
		}
	}
	//not finished
}
