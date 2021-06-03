#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

/// <summary>
/// search: O(V+E)
/// </summary>
class graph {
private:
	struct vertex {
		int id;
		vector<int> neibs;
		int nneibs;
		bool discovered;
		vertex(int _id, vector<int> _neibs, int _nneibs) {
			id = _id;
			neibs = _neibs;
			nneibs = _nneibs;
			discovered = false;
		}
	};
	vector<vertex*> verticies;
	void add(int _id, vector<int> _neibs, int _nneibs) {
		vertex* v = new vertex(_id, _neibs, _nneibs);
		verticies.push_back(v);
	}
	void bfs() {
		vertex* root = verticies[0];
		root->discovered = true;
		cout << root->id << ' ';
		queue<vertex*> q;
		q.push(root);
		while (q.size() > 0) {
			vertex* cv = q.front();
			vector<int> neibs = cv->neibs;
			int nneibs = cv->nneibs;
			q.pop();
			for (int i = 0; i < nneibs; i++) {
				vertex* v = verticies[neibs[i]];
				if (v->discovered == false) {
					cout << v->id << ' ';
					v->discovered = true;
					q.push(v);
				}
			}
		}
		cout << endl;
	}
	void _dfs(vertex* v) {
		cout << v->id << ' ';
		v->discovered = true;
		vector<int> neibs = v->neibs;
		int nneibs = v->nneibs;
		for (int i = 0; i < nneibs; i++) {
			vertex* cv = verticies[neibs[i]];
			if (cv->discovered == false) {
				_dfs(cv);
			}
		}
	}
	void dfs() {
		for (int i = 0; i < verticies.size(); i++) {
			vertex* v = verticies[i];
			if (v->discovered == false) {
				_dfs(v);
			}
		}
	}
public:
	graph() {
		add(0, { 1,2,3 }, 3);
		add(1, { 0,3 }, 2);
		add(2, { 0 }, 1);
		add(3, { 1 }, 1);
		//bfs();
		dfs();
	}
};

/// <summary>
/// heapsort: O(nlogn), n calls to heapify in main function, heapify calls itelf max logn times
/// quicksort: O(n^2), all pivots on lower/higher index of partition
/// mergesort: O(nlogn), merge takes max n comparisons, mergesort called max logn times
/// stack space: hs/qs: O(n)
/// array space: ms: O(n)
/// </summary>
class sorting {
private:
	void heapify(int a[], int len, int x) {
		int largest = x;
		int left = 2 * x + 1;
		int right = 2 * x + 2;
		if (left < len && a[largest] < a[left]) {
			largest = left;
		}
		if (right < len && a[largest] < a[right]) {
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
			int* l = new int[m]();
			int* r = new int[len - m]();
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

	int partition(int a[], int l, int h) {
		int piv = a[h];
		int index = l;
		for (int i = l; i < h; i++) {
			if (a[i] > piv) {
				swap(a[i], a[index]);
				index++;
			}
		}
		swap(a[h], a[index]);
		return index;
	}
	void quicksort(int a[], int l, int h) {
		if (l < h) {
			int pivot = partition(a, l, h);
			quicksort(a, l, pivot - 1);
			quicksort(a, pivot + 1, h);
		}
	}

	void display(int a[]) {
		for (int i = 0; i < 5; i++) {
			cout << a[i] << ' ';
		}cout << endl;
	}

public:
	sorting() {
		int a0[] = { 12,-2,163, -34, 121 };
		mergesort(a0, 5);
		display(a0);
		int a1[] = { 12,-2,163, -34, 121 };
		heapsort(a1, 5);
		display(a1);
		int a2[] = { 12,-2,163, -34, 121 };
		quicksort(a2, 0, 4);
		display(a2);
	}
};

/// <summary>
/// recursion in action
/// </summary>
class recursion {
private:
	void _fib(int n, int i, int t) {
		if (n < t) {
			int k = n + i;
			int j = n;
			cout << k << ' ';
			_fib(k, j, t);
		}
	}
	void fib(int num) {
		_fib(0, 1, num);
		cout << endl;
	}

	bool _prime(int p) {
		int lim = (int)sqrt(p) + 1;
		for (int i = 2; i < lim; i++) {
			if (p % i == 0) {
				return false;
			}
		}
		return true;
	}
	void primes(int num) {
		int count = 0;
		int curr = 2;
		while (count < num) {
			if (_prime(curr)) {
				cout << curr << ' ';
				count++;
			}
			curr++;
		}
		cout << endl;
	}

	void reverse(char arr[], int low, int high) {
		if (low < high) {
			swap(arr[low], arr[high]);
			low++;
			high--;
			reverse(arr, low, high);
		}
	}

	vector<string> perms;
	void permutations(char arr[], int low, int high) {
		if (low == high) {
			perms.push_back((string)arr);
			return;
		}
		else {
			for (int i = low; i < high; i++) {
				swap(arr[i], arr[low]);
				permutations(arr, low + 1, high);
				swap(arr[i], arr[low]);
			}
		}
	}
	void display() {
		cout << endl;
		for (int i = 0; i < perms.size(); i++) {
			cout << perms[i] << endl;
		}cout << endl;
	}
public:
	recursion() {
		fib(100);
		primes(10);
		char wrd[] = "asdz";
		reverse(wrd, 0, 3);
		cout << wrd << endl;
		permutations(wrd, 0, 4);
		display();
	}
};

/// <summary>
/// encapsulation: hiding data
/// abstraction: allows code to be portable and repeatable over programs
/// polymorphism: heirachical structure of code
/// inheritance: code that is agnostic to its instance
/// </summary>
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
		void feeder(animal* a, const char food[]) {
			cout << a->eat(food) << endl;
		}
		void abstract(int i) {
			switch (i) {
			case 10:
				size = i;
				cout << size << endl;
				break;
			default:
				break;
			}
		}
	};
public:
	oop() {
		monkey m;
		maggot mag;
		zoo z;
		z.feeder(&m, "human");
		z.feeder(&mag, "human");
		z.abstract(10);
	}
};

/// <summary>
/// search: O(log(n))
/// </summary>
class binaryTree {
private:
	struct node {
		int val;
		node* left;
		node* right;
		node(int _v) {
			val = _v;
			left = right = NULL;
		}
	};
	node* root;
public:
	void binarySearch(node * v, int n) {
		if (v) {
			if (v->val == n) {
				cout << "found" << endl;
				return;
			}
			else if (v->val > n) {
				binarySearch(v->left, n);
			}
			else {
				binarySearch(v->right, n);
			}
		}
		else {
			cout << "not found" << endl;
		}
	}
	binaryTree() {
		root = new node(10);
		root->left = new node(5);
		root->right = new node(15);
		root->right->left = new node(12);

		binarySearch(root, 12);
		binarySearch(root, 20);
	}
};

/// <summary>
/// search: O(1), O(log(n))
/// </summary>
class hashMap {
private:
	struct node {
		int key;
		int val;
		node* left;
		node* right;
		node(int _k, int _v) {
			key = _k;
			val = _v;
			left = right = NULL;
		}
	};
	int size;
	node** table;
	int hash(int n) {
		return n % size;
	}
	void _insert(node* nn, int index, int n) {
		if (n < nn->val) {
			if (!nn->right) {
				nn->right = new node(index, n);
			}
			else {
				_insert(nn->right, index, n);
			}
		}
		else {
			if (!nn->left) {
				nn->left = new node(index, n);
			}
			else {
				_insert(nn->left, index, n);
			}
		}
	}
	void add(int n) {
		int index = hash(n);
		node* nn = new node(index, n);
		if (!table[index]) {
			table[index] = nn;
		}
		else {
			_insert(table[index], index, n);
		}
	}
	void _search(node* n, int t) {
		if (n) {
			if (n->val == t) {
				cout << "found" << endl;
			}
			else if (n->val < t) {
				_search(n->left, t);
			}
			else {
				_search(n->right, t);
			}
		}
		else {
			cout << "not found" << endl;
		}
	}
	void search(int n) {
		int index = hash(n);
		node* curr = table[index];
		switch (curr!=NULL) {
		case 1:
			_search(curr, n);
			break;
		case 0:
			cout << "not found" << endl;
			break;
		}
	}
public:
	hashMap(int _size) {
		size = _size;
		table = new node* [size]();
		for (int i = 0; i < size; i++) {
			add(i);
		}
		search(6);
		search(12);
		add(12);
		search(12);
		search(13);
		search(14);
	}
};

/// <summary>
/// search: O(n)
/// </summary>
class linkedList {
private:
	struct node {
		int val;
		node* next;
		node(int _v) {
			val = _v;
			next = NULL;
		}
	};
	node* head;
	void add(int n) {
		node* nn = new node(n);
		nn->next = head;
		head = nn;
	}
	void reverse() {
		node* curr = head;
		node* prev = NULL;
		node* next = NULL;
		while (curr) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		head = prev;
	}
	void display() {
		node* curr = head;
		while (curr) {
			cout << curr->val << ' ';
			curr = curr->next;
		}cout << endl;
	}
public:
	linkedList() {
		for (int i = 0; i < 10; i++) {
			add(i);
		}
		display();
		reverse();
		display();
	}
};

/// <summary>
/// search: O(n)
/// </summary>
class stack {
private:
	struct node {
		int val;
		node* next;
		node(int _v) {
			val = _v;
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
		int ret = head->val;
		head = head->next;
		return ret;
	}
	void search(int n) {
		int k = pop();
		while (k != NULL) {
			if (k == n) {
				cout << "found" << endl;
				return;
			}
			k = pop();
		}
		cout << "not found" << endl;
	}
public:
	stack() {
		head = NULL;
		for (int i = 0; i < 10; i++) {
			push(i);
		}
		search(97);
	}
};

int main() {
	binaryTree bt;
	linkedList ll;
	stack stk;
	oop op;
	hashMap hm(10);
	recursion rec;
	sorting s;
	graph g;
	return 0;
}
