#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;


class graph {
private:
	struct cell {
		int id;
		vector<int> neibs;
		int nneibs;
		bool colour;
		cell(int i, vector<int> n, int nn) {
			id = i;
			neibs = n;
			nneibs = nn;
			colour = false;
		}
	};
	vector<cell*> grid;
	void add(int i, vector<int> n, int nn, bool col) {
		cell* c = new cell(i, n, nn);
		c->colour = col;
		grid.push_back(c);
	}
	/// <summary>
	/// bfs/dfs: O(v+e), O(v)
	/// </summary>
	int max;
	int curr;
	void _dfs(cell* c) {
		c->colour = false;
		vector<int> neibs = c->neibs;
		int nneibs = c->nneibs;
		for (int i = 0; i < nneibs; i++) {
			cell* nc = grid[neibs[i] - 1];
			if (nc->colour) {
				curr++;
				_dfs(nc);
			}
		}
	}
	void dfs() {
		for (int i = 0; i < grid.size(); i++) {
			cell* c = grid[i];
			if (c->colour) {
				curr = 0;
				_dfs(c);
				if (curr > max) {
					max = curr;
				}
			}
		}
		cout << max << endl;
	}

	void bfs() {
		cell* c = grid[0];
		cout << c->id <<' ';
		c->colour = true;
		queue<cell*> q;
		q.push(c);
		while (q.size() > 0) {
			cell* nc = q.front();
			vector<int> neibs = nc->neibs;
			int nneibs = nc->nneibs;
			q.pop();
			for (int i = 0; i < nneibs; i++) {
				cell* cc = grid[neibs[i] - 1];
				if (!cc->colour) {
					cout << cc->id << ' ';
					cc->colour = true;
					q.push(cc);
				}
			}
		}
		cout << endl;
	}
public:
	graph() {
		/*
		max = curr = 0;
		/// <summary>
		/// 1 2 3
		/// 4 5 6
		/// 7 8 9 10 11
		/// </summary>
		add(1, { 2,4 }, 2, true);
		add(2, { 1,3,5 }, 3, true);
		add(3, { 2,6 }, 2, false);
		add(4, { 1,5,7 }, 3, false);
		add(5, { 2,4,6,8 }, 4, false);
		add(6, { 3,5,9 }, 3, true);
		add(7, { 4,8 }, 2, false);
		add(8, { 5,7,9 }, 3, true);
		add(9, { 6,8,10 }, 3, true);
		add(10, { 9,11 }, 2, true);
		add(11, { 10 }, 1, true);

		dfs();
		*/
		add(1, { 2,4 }, 2, 0);
		add(2, { 1,3,5 }, 3, 0);
		add(3, { 2,6 }, 2, 0);
		add(4, { 1,5,7 }, 3, 0);
		add(5, { 2,4,6,8 }, 4, 0);
		add(6, { 3,5,9 }, 3, 0);
		add(7, { 4,8 }, 2, 0);
		add(8, { 5,7,9 }, 3, 0);
		add(9, { 6,8,10 }, 3, 0);
		add(10, { 9,11 }, 2, 0);
		add(11, { 10 }, 1, 0);
		bfs();
	}
};

class recursion {
private:
	void fib(int i, int j, int t) {
		if (i < t) {
			int k = i + j;
			int m = i;
			cout << k << ' ';
			fib(k, m, t);
		}
		else {
			cout << endl;
		}
	}
	void primes(int i, int j) {
		if (j == 1) {
			cout << i << " : prime" << endl;
			return;
		}
		else if (i % j == 0) {
			cout << i << " : not prime" << endl;
			return;
		}
		primes(i, j - 1);
	}
	/// <summary>
	/// O(2^nlog(n))
	/// </summary>
	void perms(char a[], int l, int h) {
		if (l == h) {
			for (int i = 0; i < h; i++) {
				cout << a[i] << ' ';
			}cout<<endl;
			return;
		}
		else {
			for (int i = l; i < h; i++) {
				swap(a[i], a[l]);
				perms(a, l + 1, h);
				swap(a[i], a[l]);
			}
		}
	}
	void rev(char a[], int l, int h) {
		if (l < h) {
			swap(a[l], a[h]);
			rev(a, l + 1, h - 1);
		}
	}
public:
	recursion() {
		fib(0, 1, 25);
		primes(101, 100);
		char a[] = "abcd";
		perms(a, 0, 4);
		rev(a, 0, 3);
		cout << a << endl;
 	}
};

class linkl {
private:
	struct node {
		int val;
		node* next;
		node(int v) {
			val = v;
			next = NULL;
		}
	};
	node* h0;
	node* h1;
	void insert(int n, int type) {
		node* nn = new node(n);
		switch (type) {
		case 0:
			nn->next = h0;
			h0 = nn;
			break;
		case 1:
			nn->next = h1;
			h1 = nn;
			break;
		}
	}
	/// <summary>
	/// O(max(n0 , n1))
	/// </summary>
	node* add(node* n0, node* n1, int c) {
		int nval = n0->val + n1->val + c;
		int nc = nval / 10;
		node* ret = new node(nval % 10);
		if (n0->next or n1->next) {
			if (not n0->next) {
				n0->next = new node(0);
			}
			if (not n1->next) {
				n1->next = new node(0);
			}
			ret->next = add(n0->next, n1->next, nc);
		}
		else if (nc) {
			ret->next = new node(nc);
		}
		return ret;
	}
	node* rev(node* n) {
		node* curr = n;
		node* next = NULL;
		node* prev = NULL;
		while (curr) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		return prev;
	}
	void disp(node* c) {
		if (c) {
			cout << c->val << ' ';
			disp(c->next);
		}
	}
public:
	linkl() {
		h0 = h1 = NULL;

		insert(3, 0);
		insert(1, 0);
		insert(9, 0);

		insert(2, 1);
		insert(2, 1);

		node* out = add(h0, h1, 0);
		disp(out);
		cout << endl;
		node* rout = rev(out);
		disp(rout);
	}
};

class oop {
private:
	class animal {
	public:
		virtual bool eat(const char food[]) {
			return NULL;
		}
	};
	class monkey : public animal {
	public:
		bool eat(const char food[]) {
			return food == "banana";
		}
	};
	class maggot : public animal {
	public:
		bool eat(const char food[]) {
			return food == "human";
		}
	};
	class zoo {
	private:
		int size = 0;
	public:
		void add(animal a) {
			size++;
			cout << size << endl;
		}
		void feeder(animal* a, const char food[]) {
			switch (a->eat(food)) {
			case 0:
				cout << "cannot" << endl;
				break;
			case 1:
				cout << "can" << endl;
			}
		}
	};
public:
	oop() {
		monkey mo;
		maggot ma;
		zoo z;
		z.add(mo);
		z.add(ma);
		z.feeder(&mo, "banana");
		z.feeder(&ma, "banana");
	}
};

class sorting {
private:
	int partition(int a[], int l, int h) {
		int pivot = a[h];
		int index = l;
		for (int i = l; i < h; i++) {
			if (a[index] < pivot) {
				swap(a[index], a[i]);
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
	
	void merge(int l[], int nl, int r[], int nr, int a[]) {
		int i = 0, j = 0, k = 0;
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
			int m = len / 2;
			int* r = new int[m]();
			int* l = new int[len - m]();
			for (int i = 0; i < m; i++) {
				l[i] = a[i];
			}
			for (int i = m; i < len; i++) {
				r[i - m] = a[i];
			}
			mergesort(l, m);
			mergesort(r, len - m);
			merge(l, m, r, len - m, a);
		}
	}

	void heapify(int a[], int len, int x) {
		int largest = x;
		int left = 2 * x + 1;
		int right = 2 * x + 2;
		if (left < len and a[largest] < a[left]) {
			largest = left;
		}
		if (right < len and a[largest] < a[right]) {
			largest = right;
		}
		if (largest != x) {
			swap(a[largest], a[x]);
			heapify(a, len, largest);
		}
	}
	void heapsort(int a[], int len) {
		for (int i = (len / 2); i >= 0; i--) {
			heapify(a, len, i);
		}
		for (int i = len - 1; i >= 0; i--) {
			swap(a[i], a[0]);
			heapify(a, i, 0);
		}
	}

	void disp(int a[], int len) {
		for (int i = 0; i < len; i++) {
			cout << a[i] << ' ';
		}cout << endl;
	}
public:
	sorting() {
		int a[] = { 1,6,3,78,3,9,3,-1 };
		/// <summary>
		/// O(n^2)/O(n)
		/// </summary>
		quicksort(a, 0, 7);
		disp(a, 8);
		int a0[] = { 1,6,3,78,3,9,3,-1 };
		/// <summary>
		/// O(nlogn)/O(n)
		/// </summary>
		mergesort(a0, 8);
		disp(a0, 8);
		int a1[] = { 1,6,3,78,3,9,3,-1 };
		heapsort(a1, 8);
		disp(a1, 8);
 	}
};

class hashMap {
private:
	struct node {
		int val;
		node* left;
		node* right;
		node(int v) {
			val = v;
			left = right = NULL;
		}
	};
	int size;
	node** table;
	int hash(int n) {
		return n % size;
	}
	void insert(node* nn, int n) {
		if (nn->val > n) {
			if (nn->right) {
				insert(nn->right, n);
			}
			else {
				nn->right = new node(n);
			}
		}
		else {
			if (nn->left) {
				insert(nn->left, n);
			}
			else {
				nn->left = new node(n);
			}
		}
	}
	void add(int n) {
		node* nn = table[hash(n)];
		if (nn) {
			insert(nn, n);
		}
		else {
			table[hash(n)] = new node(n);
		}
	}
	void _search(node* nn, int n) {
		if (nn) {
			if (nn->val == n) {
				cout << "found" << endl;
			}
			else if (nn->val < n) {
				_search(nn->left, n);
			}
			else {
				_search(nn->right, n);
			}
		}
		else {
			cout << "not found" << endl;
		}
	}
	void search(int n) {
		node* nn = table[hash(n)];
		_search(nn, n);
	}
public:
	hashMap() {
		int k = 10;
		size = k;
		table = new node* [k]();
		for (int i = 0; i < k; i++) {
			add(i);
		}
		search(5);
		search(71);
		add(71);
		search(71);
	}
};

class stack {
private:
	struct node {
		int val;
		node* next;
		node(int v) {
			val = v;
			next = NULL;
		}
	};
	node* head;
	void push(int n) {
		node* nn = new node(n);
		nn->next = head;
		head = nn;
	}
	int pop() {
		int temp = head->val;
		node* nn = head->next;
		head = nn;
		return temp;
	}
public:
	stack() {
		head = NULL;
		for (int i = 0; i < 10; i++) {
			push(i);
		}
		cout << pop() << endl;
	}
};

class Queue {
private:
	struct node {
		int val;
		node* prev;
		node* next;
		node(int v) {
			val = v;
			prev = next = NULL;
		}
	};
	node* head;
	node* tail;
	void push(int n) {
		node* nn = new node(n);
		nn->next = head;
		head = nn;
		if (tail == NULL) {
			tail = head;
		}
		if (nn->next) {
			nn->next->prev = nn;
		}
	}
	int pop() {
		if (tail) {
			node* nn = tail->prev;
			int temp = tail->val;
			tail = nn;
			return temp;
		}
	}
public:
	Queue() {
		head = tail = NULL;
		for (int i = 0; i < 10; i++) {
			push(i);
		}
	}
};

class heapQ {
private:
	struct item {
	public:
		int val;
		int pri;
	};

	int tailIndex;
	int size;
	vector<item> heap;

public:
	// O(logn)
	void siftUp(int i) {
		int above = floor((i - 1) / 2);
		if (above >= 0 and heap[above].pri < heap[i].pri) {
			swap(heap[i], heap[above]);
			siftUp(above);
		}
	}

	// O(logn)
	void push(item item) {
		heap.push_back(item);
		size++;
		siftUp(heap.size());
	}

	void siftDown(int i) {
		int largest = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		if (left < heap.size() and heap[largest].pri < heap[left].pri) {
			largest = left;
		}
		if (right < heap.size() and heap[largest].pri < heap[right].pri) {
			largest = right;
		}
		if (largest != i) {
			swap(heap[i], heap[largest]);
			siftDown(largest);
		}
	}

	// O(logn)
	int pop() {
		item it = heap.front();
		item hb = heap.back();
		heap.front() = hb;
		heap.pop_back();
		siftDown(0);
		return it.val;
	}

	void disp() {
		for (int i = 0; i < heap.size(); i++) {
			cout << heap[i].val << ':' << heap[i].pri << ' ';
		}cout << endl;
		cout << heap.size() << endl;
	}

	heapQ() {
		
		int a[] = { 1, 2, 8, 3, 0, 2, 6, 2, 6, 1, 5, 3, 5, 1 };
		int len = sizeof(a) / sizeof(a[0]);

		vector<item> freqs;

		for (int i = 0; i < len; i++) {
			item ite = { 0 , -1 };
			freqs.push_back(ite);
		}

		for (int i = 0; i < len; i++) {
			if (freqs[a[i]].pri == -1) {
				freqs[a[i]].val = a[i];
				freqs[a[i]].pri = 1;
			}
			else {
				freqs[a[i]].pri++;
			}

		}

		vector<item> freqsOut;

		for (int i = 0; i < freqs.size(); i++) {
			if (freqs[i].pri >= 0) {
				freqsOut.push_back(freqs[i]);
			}
		}

		size = freqsOut.size();
		tailIndex = 0;
		heap = freqsOut;

		for (int i = 0; i < size; i++) {
			siftUp(i);
		}

		cout << pop() << endl;
		cout << pop() << endl;
		cout << pop() << endl;
		cout << pop() << endl;

	}

};



int main() {
	graph g;
	recursion r;
	linkl ll;
	oop o;
	sorting s;
	hashMap hm;
	stack stk;
	Queue q;
	heapQ hq;
	return 0;
}
