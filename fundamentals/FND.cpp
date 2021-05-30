#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

/// <summary>
/// sorting
/// </summary>
class sorting {
private:
	int partition(int a[], int l, int h) {
		int piv = a[h];
		int index = l;
		for (int i = l; i < h; i++) {
			if (a[i] < piv) {
				swap(a[i], a[index]);
				index++;
			}
		}
		swap(a[index], a[h]);
		return index;
	}
	void quicksort(int a[], int l, int h) {
		if (l < h) {
			int piv = partition(a, l, h);
			quicksort(a, l, piv - 1);
			quicksort(a, piv + 1, h);
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
			swap(a[x], a[largest]);
			heapify(a, len, largest);
		}
	}
	void heapsort(int a[], int len) {
		for (int i = (len / 2) - 1; i >= 0; i--) {
			heapify(a, len, i);
		}
		for (int i = len - 1; i >= 0; i--) {
			swap(a[0], a[i]);
			heapify(a, i, 0);
		}
	}

	void print(int a[], int len) {
		for (int i = 0; i < len; i++) {
			cout << a[i] << ' ';
		}
		cout << endl;
	}
public:
	sorting() {
		int len = 5;
		int a0[] = { -12,23,45,211,1 };
		/// <summary>
		/// tc: O(nlog(n))
		/// sc: O(n)
		/// </summary>
		mergesort(a0, len);
		print(a0, len);
		int a1[] = { -12,23,45,211,1 };
		/// <summary>
		/// tc: O(n^2)
		/// sc: O(n)
		/// </summary>
		quicksort(a1, 0, len - 1);
		print(a1, len);
		int a2[] = { -12,23,45,211,1 };
		/// <summary>
		/// tc: O(nlog(n))
		/// sc: O(n)
		/// </summary>
		heapsort(a2, len);
		print(a2, len);
	}
};

/// <summary>
/// graph search
/// </summary>
class graph {
private:
	struct vertex {
		int data;
		vector<int> neibs;
		int nneibs;
		bool discovered = false;
		vertex(int _data, vector<int> _neibs, int _nneibs) {
			data = _data;
			neibs = _neibs;
			nneibs = _nneibs;
		}
	};
	vector<vertex*> verticies;
	void add(int data, vector<int> neibs, int nneibs) {
		vertex* v = new vertex(data, neibs, nneibs);
		verticies.push_back(v);
	}
	void _dfs(vertex* v) {
		cout << v->data;
		v->discovered = true;
		vector<int> neibs = v->neibs;
		int nneibs = v->nneibs;
		for (int i = 0; i < nneibs; i++) {
			vertex* cv = verticies[neibs[i]];
			if (!cv->discovered) {
				_dfs(cv);
			}
		}
	}
public:
	graph() {
		add(0, { 1,2,3 }, 3);
		add(1, { 0,4,5 }, 3);
		add(2, { 0 }, 1);
		add(3, { 0 }, 1);
		add(4, { 1 }, 1);
		add(5, { 1 }, 1);
	}
	/// <summary>
	/// tc: O(V+E)
	/// sc: O(V)
	/// </summary>
	void bfs() {
		vertex* root = verticies[0];
		root->discovered = true;
		queue<vertex*> q;
		q.push(root);
		while (q.size() > 0) {
			vertex* cv = q.front();
			vector<int> neibs = cv->neibs;
			int nneibs = cv->nneibs;
			q.pop();
			for (int i = 0; i < nneibs; i++) {
				vertex* v = verticies[neibs[i]];
				if (!v->discovered) {
					cout << v->data;
					v->discovered = true;
					q.push(v);
				}
			}
		}
		cout << endl;
	}
	void dfs() {
		for (int i = 0; i < verticies.size(); i++) {
			vertex* curr = verticies[i];
			if (curr->discovered == false) {
				_dfs(curr);
			}
		}
		cout << endl;
	}
};

/// <summary>
/// binary trees
/// tc: O(n)
/// </summary>
class tree {
private:
	struct node {
		int data;
		node* left;
		node* right;
		node(int _data) {
			data = _data;
			left = right = NULL;
		}
	};
	node* root;
	void pre_order(node* n) {
		if (!n) {
			return;
		}
		cout << n->data;
		pre_order(n->left);
		pre_order(n->right);
	}
	void in_order(node* n) {
		if (!n) {
			return;
		}
		in_order(n->left);
		cout << n->data;
		in_order(n->right);
	}
	void post_order(node* n) {
		if (!n) {
			return;
		}
		post_order(n->left);
		post_order(n->right);
		cout << n->data;
	}
public:
	tree() {
		root = new node(0);
		root->left = new node(1);
		root->right = new node(2);
		root->left->left = new node(3);
		root->left->right = new node(4);
		cout << endl;
		pre_order(root);
		cout << endl;
		in_order(root);
		cout << endl;
		post_order(root);
		cout << endl;
	}
};

/// <summary>
/// linked list
/// </summary>
class linked_list {
private:
	struct node {
		int data;
		node* next;
		node(int n) {
			this->data = n;
			this->next = NULL;
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
		cout << endl;
	}
	void display() {
		node* c = head;
		while (c) {
			cout << c->data;
			c = c->next;
		}
		cout << endl;
	}
public:
	linked_list(int size) {
		head = NULL;
		for (int i = 0; i < size; i++) {
			add(i);
		}
		display();
		reverse();
		display();
	}
};

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

	class rabbit : public animal {
	public:
		bool eat(const char food[]) {
			return food == "leaves";
		}
	};

	class zoo {
	private:
		int size = 0;
	public:
		void feeder(animal* a, const char food[]) {
			cout << a->eat(food) << endl;
		}
		void abstract(int _size) {
			size = _size;
			cout << size << endl;
		}
	};
public:
	oop() {
		monkey m;
		rabbit r;
		zoo z;
		z.feeder(&m, "banana");
		z.feeder(&r, "banana");
		z.abstract(101);
	}
};

/// <summary>
/// recursion
/// </summary>
class recursion {
private:
	void _fib(int n, int i, int t) {
		if (n < t) {
			int k = n + i;
			int j = n;
			cout << k;
			_fib(k, j, t);
		}
	}
	void fib(int n) {
		_fib(1, 0, n);
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
	void prime(int n) {
		int count = 0;
		int item = 2;
		while (count < n) {
			bool is_prime = _prime(item);
			if (is_prime) {
				count++;
				cout << item <<' ';
			}
			item++;
		}
		cout << endl;
	}
	void reverse(char arr[], int l, int h) {
		if (l < h) {
			swap(arr[l], arr[h]);
			l++;
			h--;
			reverse(arr, l, h);
		}
	}
public:
	recursion() {
		fib(20);
		prime(15);
		char wrd[] = "abcdef";
		int size = 6;
		cout << wrd << endl;
		reverse(wrd, 0, 5);
		cout << wrd << endl;
	}
};

/// <summary>
/// hashing
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
	int _size;
	node** table;
	int hash(int n) {
		return n % _size;
	}
	void add(int n) {
		int index = hash(n);
		node* nn = table[index];
		if (!nn) {
			table[index] = new node(n);
		}
		else {
			while (nn->next) {
				nn = nn->next;
			}
			nn->next = new node(n);
		}
	}
	void search(int n) {
		int index = hash(n);
		node* curr = table[index];
		int count = 0;
		while (curr) {
			if (curr->val == n) {
				cout << index << ':' << count;
			}
			curr = curr->next;
			count++;
		}
		cout << endl;
	}
	void display(int n) {
		for (int i = 0; i < n; i++) {
			cout << table[i]->val << ' ';
		}cout << endl;
	}
public:
	hash_map(int size) {
		_size = size;
		table = new node * [_size]();
		for (int i = 0; i < size; i++) {
			add(i);
		}
		display(_size);
		add(_size + 5);
		search(5);
		search(15);
	}
};

int main() {
	sorting s;
	graph g;
	g.dfs();
	tree t;
	linked_list l(6);
	oop o;
	recursion r;
	hash_map hm(10);
	return 0;
}
