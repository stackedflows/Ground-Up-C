#include <iostream>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;

/// <summary>
/// oop
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
			switch (a->eat(food)) {
			case 1:
				cout << "true" << endl;
				break;
			case 0:
				cout << "false" << endl;
				break;
			}
		}
		void abstract(int _size) {
			size = _size;
			cout << size << endl;
		}
	};

public:
	oop() {
		monkey mo;
		maggot mag;
		zoo z;
		z.feeder(&mo, "banana");
		z.feeder(&mag, "banana");
		z.abstract(123);
	}
};

/// <summary>
/// sorting
/// </summary>
class sorting {
private:
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

	void heapify(int a[], int len, int x) {
		int largest = x;
		int left = 2 * x + 1;
		int right = 2 * x + 2;
		if (left < len && a[largest] < a[left]) {
			largest = left;
;		}
		if (right < len && a[largest] < a[right]) {
			largest = right;
		}
		if (largest != x) {
			swap(a[0], a[largest]);
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

	int partition(int a[], int l, int h) {
		int piv = a[h];
		int index = l;
		for (int i = l; i < h; i++) {
			if (a[index] < piv) {
				swap(a[index], a[i]);
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

	void print(int a[], int l) {
		for (int i = 0; i < l; i++) {
			cout << a[i] << ' ';
		}cout << endl;
	}
public:
	sorting() {
		int a0[] = { 12, 3, -3, 324, 23 };
		int len = 5;
		/// <summary>
		/// tc: O(n^2), all pivots occur at edges
		///	sc: O(n) max stack space required for recusive call
		/// </summary>
		quicksort(a0, 0, len - 1);
		print(a0, len);
		int a1[] = { 12, 3, -3, 324, 23 };
		/// <summary>
		/// tc: O(nlog(n)), n passes, array split into log(n) levels, each of which
		/// sc: O(n) array creation
		/// </summary>
		mergesort(a1, len);
		print(a1, len);
		int a2[] = { 12, 3, -3, 324, 23 };
		/// <summary>
		/// tc: O(nlog(n)), n comparisons, max log(n) calls of recursion
		/// sc: O(n), max stack space required for recurive call
		/// </summary>
		heapsort(a2, len);
		print(a2, len);
	}
};

/// <summary>
/// hash map
/// </summary>
class hash_map {
private:
	struct node {
		int val;
		node* next;
		node(int n) {
			val = n;
			next = NULL;
		}
	};
	int size;
	node** table;
	int hash(int n) {
		return n % size;
	}
	void add(int n) {
		int index = hash(n);
		node* nn = new node(n);
		node* curr = table[index];
		if (!curr) {
			table[index] = nn;
		}
		else {
			while (curr->next) {
				curr = curr->next;
			}
			curr->next = nn;
		}
	}
	void search(int n) {
		int index = hash(n);
		node* curr = table[index];
		int count = 0;
		if (!curr) {
			return;
		}
		while (curr) {
			if (curr->val == n) {
				cout << index << ':' << count << endl;
			}
			curr = curr->next;
			count++;
		}
	}
public:
	hash_map(int n) {
		size = n;
		table = new node * [size]();
		for (int i = 0; i < size; i++) {
			add(i);
		}
		search(4);
		add(12);
		search(12);
	}
};

/// <summary>
/// linked list
/// </summary>
class linked_list {
private:
	struct node {
		int val;
		node* next;
		node(int n) {
			val = n;
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
		node * next = NULL;
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
		}
		cout << endl;
	}
public:
	linked_list() {
		head = NULL;
		for (int i = 0; i < 10; i++) {
			add(i);
		}
		display();
		reverse();
		display();
	}
};

/// <summary>
/// graph search
/// </summary>
class graph {
private:
	struct vertex {
		int id;
		vector<int> neibs;
		int nneibs;
		bool discovered;
		vertex(int _id, vector<int> _neibs, int _nneibs) {
			this->id = _id;
			this->neibs = _neibs;
			this->nneibs = _nneibs;
			this->discovered = false;
		}
	};
	vector<vertex*> verticies;
	void add(int id, vector<int> neibs, int nneibs) {
		vertex* v = new vertex(id, neibs, nneibs);
		verticies.push_back(v);
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

	void bfs() {
		vertex* root = verticies[0];
		cout << root->id << ' ';
		root->discovered = true;
		queue<vertex*> q;
		q.push(root);
		while (q.size() > 0) {
			vertex* v = q.front();
			vector<int> neibs = v->neibs;
			int nneibs = v->nneibs;
			q.pop();
			for (int i = 0; i < nneibs; i++) {
				vertex* cv = verticies[neibs[i]];
				if (cv->discovered == false) {
					cout << cv->id << ' ';
					cv->discovered = true;
					q.push(cv);
				}
			}
		}
		cout << endl;
	}
public:
	graph() {
		add(0, { 1,2,3 }, 3);
		add(1, { 0,4,5 }, 3);
		add(2, { 0 }, 1);
		add(3, { 0 }, 1);
		add(4, { 1 }, 1);
		add(5, { 1 }, 1);
		//bfs();
		dfs();
		cout << endl;
	}
};
/// <summary>
/// tree
/// </summary>
class tree {
private:
	struct node {
		int val;
		node* left;
		node* right;
		node(int n) {
			val = n;
			left = right = NULL;
		}
	};
	node* root;
	void pre(node* root) {
		if (!root) { return; }
		cout << root->val << ' ';
		pre(root->left);
		pre(root->right);
	}
public:
	tree() {
		root = new node(10);
		root->left = new node(5);
		root->right = new node(15);
		root->right->left = new node(12);
		root->right->right = new node(17);

		pre(root);
		cout << endl;
	}
};

/// <summary>
/// bst
/// </summary>
class bst {
private:
	struct node {
		int val;
		node* left;
		node* right;
		node(int n) {
			val = n;
			left = right = NULL;
		}
	};
	node* root;
	void _binSrc(node* v, int t) {
		if (v) {
			if (v->val == t) {
				cout << "found" << endl;
			}
			else if (v->val > t) {
				_binSrc(v->left, t);
			}
			else {
				_binSrc(v->right, t);
			}
		}
		else {
			cout << "not found" << endl;
		}
	}
	void binarySearch(int k) {
		return _binSrc(root, k);
	}
public:
	bst() {
		root = new node(10);
		root->left = new node(5);
		root->left->right = new node(8);
		root->right = new node(15);
		root->right->left = new node(11);
		root->right->right = new node(18);

		binarySearch(5);
		binarySearch(17);
		binarySearch(18);
	}
};

/// <summary>
/// recursion
/// </summary>
class recursion {
private:
	void _fib(int n, int i, int count, int target) {
		if (count < target) {
			int k = n + i;
			int j = n;
			cout << k << ' ';
			_fib(k, j, count + 1, target);
		}
	}
	void fib(int n) {
		_fib(1, 0, 0, n);
		cout << endl;
	}

	bool _prime(int curr) {
		int m = (int)sqrt(curr) + 1;
		for (int i = 2; i < m; i++) {
			if (curr % i == 0) {
				return false;
			}
		}
		return true;
	}
	void prime(int n) {
		int count = 0;
		int curr = 2;
		while (count < n) {
			if (_prime(curr)) {
				cout << curr << ' ';
				count++;
			}
			curr++;
		}cout << endl;
	}

	void reverse(char wrd[], int low, int high) {
		if (low < high) {
			swap(wrd[low], wrd[high]);
			low++;
			high--;
			reverse(wrd, low, high);
		}
	}

	void permutations(char a[], int low, int high) {
		if (low == high) {
			cout << a << endl;
		}
		else {
			for (int i = low; i < high; i++) {
				swap(a[low], a[i]);
				permutations(a, low + 1, high);
				swap(a[low], a[i]);
			}
		}
	}
public:
	recursion() {
		fib(10);
		prime(10);
		char a[] = "asdf";
		reverse(a, 0, 3);
		cout << a << endl;
		permutations(a, 0, 4);
	}
};

int main() {
	recursion rec;
	tree tr;
	graph g;
	linked_list ll;
	hash_map hm(10);
	sorting s;
	oop o;
	bst bs;
	return 0;
}
