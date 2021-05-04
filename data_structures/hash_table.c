#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// data type we are interested in has a data field and key field
struct hash_obj{
	int data;
	int key;
};

// declare location of table
struct hash_obj * hash_table;

// function sends our key to a table index
int hash_func(int key){
	return key % SIZE;
}

// takes a data structure and assigns it to the table, making sure to deal with clashes using a probing function
void insert(int key, int data){
	struct hash_obj * new_obj = (struct has_obj *)malloc(sizeof(struct has_obj));
	new_obj -> key = key;
	new_obj -> data = data;

	int code = hash_func(key);
	int probe = code;
	while(hash_table[probe] != NULL){
		if(probe > SIZE){
			printf("overflow\n");
			return NULL;
		}else{
			++probe;
			probe %= SIZE;
		}
	}
	hash_table[probe] = new_obj;
}

// looks throught the table and returns an address based on a key, making sure to handle overflow
struct hash_obj * search(int key){
	int code = hash_func(key);
	int probe = code;
	while(hash_table[probe] == NULL){
		if(hash_table[probe] -> key == key && hash_table[probe] !== NULL){
			return hash_table[probe];
		}
		if(probe > SIZE){
			printf("overflow\n");
			return NULL;
		}else{
			++probe;
			probe %= SIZE;
		}
	}
}

int main(void){

	hash_table = malloc(SIZE * sizeof(struct hash_obj));
	//do stuff
	free(hash_table);
	return 0;
}
