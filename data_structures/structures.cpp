#include <iostream>
using namespace std;

struct node {
	int data;
	struct node* next;
};

struct node* head = NULL;

void add(int n) {
	struct node* n_node = new node;
	n_node->data = n;
	n_node->next = head;
	head = n_node;
}

bool search(int n) {
	struct node* curr = head;
	while (curr != NULL) {
		if (curr->data == n)return true;
		curr = curr->next;
	}
	return false;
}

void push(int n) {
	return add(n);
}

int pop() {
	int popped = head -> data;
	struct node* new_head = head->next;
	head = new_head;
	return popped;
}

bool _search(int n) {
	struct node* curr = head;
	while (curr != NULL) {
		if (curr->data == n)return true;
		curr = curr->next;
	}
	return false;
}

int main(){
	for (int i = 0; i < 5; i++) {
		add(i);
	}
	cout << search(9) << endl;

	head = NULL;

	for (int i = 0; i < 23; i++) {
		push(i);
	}

	cout << _search(45) << endl;

	return 0;
}
