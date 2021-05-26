#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/// <summary>
/// dfs/bfs
/// time complexity: O(V+E)
/// space complexity: O(V)
/// </summary>
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
	int count = 0;
	vector<vertex*> verticies;
	void add(int _id, vector<int> _neibs, int _nneibs) {
		vertex* v = new vertex(_id, _neibs, _nneibs);
		verticies.push_back(v);
		count++;
	}
};

void dfs(graph g, vertex* v) {
	v->discovered = true;
	cout << v->id << ' ';
	vector<int> neibs = v->neibs;
	for (int i = 0; i < v->nneibs; i++) {
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
		vertex* cv = q.front();
		vector<int> neibs = cv->neibs;
		q.pop();
		for (int i = 0; i < cv->nneibs; i++) {
			vertex* k = g.verticies[neibs[i]];
			if (k->discovered == false) {
				cout << k->id << ' ';
				k->discovered = true;
				q.push(k);
			}
		}
	}
	cout << endl;
}

/// <summary>
/// sorting
/// quicksort:
///		time complexity: O(n^2), each call results with pivot at lower/uppermost index of subarray: n comparisons, n passes
///		space complexity: O(log(n)), each recursive call takes constant space, and there are at most log(n) of them
/// mergesort:
///		time complexity: O(nlog(n)), n merges of size log(n)
///		space complexity: O(n), array storage
/// heapsort:
///		time complexity: O(nlog(n)), heapify takes log(n), heapsort passes n times
///		space complexity: O(1), we use only input array
/// 
/// </summary>
/// <returns></returns>
class sorting {
public:
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
			int p = partition(a, l, h);
			quicksort(a, l, p - 1);
			quicksort(a, p + 1, h);
		}
	}

	void heapify(int a[], int len, int x) {
		int largest = x;
		int left = 2 * x + 1;
		int right = 2 * x + 2;
		if (left<len && a[left]>a[largest]) {
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
				r[i-m] = a[i];
			}
			mergesort(l, m);
			mergesort(r, len - m);
			merge(l, m, r, len - m, a);
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
/// recursion
/// </summary>
/// <returns></returns>
class recursion {
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
			return;
		}
		if (n % i == 0) {
			cout << "not prime" << endl;
			return;
		}
		return prime(n, i - 1);
	}
	int bin_search(int a[], int l, int h, int t) {
		int m = (l + h) / 2;
		if (l < h) {
			if (a[m] == t) {
				return m;
			}
			else if (a[m] > t) {
				return bin_search(a, l, m - 1, t);
			}
			else {
				return bin_search(a, m + 1, h, t);
			}
		}
		else {
			cout << "not found" << endl;
		}
	}
	void reverse(char word[], int l, int h) {
		if (l < h) {
			swap(word[l], word[h]);
			l++;
			h--;
			return reverse(word, l, h);
		}
		cout << word << endl;
	}
};

/// <summary>
/// OOP
/// </summary>
/// <returns></returns>
class animal {
private:
	int encap = 0;
public:
	virtual bool eat(const char food[]) {
		return NULL;
	}
	int abstract(int e = 0) {
		encap = e;
		return encap;
	}
};

class rabbit : public animal{
public:
	bool eat(const char food[]) {
		return food == "leaves";
	}
};

class monkey : public animal {
public:
	bool eat(const char food[]) {
		return food == "banana";
	}
};

class cafe {
public:
	void feeder(animal* a, const char food[]) {
		cout << a->eat(food) << endl;
	}
};

/// <summary>
/// data structures
/// </summary>
/// <returns></returns>
class linked_list {
private:
	struct node {
		int data;
		struct node* next;
	};
	struct node* head = NULL;
public:
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
	int search(int n) {
		struct node* c = head;
		while (c != NULL) {
			if (c->data == n) {
				return 1;
			}
			c = c->next;
		}
		return 0;
	}
	void reverse(){
		struct node* curr = head;
		struct node* prev = NULL;
		struct node* next = NULL;
		whiel(curr != NULL){
			prev = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		head = curr;
	}
};

int main() {
	/// <summary>
	/// dfs/bfs
	/// </summary>
	/// <returns></returns>
	graph g;
	g.add(0, { 1, 2 }, 2);
	g.add(1, { 0, 3 ,4 }, 3);
	g.add(2, { 0, 5, 6 }, 3);
	g.add(3, { 1, 7 }, 2);
	g.add(4, { 1 }, 1);
	g.add(5, { 2 }, 1);
	g.add(6, { 2 }, 1);
	g.add(7, { 3 }, 1);

	for (int i = 0; i < g.count; i++) {
		if (g.verticies[i]->discovered == false) {
			//dfs(g, g.verticies[i]);
		}
	}
	cout << endl;

	bfs(g, g.verticies[0]);

	/// <summary>
	/// sorting
	/// </summary>
	/// <returns></returns>
	sorting s;
	int a0[] = {23, 543, -2, 234, -1};
	int len = 5;
	s.heapsort(a0, len);
	s.print(a0, len);

	int a1[] = { 23, 543, -2, 234, -1 };
	s.quicksort(a1, 0, len);
	s.print(a1, len);

	int a2[] = { 23, 543, -2, 234, -1 };
	s.mergesort(a2, len);
	s.print(a2, len);

	/// <summary>
	/// recursion
	/// </summary>
	/// <returns></returns>
	recursion r;
	int a3[] = { 1, 34, 123, 3453, 43543 };
	cout << r.bin_search(a3, 0, len, 43543) << endl;

	char word[] = "bagdad";
	r.reverse(word, 0, 5);

	r.prime(1231, 1230);
	r.fib(1, 0, 23);

	/// <summary>
	/// OOP
	/// </summary>
	/// <returns></returns>
	animal a;
	monkey m;
	rabbit rab;
	cafe c;
	c.feeder(&m, "banana");
	c.feeder(&rab, "leaves");

	cout << a.abstract(10) << endl;

	/// <summary>
	/// data structures
	/// </summary>
	/// <returns></returns>
	linked_list ll;
	for (int i = 0; i < 10; i++) {
		ll.add(i);
	}
	cout << ll.search(4) << endl;
	cout << ll.search(12) << endl;
	return 0;
}
