#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

class fundamentals {

public:

	/// <summary>
	/// inheritance: heirachical code
	/// polymorphism: allows for function implimentation to differ depending on instance
	/// abstraction: allows for code to be portable over code-base
	/// encapsulation: allows for hidden data / method 
	/// </summary>
	class oop {
	private:

		class animal {
		public:
			virtual bool eat(const char food[]) {
				return NULL;
			}
		};

		class maggot : public animal {
		public:
			bool eat(const char food[]) {
				return food == "human";
			}
		};

		class monkey : public animal {
			bool eat(const char food[]) {
				return food == "banana";
			}
		};

		class zoo {
		private:
			int size = 0;
		public:
			void feed(animal* a, const char food[]) {
				switch (a->eat(food)) {
				case 0:
					cout << "doesnt eat" << endl;
					break;
				case 1:
					cout << "eats!" << endl;
					break;
				}
			}
			void add(animal* a) {
				size++;
				cout << size << endl;
			}
		};

	public:
		oop() {
			maggot ma;
			monkey mo;
			zoo z;
			z.add(&mo);
			z.feed(&mo, "banana");
			z.feed(&ma, "banana");
		}
	};

	/// <summary>
	/// dfs / bfs : O(v+e) / O(v)
	/// </summary>
	class graph {
	private:

		struct cell {
			int id;
			vector<int> neibs;
			int nneibs;
			bool colour;
			cell(int i, vector<int> n, int nn, bool col) {
				id = i;
				neibs = n;
				nneibs = nn;
				colour = col;
			}
		};

		vector<cell*> grid;

		void add(int i, vector<int> n, int nn, bool col) {
			cell* c = new cell(i, n, nn, col);
			grid.push_back(c);
		}

		int max = 0;
		int curr = 0;

		void _dfs(cell* c) {
			c->colour = false;
			vector<int> neibs = c->neibs;
			int nneibs = c->nneibs;
			for (int neib = 0; neib < nneibs; neib++) {
				cell* nc = grid[neibs[neib] - 1];
				if (nc->colour) {
					curr++;
					_dfs(nc);
				}
			}
		}

		void dfs() {
			for (int c = 0; c < grid.size(); c++) {
				cell* nc = grid[c];
				if (nc->colour) {
					curr = 1;
					_dfs(nc);
					if (curr > max) {
						max = curr;
					}
				}
			}cout << max << endl;
		}

		void bfs() {
			cell* root = grid[0];
			cout << root->id << ' ';
			root->colour = true;
			queue<cell*> q;
			q.push(root);
			while (q.size() > 0) {
				cell* cc = q.front();
				vector<int> neibs = cc->neibs;
				int nneibs = cc->nneibs;
				q.pop();
				for (int i = 0; i < nneibs; i++) {
					cell* nc = grid[neibs[i] - 1];
					if (!nc->colour) {
						cout << nc->id << ' ';
						nc->colour = true;
						q.push(nc);
					}
				}
			}cout << endl;
		}

	public:
		graph() {
			
			int arr[3][3] = {
				{1,2,3},
				{4,5,6},
				{7,8,9}
			};

			add(1, { arr[0][1], arr[1][0] }, 2, true);
			add(2, { arr[0][0],arr[0][2],arr[1][1] }, 3, true);
			add(3, { arr[0][1], arr[1][2] }, 2, false);
			add(4, {arr[0][0], arr[1][1], arr[2][0]}, 3, false);
			add(5, { arr[0][1],arr[1][0],arr[1][2], arr[2][1] }, 4, false);
			add(6, { arr[0][2],arr[1][1],arr[2][2] }, 3, true);
			add(7, { arr[1][0], arr[2][1] }, 2, true);
			add(8, { arr[1][1], arr[2][0], arr[2][2] }, 3, true);
			add(9, { arr[2][1],arr[1][2] }, 2, true);

			//dfs();

			for (int i = 0; i < grid.size(); i++) {
				grid[i]->colour = false;
			}

			//bfs();
		}
	};

	/// <summary>
	/// stack space analysis
	/// </summary>
	class recursion {

	private:

		vector<string> perms;
		/// <summary>
		/// O(n^2logn)
		/// </summary>
		void permutations(char wrd[], int low, int high) {
			if (low == high) {
				perms.push_back((string)wrd);
			}
			else {
				for (int letter = low; letter < high; letter++) {
					swap(wrd[low], wrd[letter]);
					permutations(wrd, low + 1, high);
					swap(wrd[low], wrd[letter]);
				}
			}
		}

		/// <summary>
		/// O(n)
		/// </summary>
		void rev(char wrd[], int low, int high) {
			if (low < high) {
				swap(wrd[low], wrd[high]);
				rev(wrd, low + 1, high - 1);
			}
			if (low == high) {
				cout << wrd << endl;
				return;
			}
		}

	public:

		recursion() {
			char word[] = "abc";
			permutations(word, 0, 3);
			for (int i = 0; i < perms.size(); i++) {
				cout << perms[i] << endl;
			}
			rev(word, 0, 2);
		}

	};

	/// <summary>
	/// heap: O(nlogn) / O(n)
	/// merge: O(nlogn) / O(n)
	/// quick: O(n^2) / O(n)
	/// </summary>
	class sorting {
	private:
		
		void heapify(int a[], int len, int x) {
			int largest = x;
			int left = 2 * x + 1;
			int right = 2 * x + 2;
			if (left < len and a[largest] < a[left]) {
				largest = left;
			}
			if (right < len and a[largest] < a[right]) {
				largest = right;
			}
			if (largest != x) {
				swap(a[largest], a[x]);
				heapify(a, len, largest);
			}
		}
		void heapsort(int a[], int len) {
			for(int i = (len / 2) - 1; i >= 0; i--) {
				heapify(a, len, i);
			}
			for(int i = len - 1; i >= 0; i--) {
				swap(a[i], a[0]);
				heapify(a, i, 0);
			}
		}

		void merge(int l[], int nl, int r[], int nr, int a[]) {
			int i = 0, j = 0, k = 0;
			while (i < nl and j < nr) {
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
			if (len / 2 >= 2) {
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

		void disp(int a[], int l) {
			for (int i = 0; i < l; i++) {
				cout << a[i] << ' ';
			}cout << endl;
		}

	public:
		sorting() {
			int a[] = {1, 6, 3, 8, 4};
			int len = 5;
			//quicksort(a, 0, len - 1);
			//heapsort(a, 5);
			mergesort(a, len);
			disp(a, len);
		}
	};

	/// <summary>
	/// add: O(max(l1, l2)) / O(l1+l2)
	/// </summary>
	class linkedList {
	private:

		struct node {
			int val;
			node* next;
			node(int v) {
				val = v;
				next = NULL;
			}
		};

		node* h0;
		node* h1;

		void insert(int n, int type) {
			node* nn = new node(n);
			switch (type) {
			case 0:
				nn->next = h0;
				h0 = nn;
				break;
			case 1:
				nn->next = h1;
				h1 = nn;
				break;
			}
		}

		node* add(node* n0, node* n1, int c) {
			int nVal = n0->val + n1->val + c;
			int nc = nVal / 10;
			node* ret = new node(nVal % 10);
			if (n0->next or n1->next) {
				if (not n0->next) {
					n0->next = new node(0);
				}
				if (not n1->next) {
					n1->next = new node(0);
				}
				ret->next = add(n0->next, n1->next, nc);
			}
			else {
				if (nc) {
					ret->next = new node(nc);
				}
			}
			return ret;
		}

		node* rev(node* n) {
			node* curr = n;
			node* prev = NULL;
			node* next = NULL;
			while (curr) {
				next = curr->next;
				curr->next = prev;
				prev = curr;
				curr = next;
			}
			return prev;
		}

		void disp(node* n) {
			while (n) {
				cout << n->val << ' ';
				n = n->next;
			}cout << endl;
		}
	public:
		linkedList() {
			insert(1, 0);
			insert(1, 0);
			insert(9, 0);

			insert(7, 1);
			insert(6, 1);
			insert(1, 1);

			disp(add(h0, h1, 0));
		}
	};

	/// <summary>
	/// insert/delete/search o(logn)
	/// </summary>
	class hashMap {
	private:
		struct node {
			int val;
			node* left;
			node* right;
			node(int v) {
				val = v;
				left = right = NULL;
			}
		};

		int size;
		node** table;

		int hash(int n) {
			return n % size;
		}

		void insert(int n, node* cn) {
			if (n < cn->val) {
				if (cn->left) {
					insert(n, cn->left);
				}
				else {
					cn->left = new node(n);
				}
			}
			else{
				if (cn->right) {
					insert(n, cn->right);
				}
				else {
					cn->right = new node(n);
				}
			}
		}
		void add(int n) {
			int index = hash(n);
			node* nn = table[index];
			if (nn) {
				insert(n, nn);
			}
			else {
				table[index] = new node(n);
			}
		}

		void bSearch(int n, node* cn) {
			if (cn->val == n) {
				cout << "found" << endl;
				return;
			}
			if (n < cn->val) {
				if (cn->left) {
					bSearch(n, cn->left);
				}
				else {
					cn->left = new node(n);
				}
			}
			else{
				if (cn->right) {
					bSearch(n, cn->right);
				}
				else {
					cn->right = new node(n);
				}
			}
		}
		void search(int n) {
			int index = hash(n);
			if (table[index]) {
				bSearch(n, table[index]);
			}
			else {
				cout << "not found" << endl;
			}
		}

	public:
		hashMap() {
			size = 10;
			table = new node* [size]();
			for (int i = 0; i < size; i++) {
				add(i);
			}
			search(11);
			add(11);
			search(11);
		}
	};

	/// <summary>
	/// push/pop: O(logn)
	/// </summary>
	class heapQ {
	private:
		struct node {
			int val;
			int pri;
			node(int v, int p) {
				val = v;
				pri = p;
			}
		};

		vector<node> pQueue;

		void siftUp(int pos) {
			int above = floor((pos - 1) / 2);
			while (above >= 0 and pQueue[pos].pri > pQueue[above].pri) {
				swap(pQueue[pos], pQueue[above]);
				siftUp(above);
			}
		}

		void siftDown(int pos) {
			int large = pos;
			int left = 2 * pos + 1;
			int right = 2 * pos + 2;
			if (left < pQueue.size() and pQueue[large].pri < pQueue[left].pri) {
				large = left;
			}
			if (right < pQueue.size() and pQueue[large].pri < pQueue[right].pri) {
				large = right;
			}
			if (large != pos) {
				swap(pQueue[pos], pQueue[large]);
				siftDown(large);
			}
		}

		void disp() {
			for (int i = 0; i < pQueue.size(); i++) {
				cout << pQueue[i].val << ' ';
			}cout << endl;
		}

	public:

		int pop() {
			int f = pQueue.front().val;
			node b = pQueue.back();
			pQueue.front() = b;
			pQueue.pop_back();
			siftDown(0);
			return f;
		}

		void push(int n, int p) {
			node nn(n, p);
			pQueue.push_back(nn);
			siftUp(pQueue.size() - 1);
		}

		heapQ() {
			for (int i = 0; i < 10; i++) {
				push(i, i);
			}
			disp();
			cout << pop() << endl;
			disp();
		}
	};

	fundamentals() {
		oop o;
		graph g;
		recursion r;
		sorting so;
		linkedList ll;
		hashMap hm;
		heapQ hq;

	}
};

int main() {
	fundamentals f;
	return 0;
}
