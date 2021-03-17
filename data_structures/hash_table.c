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

struct hash_obj * delete(struct hash_obj * item){
	int key = item -> key;
	int code = hash_func(key);

	int probe = code;
	while (hash_table[probe] == NULL) {
		if(probe > SIZE){
			printf("overflow\n");
			return NULL;
		}else{
			++probe;
			probe %= SIZE;
		}
	}

	struct hash_obj * dummy;
	dummy -> key = -1;
	dummy -> data = -1;

	hash_table[probe] = dummy;
}

int main(void){

	hash_table = malloc(SIZE * sizeof(struct hash_obj));
	//do stuff
	free(hash_table);
	return 0;
}
