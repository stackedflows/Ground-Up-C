#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/// <summary>
/// hashmap
///		search: O(n)
///		insert: O(n)
/// </summary>
class hashnode {
public:
	int val;
	hashnode* next;
};

class hashmap {
public:
	hashnode** table;
	int size = 0;
	hashmap(int _size) {
		size = _size;
		table = new hashnode * [size]();
	}
	int hash(int n) {
		return n % size;
	}
	void display() {
		for (int i = 0; i < size; i++) {
			cout << i << ':' << table[i]->val << ' ';
		}
		cout << endl;
	}
	void insert(int n) {
		int index = hash(n);
		hashnode* nn = new hashnode;
		nn->val = n;
		nn->next = NULL;
		hashnode* curr = table[index];
		if (curr == NULL) {
			table[index] = nn;
		}
		else {
			while (curr->next != NULL) {
				curr = curr->next;
			}
			curr->next = nn;
		}
	}
	void search(int n) {
		int index = hash(n);
		hashnode* curr = table[index];
		int count = 0;
		while (curr != NULL) {
			if (curr->val == n) {
				cout << "yep:" << index << ':' << count << endl;
				return;
			}
			curr = curr->next;
			count++;
		}
		cout << "nope" << endl;
	}
};

/// <summary>
/// graph
///		search: O(V+E)
///		space: O(V)
/// </summary>
/// <returns></returns>

class vertex {
public:
	int id;
	vector<int> neibs;
	int nneibs;
	bool discovered;
	vertex(int _id, vector<int> _neibs, int _nneibs) {
		discovered = false;
		id = _id;
		neibs = _neibs;
		nneibs = _nneibs;
	}
};

class graph {
public:
	vector<vertex*> verticies;
	int size = 0;
	void add(int _id, vector<int> _neibs, int _nneibs) {
		vertex * v = new vertex(_id, _neibs, _nneibs);
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
}

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

class cat : public animal {
public:
	bool eat(const char food[]) {
		return food == "fish";
	}
};

class zoo {
private:
	int size_encap = 0;
public:
	void feeder(animal* a, const char food[]) {
		cout << a->eat(food) << endl;
	}
	void abstract(int encap) {
		size_encap += encap;
		cout << size_encap << endl;
	}
};

/// <summary>
/// recursion
/// </summary>
/// <returns></returns>
class recursion {
public:
	void fib(int n, int i, int t) {
		if (t > n) {
			int temp = n;
			n = n + i;
			i = temp;
			cout << temp << ' ';
			return fib(n, i, t);
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
		while (l < h) {
			swap(a[l], a[h]);
			l++;
			h--;
			return reverse(a, l, h);
		}
	}
	int bs(int a[], int l, int h, int t) {
		while (l < h) {
			int m = (l + h) / 2;
			if (a[m] == t) {
				return m;
			}
			else if (a[m] > t) {
				return bs(a, l, m - 1, t);
			}
			else {
				return bs(a, m + 1, h, t);
			}
		}
	}
};

/// <summary>
/// linked list
///		search: tc: O(n)
///		insert: sc: O(1)
/// </summary>
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
	linked_list(int n) {
		for (int i = 0; i < n; i++) {
			add(i);
		}
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
/// mergesort:
///		tc: O(nlog(n))
///		sc: O(n)
/// heapsort:
///		tc: O(nlog(n))
///		sc: O(n)
/// bubblesort:
///		tc: O(n^2)
///		sc: O(1)
/// </summary>
/// <returns></returns>
class sorting {
public:
	void merge() {

	}
	void mergesort() {

	}

	void heapify() {

	}
	void heapsort() {

	}

	int partition() {

	}
	void quicksort() {

	}

	void bubblesort() {

	}

	void print() {

	}
};

int main() {
	/// <summary>
	/// hash map
	/// </summary>
	/// <returns></returns>
	int size = 10;
	hashmap hm(size);
	for (int i = 0; i < size; i++) {
		hm.insert(i);
	}
	hm.display();
	hm.insert(11);
	hm.search(1);
	hm.search(11);

	/// <summary>
	/// dfs/bfs
	/// </summary>
	/// <returns></returns>
	graph g;
	g.add(0, { 1, 2, 3 }, 3);
	g.add(1, { 4, 5 }, 2);
	g.add(2, { 0 }, 1);
	g.add(3, { 0 }, 1);
	g.add(4, { 1, 6 }, 2);
	g.add(5, { 1 }, 1);
	g.add(6, { 4 }, 1);

	//bfs(g, g.verticies[0]);
	for (int i = 0; i < g.size; i++) {
		vertex* v = g.verticies[i];
		if (v->discovered == false) {
			dfs(g, v);
		}
	}
	cout << endl;

	/// <summary>
	/// oop
	/// </summary>
	/// <returns></returns>
	animal an;
	monkey mo;
	cat ca;
	zoo z;
	z.feeder(&mo, "banana");
	z.feeder(&ca, "banana");
	z.abstract(21);

	/// <summary>
	/// recursion
	/// </summary>
	/// <returns></returns>
	recursion rec;
	rec.fib(1, 0, 12);
	rec.prime(101, 100);
	char word[] = "abcdef";
	rec.reverse(word, 0, 5);
	cout << word << endl;
	int a[] = { -1, 0, 90, 123, 12312, 131313 };
	cout << rec.bs(a, 0, 5, 0) << endl;

	/// <summary>
	/// linked list
	/// </summary>
	/// <returns></returns>
	linked_list ll(10);
	ll.display();
	ll.reverse();
	ll.display();

	/// <summary>
	/// sorting
	/// </summary>
	/// <returns></returns>
	sorting srt;
	return 0;
}
