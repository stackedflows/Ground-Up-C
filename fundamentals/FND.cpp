#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/// <summary>
/// dfs/bfs
///		insert/search: O(n)
/// </summary>
/// <returns></returns>

class vertex {
public:
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

class graph {
public:
	vector<vertex*> verticies = {};
	int size = 0;
	void add(int _val, vector<int> _neibs, int _nneibs) {
		vertex* v = new vertex(_val, _neibs, _nneibs);
		verticies.push_back(v);
		size++;
	}
};

class traversals {
public:

	void dfs(graph g, vertex* v) {
		v->discovered = true;
		cout << v->id << ' ';
		vector<int> neibs = v->neibs;
		int nneibs = v->nneibs;
		for (int i = 0; i < nneibs; i++) {
			vertex* cv = g.verticies[neibs[i]];
			if (cv->discovered == false) {
				dfs(g, cv);
			}
		}
	}

	void bfs(graph g, vertex* root) {
		root->discovered = true;
		queue<vertex*> q;
		q.push(root);
		while (q.size() > 0) {
			vertex* cv = q.front();
			vector<int>neibs = cv->neibs;
			int nneibs = cv->nneibs;
			q.pop();
			for (int i = 0; i < nneibs; i++) {
				vertex* v = g.verticies[neibs[i]];
				if (v->discovered == false) {
					cout << v->id << ' ';
					v->discovered = true;
					q.push(v);
				}
			}
		}
		cout << endl;
	}
};

/// <summary>
/// hash map
///		search/insert: O(n)
/// </summary>
/// <returns></returns>

class hash_node {
public:
	int val;
	hash_node* next;
};

class hash_map {
public:
	hash_node** table;
	int size;
	hash_map(int n){
		size = n;
		table = new hash_node * [size]();
	}
	int hash(int n) {
		return n % size;
	}
	void add(int n) {
		int index = hash(n);
		hash_node* nn = new hash_node;
		nn->val = n;
		nn->next = NULL;
		hash_node* curr = table[index];
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
		hash_node* nn = table[index];
		int count = 0;
		while (nn) {
			if (nn->val == n) {
				cout << index << ':' << count << endl;
				return;
			}
			count++;
			nn = nn->next;
		}
		cout << "not found" << endl;
	}
	void display() {
		for (int i = 0; i < size; i++) {
			cout << i << ':' << table[i]->val << ' ';
		}
		cout << endl;
	}
};

/// <summary>
/// linked list
///		search: O(n)
///		insert: O(1)
/// </summary>
/// <returns></returns>
class linked_list {
public:
	struct node {
		int data;
		node* next;
		node(int n) {
			this->data = n;
			this->next = NULL;
		}
	};
	node* head = NULL;
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
			cout << curr->data << ' ';
			curr = curr->next;
		}
	}
};

/// <summary>
/// sorting
///	heapsort:
///		tc: O(nlog(n))
///		sc: O(n)
/// mergesort:
///		tc: O(nlog(n))
///		sc: O(n)
/// quicksort:
///		tc: O(n^2)
///		sc: O(n)
/// bubble:
///		tc: O(n^2)
///		sc: O(1)
/// </summary>
/// <returns></returns>
class sorting {
public:
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
		int pivot = a[h];
		int index = l;
		for (int i = l; i < h; i++) {
			if (a[i] < pivot) {
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

	void bubblesort(int a[], int len) {
		for (int i = 0; i < len; i++) {
			for (int ii = i + 1; ii < len; ii++) {
				if (a[i] > a[ii]) {
					swap(a[i], a[ii]);
				}
			}
		}
	}

	void print(int a[], int len) {
		for (int i = 0; i < len; i++) {
			cout << a[i] << ' ';
		}
		cout << endl;
	}
};

/// <summary>
/// recursive
/// </summary>
/// <returns></returns>
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
	void prime(int n, int i) {
		if (i == 1) {
			cout << "is prime" << endl;
		}
		else if (n % i == 0) {
			cout << "not prime" << endl;
		}
		else {
			return prime(n, i - 1);
		}
	}
	void reverse(char a[], int l, int h) {
		if (l < h) {
			swap(a[l], a[h]);
			l++;
			h--;
			return reverse(a, l, h);
		}
	}
	void bs(int a[], int l, int h, int t) {
		if (h > l) {
			int m = (l + h) / 2;
			if (a[m] == t) {
				cout << m << endl;
			}
			else if (a[m] < t) {
				return bs(a, l, m - 1, t);
			}
			else {
				return bs(a, m + 1, h, t);
			}
		}
	}
};

/// <summary>
/// oop
/// </summary>
/// <returns></returns>
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

class donkey : public animal {
public:
	bool eat(const char food[]) {
		return food == "shoes";
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
		cout << size <<endl;
	}
};

/// <summary>
/// binary traversal
/// </summary>
/// <returns></returns>

struct tree_node {
public:
	int data;
	tree_node* left;
	tree_node* right;
	tree_node(int n) {
		this->data = n;
		left = right = NULL;
	}
};

class b_traversals {
public:
	void pre_(tree_node* n) {
		if (!n) {
			return;
		}
		cout << n->data << ' ';
		pre_(n->left);
		pre_(n->right);
	}
	void in_(tree_node* n) {
		if (!n) {
			return;
		}
		in_(n->left);
		cout << n->data << ' ';
		in_(n->right);
	}
	void post_(tree_node* n) {
		if (!n) {
			return;
		}
		post_(n->left);
		post_(n->right);
		cout << n->data << ' ';
	}
};

int main() {
	/// <summary>
	/// gen graph traversals
	/// </summary>
	/// <returns></returns>
	graph g;
	g.add(0, { 1,2 }, 2);
	g.add(1, { 3,4 }, 2);
	g.add(2, { 0 }, 1);
	g.add(3, { 1 }, 1);
	g.add(4, { 1 }, 1);

	traversals tr;
	//tr.bfs(g, g.verticies[0]);
	for (int i = 0; i < g.size; i++) {
		vertex* v = g.verticies[i];
		if (!v->discovered) {
			tr.dfs(g, v);
		}
	}
	cout << endl;

	/// <summary>
	/// hash map
	/// </summary>
	/// <returns></returns>
	hash_map hm(10);
	for (int i = 0; i < hm.size; i++) {
		hm.add(i);
	}
	hm.display();
	hm.add(13);
	hm.search(13);
	hm.search(18);

	/// <summary>
	/// linked list
	/// </summary>
	/// <returns></returns>
	linked_list ll;
	for (int i = 0; i < 10; i++) {
		ll.add(i);
	}
	ll.display();
	cout << endl;
	ll.reverse();
	ll.display();
	cout << endl;

	/// <summary>
	/// sorting
	/// </summary>
	/// <returns></returns>
	sorting so;
	int len = 5;
	int a0[] = { -1, 234, 34, -2, 34 };
	so.bubblesort(a0, len);
	so.print(a0, 5);
	int a1[] = { -1, 234, 34, -2, 34 };
	so.heapsort(a1, len);
	so.print(a1, len);
	int a2[] = { -1, 234, 34, -2, 34 };
	so.mergesort(a2, len);
	so.print(a2, len);
	int a3[] = { -1, 234, 34, -2, 34 };
	so.quicksort(a3, 0, len - 1);
	so.print(a3, len);

	/// <summary>
	/// recursion
	/// </summary>
	/// <returns></returns>
	recursive rec;
	rec.fib(1, 0, 10);
	rec.prime(23, 22);
	char a[] = "abcd";
	rec.reverse(a, 0, 3);
	cout << a << endl;
	int d[] = { 12, 23, 54, 211 };
	rec.bs(d, 0, 4, 54);
	cout << endl;

	/// <summary>
	/// oop
	/// </summary>
	/// <returns></returns>
	monkey mo;
	donkey don;
	zoo z;
	z.feeder(&mo, "banana");
	z.feeder(&don, "banana");
	z.abstract(100);

	/// <summary>
	/// binary search
	/// </summary>
	/// <returns></returns>
	b_traversals bt;
	tree_node* root = new tree_node(0);
	root->left = new tree_node(1);
	root->right = new tree_node(2);
	root->left->left = new tree_node(3);
	root->left->right = new tree_node(4);

	bt.pre_(root);
	cout << endl;
	bt.in_(root);
	cout << endl;
	bt.post_(root);
	cout << endl;
	return 0;
}
