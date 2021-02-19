#include <stdio.h>
#include <stdlib.h>

#define MAX 30000

//input tape
char parsed[MAX];
char * ptr;

//bracket matching
struct bracketlinks{
	char * bracket_1;
	char * bracket_2;
};
struct bracketlinks * pairslist;
int bracket_count;

//output tape
char mem[MAX] = {0};
int * mptr;

int main(){
	mptr = malloc(MAX*sizeof(int));

	//parse text file and make list of tokens
	FILE * parsecode;
	parsecode = fopen("helloworldbf.txt", "r");
	int count = 0;
	char buffer;
	while(!feof(parsecode)){
		buffer = fgetc(parsecode);
		if(buffer == 10){break;}
		if(buffer == 32){continue;}
		else{
			parsed[count] = buffer;
			if(buffer == 91 || buffer == 93){
				bracket_count++;
			}
			count++;
		}
	}
	fclose(parsecode);

	pairslist = malloc(bracket_count * sizeof(char*));

	//creates array of structures which match brackets so we can perform memory jumps
	int reset_count;
	int list_counter = 0;
	for(int i = 0; i < count; i++){
		if(parsed[i] == '['){
			reset_count = 0;
			for(int j = 0; j < count - i + 1; j++){
				if(parsed[i + j] == '['){reset_count++;}
				if(parsed[i + j] == ']'){reset_count--;}
				if(reset_count == 0){
					struct bracketlinks new;
					new.bracket_1 = &parsed[i];
					new.bracket_2 = &parsed[i + j];
					pairslist[list_counter] = new;
					list_counter++;
					break;
				}
				else{continue;}
			} 
		}
		else{continue;}
	}
	
	for(int i = 0; i < bracket_count/2; i++){
		printf("%p %p \n", pairslist[i].bracket_1, pairslist[i].bracket_2);
	}
	//runs through the input tape and performs brainfuck operations on the output tape
	ptr = parsed;
	char final_token = ptr[count];
	while(ptr[0] != final_token){
		if(ptr[0] == '['){
			if(mem[mptr[0]]){++ptr;}
			if(!mem[mptr[0]]){
				for(int i = 0; i < bracket_count/2; i++){
					if(pairslist[i].bracket_1 == &ptr[0]){
						ptr = pairslist[i].bracket_2;
					}
					if(pairslist[i].bracket_2 == &ptr[0]){
						ptr = pairslist[i].bracket_1;
					}
					else{continue;}
				}
			}
		}
		if(ptr[0] == ']'){
			if(mem[mptr[0]]){
				for(int i = 0; i < bracket_count/2; i++){
					if(pairslist[i].bracket_1 == &ptr[0]){
						ptr = pairslist[i].bracket_2;
					}
					if(pairslist[i].bracket_2 == &ptr[0]){
						ptr = pairslist[i].bracket_1;
					}
					else{continue;}
				}
			}
			if(!mem[mptr[0]]){++ptr;}
			else{continue;}
		}
		if(ptr[0] == '+'){++ptr;++mem[mptr[0]];}
		if(ptr[0] == '-'){++ptr;--mem[mptr[0]];}
		if(ptr[0] == '>'){++ptr; mptr[0]++;}
		if(ptr[0] == '<'){++ptr; mptr[0]--;}
		if(ptr[0] == '.'){++ptr;printf("%d\n", mem[mptr[0]]);}
		else{continue;}
	}

	return 0;
}
