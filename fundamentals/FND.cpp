#include <iostream>
#include <vector>

using namespace std;

/// <summary>
/// dfs/bfs
/// </summary>

// time complexity: O(V + E)
// space compexity: O(V)

class vertex {
private:
	int identity;
	vector<int> neibours;
	int nneibours;
public:
	bool discovered = false;
	vertex(int _identity, vector<int> _neibours, int _nneibours) {
		identity = _identity;
		neibours = _neibours;
		nneibours = _nneibours;
	}
	int get_id() {
		return identity;
	}
	vector<int> get_neibs() {
		return neibours;
	}
	int get_nneibs() {
		return nneibours;
	}
};

class graph {
private:
	int count = 0;
public:
	vector<vertex*> vertices;
	void add(int id, vector<int> neibs, int nneibs) {
		vertex* v = new vertex(id, neibs, nneibs);
		vertices.push_back(v);
		count++;
	}
	int get_count() {
		return count;
	}
};

void dfs(graph g, vertex* v) {
	cout << v->get_id() << ' ';
	v->discovered = true;
	vector<int> neibs = v->get_neibs();
	for (int i = 0; i < v->get_nneibs(); i++) {
		int curr = neibs[i];
		vertex* cv = g.vertices[curr];
		if (cv->discovered == false) {
			return dfs(g, cv);
		}
	}
}

/// <summary>
/// sorting algs
/// </summary>
/// <returns></returns>

// heapsort
// time compelxity: O(nlog(n)), as the heap is of max height log(n), and we heapify it a maximum of n times
// space complexity: O(1), as we operate only on the original data structure

// quicksort
// time complexity: O(n^2), as each pass the pivot could land on the smallest index, causing n comparisons and n passes
// space complexity: O(nlog(n)), occurs if we partiion the heap at the midpoint each time

// mergesort
// time complexity: O(nlog(n)), as the merge/comparison could take n iterations, and there are log(n) array splits
// space complexity: O(n), as each of n passes we need to create an array of constant size 

class sort {
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

	void merge(int l[], int nl, int r[], int nr, int a[]) {
		int i = 0;
		int j = 0;
		int k = 0;
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
			for(int i = m; i < len; i++){
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
			swap(a[x], a[largest]);
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
};

/// <summary>
/// recursion
/// </summary>

class recursion {
public:
	void fib(int n, int i, int t) {
		if (t > n) {
			int k = n + i;
			int j = n;
			cout << k << ' ';
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

	void binary_search(int a[], int l, int h, int t) {
		if (l < h) {
			int m = (l + h) / 2;
			if (a[m] == t) {
				cout << m << endl;
			}
			else if (a[m] < t) {
				return binary_search(a, m + 1, h, t);
			}
			else {
				return binary_search(a, l, m - 1, t);
			}
		}
	}

	void reverse(char str[], int l, int h) {
		if (l < h) {
			swap(str[l], str[h]);
			l++;
			h--;
			reverse(str, l, h);
		}
	}
};
 
/// <summary>
/// OOP
/// </summary>
/// <param name="a"></param>
/// <param name="len"></param>

class OOP {
private:
	int encap = 0;
public:
	void abstract(int _x = 0) {
		encap = _x;
		cout << encap << endl;
	}
};

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

class whale : public animal {
public:
	bool eat(const char food[]) {
		return food == "fish";
	}
};

class cafe {
public:
	void feeder(animal * a, const char food[]) {
		cout << a->eat(food) << endl;
	}
};

void print(int a[], int len) {
	for (int i = 0; i < len; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
}

int main() {
	/// <summary>
	/// dfs
	/// </summary>
	/// <returns></returns>
	graph g;
	g.add(0, { 1, 2, 3 }, 3);
	g.add(1, { 0, 2 }, 2);
	g.add(2, { 1, 0, 4 }, 3);
	g.add(3, { 0 }, 1);
	g.add(4, { 2 }, 1);

	for (int i = 0; i < g.get_count(); i++) {
		vertex* c = g.vertices[i];
		if (c->discovered == false) {
			dfs(g, c);
		}
	}
	cout << endl;

	/// <summary>
	/// sort
	/// </summary>
	/// <returns></returns>

	sort s;

	int a0[] = { 12, -3, 435, 3, 5, -2, 56, -65 };
	int len = 8;
	s.quicksort(a0, 0, len);
	print(a0, len);

	int a1[] = { 12, -3, 435, 3, 5, -2, 56, -65 };
	s.mergesort(a1, len);
	print(a1, len);

	int a2[] = { 12, -3, 435, 3, 5, -2, 56, -65 };
	s.heapsort(a2, len);
	print(a2, len);

	/// <summary>
	/// recursion
	/// </summary>
	/// <returns></returns>

	recursion r;

	r.fib(0, 1, 10);
	r.prime(10, 9);
	r.prime(11, 10);

	int a3[] = { 12, -3, 435, 3, 5, -2, 56, -65 };
	r.binary_search(a3, 0, len, 56);

	char str[] = "wassup";
	r.reverse(str, 0, 5);
	cout << str << endl;

	/// <summary>
	/// OOP
	/// </summary>
	/// <returns></returns>
	
	animal a;
	monkey m;
	whale w;
	cafe c;

	c.feeder(&w, "fish");
	c.feeder(&w, "banana");
	c.feeder(&m, "banana");

	OOP o;
	o.abstract(10);

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	return 0;
}
