#include <iostream>
using namespace std;

class sort {
	public :
		void heapify(int a[], int len, int x){
			int largest = x;
			int left = 2 * x + 1;
			int right = 2 * x + 2;

			if (left < len && a[left]> a[largest]) {
				largest = left;
			}
			if (right < len && a[right] > a[largest]) {
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

		// space complexity: O(1), as the algorithm only alters the original array, throught heapifying and comparing
		// time complexity: worst case O(nlog(n)), as the heap has height log(n), and heapify is called n times

		int partition(int a[], int start, int end) {
			int pivot = a[end];
			int index = start;

			for (int i = start; i < end; i++) {
				if (a[i] > pivot) {
					swap(a[i], a[index]);
					index++;
				}
			}

			swap(a[end], a[index]);
			return index;
		}

		void quicksort(int a[], int start, int end) {
			if (start < end) {
				int pivot = partition(a, start, end);

				quicksort(a, start, pivot - 1);
				quicksort(a, pivot + 1, end);
			}
		}

		// space complexity: O(n), as quicksort is called a maximum of n times, and swap functions, and pivot variable, are constant in space complexity
		// time complexity:
			// worst case: O(n^2), would occur if each time the pivot was at the leftmost of the array, causing the recursive sort graph to be right heavy
			// average case: O(nlog(n)), would occur if each time the pivot landed at the middle of the array, causuing a balanced graph of height log(n)

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

		void mergesort(int a[], int len) {
			if (len >= 2) {
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
		}

		// space complexity: O(n), as the splitting of the main array into sub arrays are linear in space complexity
		// time complexity: O(nlog(n)), as the arrays are divided in half each mergsort call
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

		void remove() {
			struct node* nn = head->next;

			head = nn;
		}

		bool search(int n) {
			struct node* nn = head;
			while (nn != NULL) {
				if (nn->data = n)return true;

				nn = nn->next;
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
			int popped = head->data;

			struct node* nn = head->next;

			head = nn;

			return popped;
		}

		bool search(int n) {
			struct node* nn = head;
			while (nn != NULL) {
				if (nn->data == n)return true;

				nn = nn->next;
			}
			return false;
		}
};

class OOP {
	private:
		int encap = 1;

	public:
		int abstract(int _x) {
			encap = _x;
			return encap;
		}
};

class inherit : public OOP{};

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
		child0(int _x = 0) : poly(_x){}
		int prop() {
			return x + 1;
		}
};

class child1 : public poly {
	public:
		child1(int _x = 0) : poly(_x){}
		int prop() {
			return x << 1;
		}
};

void print(int a[], int len) {
	for (int i = 0; i < len; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
}

int main() {
	sort s;

	int a0[] = { 12, -2, 34, 7 };
	int len = sizeof(a0) / sizeof(a0[0]);
	s.mergesort(a0, len);
	print(a0, len);

	int a1[] = { 12, -2, 34, 7 };
	s.heapsort(a1, len);
	print(a1, len);

	int a2[] = { 12, -2, 34, 7 };
	s.quicksort(a2, 0, len);
	print(a2, len);

	linked_list ll;

	for (int i = 0; i < 6; i++) {
		ll.add(i);
	}
	cout << ll.search(3) << endl;

	stack stk;

	for (int i = 0; i < 6; i++) {
		stk.push(i);
	}
	cout << stk.search(3) << endl;


	OOP o;
	
	cout << o.abstract(9) << endl;

	inherit i;

	cout << i.abstract(10) << endl;

	poly* p;
	child0 c0(1);
	child1 c1(1);

	p = &c0;
	cout << p->prop() << endl;

	p = &c1;
	cout << p->prop() << endl;
	return 0;
}
