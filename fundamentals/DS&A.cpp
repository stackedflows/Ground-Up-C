#include <iostream>
using namespace std;
class sort {
public:
	void heapify(int a[], int len, int x) {
		int largest = x;
		int left = 2 * x + 1;
		int right = 2 * x + 2;
		if (left<len && a[left]>a[largest]) {
			largest = left;
		}
		if (right<len && a[right]>a[largest]) {
			largest = right;
		}
		if (largest != x) {
			swap(a[largest], a[x]);
			heapify(a, len, largest);
		}
	}
	void heapsort(int a[], int len) {
		for (int i = (len / 2) - 1; i >= 0; i--) {
			heapify(a, len, i);
		}
		for (int i = len - 1; i >= 0; i--) {
			swap(a[i], a[0]);
			heapify(a, i, 0);
		}
	}
public:
	void quicksort(int a[], int start, int end) {
		if (start >= end)return;
		int pivot = partition(a, start, end);
		quicksort(a, start, pivot - 1);
		quicksort(a, pivot + 1, end);
	}
	int partition(int a[], int start, int end) {
		int pivot = a[end];
		int p_index = start;
		for (int i = start; i < end; i++) {
			if (a[i] > pivot) {
				swap(a[i], a[p_index]);
				p_index++;
			}
		}
		swap(a[end], a[p_index]);
		return p_index;
	}
public:
	void mergesort(int a[], int len) {
		if (len < 2)return;
		int mid = len / 2;
		int* l = new int[mid]();
		int* r = new int[len - mid]();
		for (int i = 0; i < mid; i++) {
			l[i] = a[i];
		}
		for (int i = mid; i < len; i++) {
			r[i - mid] = a[i];
		}
		mergesort(l, mid);
		mergesort(r, len - mid);
		merge(l, mid, r, len - mid, a);
	}
	void merge(int l[], int nl, int r[], int nr, int a[]) {
		int i = 0; 
		int j = 0;
		int k = 0;
		while (i < nl && j < nr) {
			if (l[i] < r[j]) {
				a[k] = l[i];
				i++;
			}
			else {
				a[k] = r[j];
				j++;
			}
			k++;
		}
		while (i < nl) {
			a[k] = l[i];
			i++;
			k++;
		}
		while (j < nr) {
			a[k] = r[j];
			j++;
			k++;
		}
	}
public:
	void print(int a[], int len) {
		for (int i = 0; i < len - 1; i++) {
			cout << a[i] << ',';
		}
		cout << a[len - 1] << endl;
	}
};
class linked_list {
private:
	struct node {
		int data;
		struct node* next;
	};
	struct node* head;
public:
	linked_list() {
		head = NULL;
	}
	void add(int n) {
		struct node* nn = new struct node;
		nn->data = n;
		nn->next = head;
		head = nn;
	}
	bool search(int n) {
		struct node* c = head;
		while (c != NULL) {
			if (c->data == n)return true;
			c = c->next;
		}
		return false;
	}
};
class stack {
private:
	struct node {
		int data;
		struct node* next;
	};
	struct node* head;
public:
	stack() {
		head = NULL;
	}
	void push(int n) {
		struct node* nn = new struct node;
		nn->data = n;
		nn->next = head;
		head = nn;
	}
	int pop() {
		if (head == NULL)return -1;
		int popped = head->data;
		struct node* nn = head->next;
		head = nn;
		return popped;
	}
	bool search(int n) {
		struct node* c = head;
		while (c != NULL) {
			if (c->data == n)return true;
			int k = pop();
			if (k == -1)break;
		}
		return false;
	}
};
class OOP {
private:
	int enc = 0;
public:
	void abstract(int n) {
		enc = n;
		cout << enc << endl;
	}
};
class inherit : public OOP {};
class poly {
protected:
	int x = 0;
public:
	poly(int _x = 0) {
		x = _x;
	}
	virtual int prop() {
		return 0;
	}
};
class child0 : public poly {
public:
	child0(int _x = 0) : poly(_x) {}
	int prop() {
		return x + 1;
	}
};
class child1 : public poly {
public:
	child1(int _x = 0) : poly(_x){}
	int prop() {
		return x * 10;
	}
};
int main() {
	sort s;
	int a0[] = { -1, 3, 6, -2, 7, 12, 5 };
	int len = sizeof(a0) / sizeof(a0[0]);
	// heapsort
	s.heapsort(a0, len);
	s.print(a0, len);
	int a1[] = { -1, 3, 6, -2, 7, 12, 5 };
	//quicksort
	s.quicksort(a1, 0, len);
	s.print(a1, len);
	int a2[] = { -1, 3, 6, -2, 7, 12, 5 };
	// mergesort
	s.mergesort(a2, len);
	s.print(a2, len);
	// linked list
	linked_list ll;
	for (int i = 0; i < 5; i++) {
		ll.add(i);
	}
	cout << ll.search(3) << ll.search(6) << endl;
	// stack
	stack stk;
	for (int i = 0; i < 7; i++) {
		stk.push(i);
	}
	cout << stk.search(9) << endl;
	// polymorphism
	poly* p;
	child0 c0(1);
	child1 c1(1);
	p = &c0;
	int k0 = p->prop();
	cout << k0 << endl;
	p = &c1;
	int k1 = p->prop();
	cout << k1 << endl;
	// abstraction
	OOP o;
	o.abstract(7);
	// inheritance
	inherit i;
	i.abstract(5);
	// encapsulation
	// cout << o.enc
	// returns err
	return 0;
}
