#include <iostream>

using namespace std;

class sort {
public:
	void print(int a[], int len) {
		for (int i = 0; i < len; i++) {
			cout << a[i] << ' ';
		}
		cout << endl;
	}
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
			swap(a[x], a[largest]);
			heapify(a, len, largest);
		}
	}
	void heapsort(int a[], int len) {
		if (len >= 2) {
			for (int i = (len / 2) - 1; i >= 0; i--) {
				heapify(a, len, i);
			}
			for (int i = len - 1; i >= 0; i--) {
				swap(a[i], a[0]);
				heapify(a, i, 0);
			}
		}
	}
	// time complexity: worst case O(nlog(n)), as we make xn passes and the max height of the heap is xlog(n)
	// space complexity: worst case O(1), as we only operate on the original array

	int partition(int a[], int l, int h) {
		int pivot = a[h];
		int index = l;
		for (int i = l; i < h; i++) {
			if (a[i] > pivot) {
				swap(a[i], a[index]);
				index++;
			}
		}
		swap(a[index], a[h]);
		return index;
	}
	void quicksort(int a[], int l, int h) {
		if (l < h) {
			int pivot = partition(a, l, h);
			quicksort(a, l, pivot - 1);
			quicksort(a, pivot + 1, h);
		}
	}
	// time complexity: worst case O(n^2) occurs if each time the pivot lands on the smallest/largest index of the partitioned array
	// space complexity: worst case O(n), as the partition function takes up max n space

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
	// time complexity: worst case O(nlog(n)), since the array is split over log(n) operation, and ordered with max n passes each iteration
	// space complexity: worst case O(n), since we must create new arrays each pass
};

class recursive {
public:
	void fib(int n, int i, int t) {
		if (n < t) {
			int k = n + i;
			int j = n;
			cout << k << ' ';
			return fib(k, j, t);
		}
		cout << endl;
	}
	bool is_prime(int n, int i) {
		if (i == 1) {
			return true;
		}
		if (n % i == 0) {
			return false;
		}
		return is_prime(n, i - 1);
	}
	int bin_src(int a[], int l, int h, int t) {
		int m = (l + h) / 2;
		if (l <= h) {
			if (a[m] == t) {
				return m;
			}
			else if (a[m] > t) {
				return bin_src(a, l, m - 1, t);
			}
			else {
				return bin_src(a, m + 1, h, t);
			}
		}
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
	void remove() {
		struct node* nn = head->next;
		head = nn;
	}
	void search(int n) {
		struct node* nn = head;
		while (nn != NULL) {
			if (nn->data == n) {
				cout << "true" << endl;
				break;
			}
			nn = nn->next;
		}
		cout << "false" << endl;
	}
};

class animal {
public:
	virtual bool eat(const char food[]) {
		return NULL;
	}
};

class mankey : public animal {
public:
	bool eat(const char food[]) {
		return food == "banana";
	}
};

class dog : public animal {
public:
	bool eat(const char food[]) {
		return food == "cat";
	}
};

class feeder {
	feeder(animal a) {
		const char* monkey_food = "banana";
		const char* dog_food = "cat";
		cout << a.eat(monkey_food) << endl;
		cout << a.eat(dog_food) << endl;
	}
};

class OOP {
private:
	int encap = 0;
public:
	int abstract(int _in = 0) {
		encap = _in;
		return encap;
	}
};

class inherit : public OOP{};

class poly {
protected:
	int a = 0;
public:
	poly(int _a = 0) {
		a = _a;
	}
	virtual int prop() {
		return 0;
	}
};

class child0 : public poly {
public:
	child0(int _c = 0) : poly(_c){}
	int prop() {
		return a + 1;
	}
};

class child1 : public poly {
public:
	child1(int _c = 0) : poly(_c){}
	int prop() {
		return a * 10;
	}
};

int main() {
	sort s;
	int a0[] = { 1, -2, 2345, 56, -3 };
	int len = sizeof(a0) / sizeof(a0[0]);
	s.mergesort(a0, len);
	s.print(a0, len);
	int a1[] = { 1, -2, 2345, 56, -3 };
	s.quicksort(a1, 0, len);
	s.print(a1, len);
	int a2[] = { 1, -2, 2345, 56, -3 };
	s.heapsort(a2, len);
	s.print(a2, len);

	recursive r;
	r.fib(0, 1, 10);
	cout << r.is_prime(11, 10) << endl;
	cout << r.is_prime(10, 9) << endl;
	int a3[] = { 1, -2, 2345, 56, -3 };
	cout << r.bin_src(a3, 0, len, 56) << endl;

	linked_list ll;
	for (int i = 0; i < 10; i++) {
		ll.add(i);
	}
	ll.search(0);
	ll.remove();
	ll.search(0);

	animal a;
	mankey m;
	dog d;
	
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
