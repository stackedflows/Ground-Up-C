#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct hash_obj{
	int data;
	int key;
};

struct hash_obj * hash_table;

int hash_func(int key){
	
	return key % SIZE;
}

struct hash_obj * search(int key){
	for(int i = 0; i < SIZE; i++){
		i %= SIZE;
		if(hash_table[i] -> key == key){
			return 	hash_table[i];
		}else{
			printf("probe");
			return NULL;
		}
	}
}

void insert(int key, int data){
	struct hash_obj * insert = (struct hash_obj *)malloc(sizeof(struct hash_obj));
	hash_obj -> key = key;
	hash_obj -> data = data;
	
	int code = hash_func(key);
	
	for(int i = 0; i < SIZE; i++){
		i %= SIZE;
		if(hash_table[i] -> key == code && hash_table[i] == NULL){
			hash_table[i] = hash_obj;	
		}else{
			printf("probe");
			return;
		}
	}
}

struct hash_obj * delete(struct hash_obj * item){
	int key = hash_obj -> key;
	int index = hash_func(key);
	
	struct hash_obj * hash_dummy = (struct hash_obj *)malloc(sizeof(struct hash_obj));
	
	for(int i = 0; i < SIZE; i++){
		i %= SIZE;
		if(hash_table[i] -> key = index){
			struct hash_obj * hash_temp = hash_table[index];
			
			hash_table[index] = hash_dummy;
			return hash_temp;
		}else{
			printf("probe");
			return NULL;
		}
	}
}

int main(void){
	
	hash_table = malloc(SIZE * sizeof(struct hash_obj));
	//do stuff
	free(hash_table);
;	return 0;
}
