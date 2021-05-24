#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/// <summary>
/// bfs/dfs
/// </summary>
/// time complexity: O(V + E)
/// space complexity: O(V)
/// 
class vertex {
public:
	int id;
	vector<int> neibs;
	int ncount;
	bool discovered;
	vertex(int _id, vector<int> _neibs, int _ncount) {
		id = _id;
		neibs = _neibs;
		ncount = _ncount;
		discovered = false;
	}
};

class graph {
public:
	int count = 0;
	vector<vertex*> verticies;
	void add(int _id, vector<int> _neibs, int _ncount) {
		vertex* v = new vertex(_id, _neibs, _ncount);
		verticies.push_back(v);
		count++;
	}
};

void dfs(graph g, vertex*v) {
	cout << v->id << ' ';
	v->discovered = true;
	for (int i = 0; i < v->ncount; i++) {
		vertex* cv = g.verticies[(v->neibs)[i]];
		if (cv->discovered == false) {
			dfs(g, cv);
		}
	}
}

void bfs(graph g, vertex* root) {
	queue<vertex*> q;
	root->discovered = true;
	q.push(root);
	while (q.size() > 0) {
		vertex* s = q.front();
		cout << s->id << ' ';
		vector<int> neibs = s->neibs;
		int ncount = s->ncount;
		q.pop();
		for (int i = 0; i < ncount; i++) {
			if (g.verticies[neibs[i]]->discovered == false) {
				g.verticies[neibs[i]]->discovered = true;
				q.push(g.verticies[neibs[i]]);
			}
		}
	}
}

/// <summary>
/// sorting
/// </summary>
/// <returns></returns>

class sorting {
public:
	/// <summary>
	/// time complexity: partition runs in worst case n iterations, and quicksort runs in worst case n iterations: O(n^2)
	/// space complexity: partition takes constant space, and runs at worst n times: O(n)
	/// </summary>
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
			int pivot = partition(a, l, h);
			quicksort(a, l, pivot - 1);
			quicksort(a, pivot + 1, h);
		}
	}

	/// <summary>
	/// time complexity: O(nlog(n)) merge sorts in logarithmic time, and is called n times
	/// space complexity: O(n), we require instantiation of new arrays each level
	/// </summary>
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
			for (int i = m; i < len; i++) {
				r[i - m] = a[i];
			}
			mergesort(l, m);
			mergesort(r, len - m);
			merge(l, m, r, len - m, a);
		}
	}

	/// <summary>
	/// time complexity: O(nlog(n)) heapify is recursively called at most log(n) times, and called at most n times by heapsort
	/// space complexity: O(1), as we operate on the original array only
	/// </summary>
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
			swap(a[i], a[0]);
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
			cout << "prime" << endl;
			return;
		}
		if (n % i == 0) {
			cout << "not prime" << endl;
			return;
		}
		return prime(n, i - 1);
	}

	int binary_search(int a[], int l, int h, int t) {
		int m = (l + h) / 2;
		if (l <= h) {
			if (a[m] == t) {
				return m;
			}
			else if (a[m] < t) {
				return binary_search(a, m + 1, h, t);
			}
			else {
				return binary_search(a, l, m - 1, t);
			}
		}
	}

	void reverese(char word[], int l, int h) {
		while (l < h) {
			swap(word[l], word[h]);
			l++;
			h--;
			return reverese(word, l, h);
		}
	}

};

int main() {
	/// <summary>
	/// bfs/dfs
	/// </summary>
	/// <returns></returns>
	graph g;
	g.add(0, { 1, 2 }, 2);
	g.add(1, { 0, 3, 4 }, 3);
	g.add(2, { 0, 5, 6 }, 3);
	g.add(3, { 1 }, 1);
	g.add(4, { 1, 7 }, 2);
	g.add(5, { 2 }, 1);
	g.add(6, { 2 }, 1);
	g.add(7, { 4 }, 1);

	bfs(g, g.verticies[0]);

	/*
	for (int i = 0; i < g.count; i++) {
		if (g.verticies[i]->discovered == false) {
			dfs(g, g.verticies[i]);
		}
	}
	*/

	/// <summary>
	/// sort
	/// </summary>
	/// <returns></returns>
	sorting s;
	int a0[] = { 12, -5, 12312, 223, -45 };
	int l = 5;
	s.heapsort(a0, l);
	s.print(a0, l);

	int a1[] = { 12, -5, 12312, 223, -45 };
	s.mergesort(a1, l);
	s.print(a1, l);

	int a2[] = { 12, -5, 12312, 223, -45 };
	s.quicksort(a2, 0, l);
	s.print(a2, l);


	/// <summary>
	/// recursion
	/// </summary>
	/// <returns></returns>
	recursion r;
	r.fib(1, 0, 15);
	r.prime(101, 100);
	int a3[] = { 1, 3, 7, 9, 10 };
	cout << r.binary_search(a3, 0, l, 3) << endl;
	char word[] = "indian";
	r.reverese(word, 0, 5);
	cout << word << endl;
	return 0;
}
