#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/// <summary>
/// oop
/// </summary>
/// <returns></returns>
class animal {
public :
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

/// <summary>
/// recursion
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
	void reverse(char wrd[], int l, int h) {
		if (l < h) {
			swap(wrd[l], wrd[h]);
			l++;
			h--;
			return reverse(wrd, l, h);
		}
	}
	void bs(int a[], int l, int h, int t) {
		if (l < h) {
			int m = (l + h) / 2;
			if (a[m] == t) {
				cout << m << endl;
			}
			else if (a[m] < t) {
				bs(a, l, m - 1, t);
			}
			else {
				bs(a, m + 1, h, t);
			}
		}
	}
};

/// <summary>
/// hash map
///		search: O(n)
///		insert: O(n)
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
	int size = 0;
	hash_map(int n) {
		size = n;
		table = new hash_node * [size]();
	}
	int hash(int n) {
		return n % size;
	}
	void insert(int n) {
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
		hash_node* curr = table[index];
		int count = 0;
		while (curr) {
			if (curr->val == n) {
				cout << index << ':' << count << endl;
				return;
			}
			count++;
			curr = curr->next;
		}
		cout << "no element:" << n << endl;
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
/// </summary>
/// <returns></returns>
class linked_list {
public:
	struct node {
		int data;
		node* next;
	};
	node* head = NULL;
	void add(int n) {
		node* nn = new node;
		nn->data = n;
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
		node* curr = head;
		while (curr) {
			cout << curr->data << ' ';
			curr = curr->next;
		}
	}
};

/// <summary>
/// sorting
/// quicksort:
///		tc: O(n^2)
///		sc: O(n)
/// heapsort:
///		tc: O(nlogn)
///		sc: O(n)
/// mergesort:
///		tc: O(nlogn)
///		sc: O(n)
/// bubblesort:
///		tc: O(n^2)
///		sc: O(1)
/// </summary>
/// <returns></returns>
class sorting {
public:
	int partition(int a[], int l, int h) {
		int pivot = a[h];
		int index = l;
		for (int i = l; i < h; i++) {
			if (a[i] < pivot) {
				swap(a[i], a[index]);
				index++;
			}
			swap(a[index], a[h]);
			return index;
		}
	}
	void quicksort(int a[], int l, int h) {
		if (l < h) {
			int pivot = partition(a, l, h);
			quicksort(a, l, pivot - 1);
			quicksort(a, pivot + 1, h);
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
			swap(a[largest], a[x]);
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

	void bubblesort(int a[], int len) {
		for (int i = 0; i < len; i++) {
			for (int j = i + 1; j < len; j++) {
				if (a[j] > a[i]) {
					swap(a[j], a[i]);
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
/// graph searching
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
	vector<vertex*> verticies;
	int size = 0;
	void add(int _id, vector<int> _neibs, int _nneibs) {
		vertex* v = new vertex(_id, _neibs, _nneibs);
		verticies.push_back(v);
		size++;
	}
};

void dfs(graph g, vertex* v) {
	v->discovered = true;
	cout << v->id << ' ';
	vector<int> neibs = v->neibs;
	int nneibs = v->nneibs;
	for (int i = 0; i < nneibs; i++) {
		vertex* cv = g.verticies[neibs[i]];
		if (!cv->discovered) {
			dfs(g, cv);
		}
	}
}

void bfs(graph g, vertex* root) {
	root->discovered = true;
	queue <vertex*> q;
	q.push(root);
	while (q.size() > 0) {
		vertex* k = q.front();
		vector<int> neibs = k->neibs;
		int nneibs = k->nneibs;
		q.pop();
		for (int i = 0; i < nneibs; i++) {
			vertex* cv = g.verticies[neibs[i]];
			if (!cv->discovered) {
				cout << cv->id << ' ';
				cv->discovered = true;
				q.push(cv);
			}
		}
	}
}

/// <summary>
/// binary tree traversals
/// </summary>
/// <returns></returns>
class tree_node {
public:
	int data;
	tree_node* left;
	tree_node* right;
	tree_node(int n) {
		this->data = n;
		left = right = NULL;
	}
};

class traversals {
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
	/// oop
	/// </summary>
	/// <returns></returns>
	monkey mon;
	rabbit rab;
	zoo z;
	z.feeder(&mon, "banana");
	z.feeder(&rab, "banana");
	z.abstract(101);

	/// <summary>
	/// recursion
	/// </summary>
	/// <returns></returns>
	recursive rec;
	rec.fib(1, 0, 11);
	rec.prime(23, 22);
	rec.prime(10, 9);
	char wrd[] = "abcde";
	rec.reverse(wrd, 0, 4);
	cout << wrd << endl;
	int a0[] = { 12, 123, 34345, 73461 };
	rec.bs(a0, 0, 4, 73461);

	/// <summary>
	/// hash map
	/// </summary>
	/// <returns></returns>
	hash_map hm(10);
	for (int i = 0; i < 10; i++) {
		hm.insert(i);
	}
	hm.display();
	hm.insert(14);
	hm.search(14);
	hm.search(15);

	/// <summary>
	/// linked list
	/// </summary>
	/// <returns></returns>
	linked_list ll;
	for (int i = 0; i < 10; i++) {
		ll.add(i);
	}
	ll.display();
	ll.reverse();
	ll.display();
	cout << endl;

	/// <summary>
	/// sorting
	/// </summary>
	/// <returns></returns>
	sorting sor;
	int len = 5;
	int a1[] = { 12, -32, 123, 432, -24 };
	sor.bubblesort(a1, len);
	sor.print(a1, len);
	int a2[] = { 12, -32, 123, 432, -24 };
	sor.heapsort(a2, len);
	sor.print(a2, len);
	int a3[] = { 12, -32, 123, 432, -24 };
	sor.mergesort(a3, len);
	sor.print(a3, len);
	int a4[] = { 12, -32, 123, 432, -24 };
	sor.quicksort(a4, 0, len - 1);
	sor.print(a4, len);

	/// <summary>
	/// graph searching
	/// </summary>
	/// <returns></returns>
	graph gr;
	gr.add(0, { 1,2,3 }, 3);
	gr.add(1, { 0 }, 1);
	gr.add(2, { 4,5 }, 2);
	gr.add(3, { 0 }, 1);
	gr.add(4, { 2 }, 1);
	gr.add(5, { 2 }, 1);

	//bfs(gr, gr.verticies[0]);
	for (int i = 0; i < gr.size; i++) {
		vertex* cv = gr.verticies[i];
		if (!cv->discovered) {
			dfs(gr, cv);
		}
	}
	cout << endl;

	/// <summary>
	/// binary tree traversals
	/// </summary>
	/// <returns></returns>
	tree_node* root = new tree_node(0);
	root->left = new tree_node(1);
	root->right = new tree_node(2);
	root->left->left = new tree_node(3);
	root->left->right = new tree_node(4);

	traversals tr;
	tr.pre_(root);
	cout << endl;
	tr.in_(root);
	cout << endl;
	tr.post_(root);
	cout << endl;

	return 0;
}
