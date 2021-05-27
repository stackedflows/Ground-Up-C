#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/// <summary>
/// hash map
/// search: O(n) with ll, O(1) without
/// insert: O(n) with ll, O(1) without
/// </summary>
class hash_node {
public:
	int val;
	hash_node* next;
};

class hash_map {
private:
	hash_node** table;
	int size;
public:
	hash_map(int _size) {
		size = _size;
		table = new hash_node * [size]();
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
		hash_node* nn = new hash_node;
		nn->val = n;
		nn->next = NULL;
		hash_node* curr = table[index];
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
		hash_node* nn = table[index];
		cout << index;
		if (nn == NULL) {
			table[index] = nn;
			cout << "yep" << endl;
		}
		else {
			int count = 0;
			while (nn!= NULL) {
				if (nn->val == n) {
					cout << "true:" << count << endl;
				}
				nn = nn->next;
				count++;
			}
			cout << "false" << endl;
		}
	}
};
/// <summary>
/// sort
/// quicksort:
///		tc: O(n^2), if pivot falls on lowermost index each time
///		sc: O(n), n recursive calls of partition, which has constant space complexity in stack
///	heapsort:
///		tc: O(nlog(n)), heapify makes max log(n) recursive calls, heapsort called max n times
///		sc: O(n), called recursively n times
/// mergesort:
///		tc: O(nlog(n)), merge makes max n comparisons, mergesort called max log(n) times
///		sc: O(n), max n calls to mergesort, wich instantiates new arrays of contant size
/// </summary>
/// <returns></returns>
class sorting {
public:
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
		while (len >= 2) {
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
		if (right < len && a[right] < a[largest]) {
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

	void print(int a[], int len) {
		for (int i = 0; i < len; i++) {
			cout << a[i] << ' ';
		}
		cout << endl;
	}
};
/// <summary>
/// linked list
/// </summary>
/// <returns></returns>
class linked_list {
private:
	struct node {
		int data;
		node* next;
	};
	node* head = NULL;
public:
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
	}
	void display() {
		node* curr = head;
		while (curr) {
			cout << curr->data << ' ';
			curr = curr->next;
		}
		cout << endl;
	}
};

/// <summary>
/// dfs/bfs
///		tc: O(V+E)
///		sc: O(V)
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
	int size = 0;;
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
	int size = v->nneibs;
	for (int i = 0; i < size; i++) {
		vertex* cv = g.verticies[neibs[i]];
		if (cv->discovered == false) {
			return dfs(g, cv);
		}
	}
}

void bfs(graph g, vertex* root) {
	root->discovered = true;
	queue<vertex*> q;
	q.push(root);
	while (q.size() > 0) {
		vertex* curr = q.front();
		vector<int> neibs = curr->neibs;
		int size = curr->nneibs;
		q.pop();
		for (int i = 0; i < size; i++) {
			vertex* cv = g.verticies[neibs[i]];
			if (cv->discovered == false) {
				cv->discovered = true;
				cout << cv->id << ' ';
				q.push(cv);
			}
		}
	}
	cout << endl;
}

/// <summary>
/// OOP
/// </summary>
/// <returns></returns>
class animal {
public:
	virtual bool eat(const char food[]) {
		return NULL;
	}
};

class donkey : public animal {
public:
	bool eat(const char food[]) {
		return food == "banana";
	}
};

class monkey : public animal {
public:
	bool eat(const char food[]) {
		return food == "shoe";
	}
};

class zoo {
private:
	int size;
public:
	void feed(animal* a, const char food[]) {
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
class recursion {
public:
	void fib(int n, int i, int t) {
		while (n < t) {
			int k = n + i;
			int j = n;
			cout << n << ' ';
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
	void reverse(char string[], int l, int h) {
		if (l < h) {
			swap(string[l], string[h]);
			l++;
			h--;
			return reverse(string, l, h);
		}
	}
	int bs(int a[], int l, int h, int t) {
		if (l < h) {
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

int main() {
	/// <summary>
	/// hash map
	/// </summary>
	/// <returns></returns>
	int size = 10;
	hash_map h(size);
	for (int i = 0; i < 10; i++) {
		h.insert(i);
	}
	h.display();
	h.insert(17);
	h.search(17);

	/// <summary>
	/// sorting
	/// </summary>
	/// <returns></returns>
	sorting so;
	int a0[] = { 12, -4, 23, -34, 12 };
	int a2[] = { 12, -4, 23, -34, 12 };
	int a1[] = { 12, -4, 23, -34, 12 };
	int len = 5;
	so.heapsort(a0, len);
	so.print(a0, len);
	so.heapsort(a1, len);
	so.print(a1, len);
	so.quicksort(a2, 0, len);
	so.print(a2, len);

	/// <summary>
	/// linked list
	/// </summary>
	/// <returns></returns>
	linked_list ll;
	for (int i = 0; i < 12; i++) {
		ll.add(i);
	}
	ll.display();
	ll.reverse();
	ll.display();

	/// <summary>
	/// dfs/bfs
	/// </summary>
	/// <returns></returns>
	graph g;
	g.add(0, { 1,2,3 }, 3);
	g.add(1, { 0 }, 1);
	g.add(2, { 0, 4 }, 2);
	g.add(3, { 0 }, 1);
	g.add(4, { 2 }, 1);

	//bfs(g, g.verticies[0]);
	for (int i = 0; i < g.size; i++) {
		vertex* v = g.verticies[i];
		if (v->discovered == false) {
			dfs(g, v);
		}
	}
	cout << endl;

	/// <summary>
	/// OOP
	/// </summary>
	/// <returns></returns>
	donkey d;
	monkey m;
	zoo z;
	z.feed(&m, "banana");
	z.feed(&d, "banana");
	z.abstract(100);

	/// <summary>
	/// recursion
	/// </summary>
	/// <returns></returns>
	recursion rs;
	rs.fib(1, 0, 10);
	rs.prime(101, 100);
	char a[] = "hello";
	rs.reverse(a, 0, 4);
	cout << a << endl;
	int a3[] = { 0, 12, 345, 2342, 456566 };
	cout << rs.bs(a3, 0, 5, 12) << endl;
	return 0;
}
