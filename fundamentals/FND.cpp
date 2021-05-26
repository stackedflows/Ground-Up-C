#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/// <summary>
/// dfs/bfs:
///		time complexity: O(V+E)
///		space complexity: O(V)
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
		vertex* v = new vertex(_id,  _neibs, _nneibs);
		verticies.push_back(v);
		count++;
	}
};

void dfs(graph g, vertex* v) {
	cout << v->id << ' ';
	v->discovered = 1;
	vector<int> neibs = v->neibs;
	for (int i = 0; i < v->nneibs; i++) {
		vertex* c = g.verticies[neibs[i]];
		if (c->discovered == 0) {
			return dfs(g, c);
		}
	}
	cout << ':' ;
}

void bfs(graph g, vertex* root) {
	root->discovered = true;
	queue<vertex*> q;
	q.push(root);
	while (q.size() > 0) {
		vertex* v = q.front();
		vector<int> neibs = v->neibs;
		int nneibs = v->nneibs;
		q.pop();
		for (int i = 0; i < nneibs; i++) {
			vertex* k = g.verticies[neibs[i]];
			if (k->discovered == 0) {
				cout << k->id << ' ';
				k->discovered = 1;
				q.push(k);
			}
		}
	}
}

/// <summary>
/// sort
///		quicksort:
///			tc: O(n^2), if pivot lands on lower index each pass
///			sc: O(n), quicksort called recursively max n times, partition stores vals on stack
///		mergesort:
///			tc: O(nlog(n)), merge takes max log(n) ops, mergesort passes max n times
///			sc: O(n), constant arrays called n times
///		heapsort:
///			tc: O(nlog(n)), heapify calls itself max n times, each heapify taking max log(n) time
///			sc: O(n), heapify called recurively max n times, stores values on stack
/// </summary>
/// <returns></returns>
class sorting {
	public:
		int partition(int a[], int l, int h) {
			int piv = a[h];
			int ind = l;
			for (int i = l; i < h; i++) {
				if (a[i] < piv) {
					swap(a[i], a[ind]);
					ind++;
				}
			}
			swap(a[ind], a[h]);
			return ind;
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
			if (left<len && a[left]>a[largest]) {
				largest = left;
			}
			if (right<len && a[right]>a[largest]) {
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
/// recursive
/// </summary>
/// <returns></returns>
class recursive {
public:
	void fib(int n, int i, int t) {
		if(n < t){
			cout << n << ' ';
			int k = n + i;
			int j = n;
			return fib(k, j, t);
		}
		cout << endl;
	}
	void prime(int n, int i) {
		if (i == 1) {
			cout << "prime" << endl;
			return;
		}
		if (n % i == 0) {
			cout << "not prime" << endl;
			return;
		}
		return prime(n, i - 1);
	}
	void reverse(char word[], int l, int h){
		if (l < h) {
			swap(word[l], word[h]);
			l++;
			h--;
			return reverse(word, l, h);
		}
	}
	int bin_search(int a[], int l, int h, int t) {
		if (l < h) {
			int m = (l + h) / 2;
			if (a[m] == t) {
				return m;
			}
			else if (a[m] < t) {
				return bin_search(a, m + 1, h, t);
			}
			else {
				return bin_search(a, l, m - 1, t);
			}
		}
		return NULL;
	}
};

/// <summary>
/// oop
/// </summary>
/// <returns></returns>
class animal {
private:
	char* encap;
public:
	virtual bool eat(const char food[]) {
		return NULL;
	}
	void abstract(char anim[], int len) {
		encap = anim;
		for (int i = 0; i < len; i++) {
			cout << encap[i];
		}
		cout << endl;
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
		return food == "mouse";
	}
};

class zoo {
public:
	void feed(animal* a, const char food[]) {
		cout << a->eat(food) << endl;
	}
};

/// <summary>
/// linked list
/// </summary>
/// <returns></returns>
class ll {
public:
	struct node {
		int data;
		struct node* next;
	};
	struct node* head = NULL;
	void add(int n) {
		struct node* nn = new struct node;
		nn->data = n;
		nn->next = head;
		head = nn;
	}
	void reverse() {
		struct node* curr = head;
		struct node* prev = NULL;
		struct node* next = NULL;
		while(curr){
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		head = prev;
		cout << endl;
	}
	void display() {
		struct node* curr = head;
		while (curr) {
			cout << curr->data << ' ';
			curr = curr->next;
		}
	}
};

int main() {
	/// <summary>
	/// dfs/bfs
	/// </summary>
	/// <returns></returns>
	graph g;
	g.add(0, { 1, 2 }, 2);
	g.add(1, { 0, 3, 4 }, 3);
	g.add(2, { 0, 5, 6 }, 3);
	g.add(3, { 1 }, 1);
	g.add(4, { 1 }, 1);
	g.add(5, { 2, 7 }, 2);
	g.add(6, { 2 }, 1);
	g.add(7, { 5 }, 1);

	for (int i = 0; i < g.count; i++) {
		if (g.verticies[i]->discovered == 0) {
			//dfs(g, g.verticies[i]);
		}
	}

	//bfs(g, g.verticies[0]);

	/// <summary>
	/// sort
	/// </summary>
	/// <returns></returns>
	sorting s;
	int a0[] = { 2, -5, 5, -2, 1 };
	int len = 5;
	s.mergesort(a0, len);
	s.print(a0, len);

	int a1[] = { 2, -5, 5, -2, 1 };
	s.quicksort(a1, 0, len - 1);
	s.print(a1, len);

	int a2[] = { 2, -5, 5, -2, 1 };
	s.heapsort(a2, len);
	s.print(a2, len);

	/// <summary>
	/// recursion
	/// </summary>
	/// <returns></returns>
	recursive rec;
	rec.fib(1, 0, 9);
	rec.prime(1010, 1009);
	char word[] = "hello";
	rec.reverse(word, 0, 5);
	cout << word << endl;
	int a[] = { 1, 5, 7, 8, 39 };
	cout << rec.bin_search(a, 0, 5, 8) << endl;

	/// <summary>
	/// oop
	/// </summary>
	/// <returns></returns>
	
	animal an;
	monkey mon;
	cat ca;
	zoo z;
	char add[] = "tiger";
	an.abstract(add, 6);
	z.feed(&mon, "banana");

	/// <summary>
	/// linked list
	/// </summary>
	/// <returns></returns>
	ll l;
	for (int i = 0; i < 10; i++) {
		l.add(i);
	}
	l.display();
	l.reverse();
	l.display();
	return 0;
}
