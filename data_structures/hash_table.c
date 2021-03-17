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
	
}

void insert(int key, int data){
	struct hash_obj * new_obj = (struct has_obj *)malloc(sizeof(struct has_obj));
	new_obj -> key = key;
	new_obj -> data = data;
	
	int code = hash_func(key);
}

struct hash_obj * delete(struct hash_obj * item){
	int key = item -> key;
	
}

int main(void){
	
	hash_table = malloc(SIZE * sizeof(struct hash_obj));
	//do stuff
	free(hash_table);
;	return 0;
}
