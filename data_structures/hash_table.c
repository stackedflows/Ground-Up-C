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

void insert(int * key_pos, int data){

}

struct hash_obj * delete(struct hash_obj * item){

}


int main(void){
	
	hash_table = malloc(SIZE * sizeof(struct hash_obj));
	
	return 0;
}
