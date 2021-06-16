#include <iostream>

using namespace std;

struct item {
	int val;
	int pri;
	item(int v, int p) {
		val = v;
		pri = p;
	}
};

class heapQ {
public:

	int tailIndex;
	int size;
	item* heap;
	
	void heapify(int i) {
		int largest = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		if (left < size and heap[largest].pri > heap[left].pri) {
			largest = left;
		}
		if (right < size and heap[largest].pri > heap[right].pri) {
			largest = right;
		}
		if (largest != i) {
			swap(heap[largest], heap[i]);
			heapify(largest);
		}
	}

	void bubble(int i) {
		int above = (i - 1) / 2;
		if (above >= 0 and heap[above].pri < heap[i].pri) {
			swap(heap[i], heap[above]);
			bubble(above);
		}
	}
public:
	void push(item item) {
		if (tailIndex < size) {
			heap[tailIndex] = item;
			heapify(0);
			tailIndex++;
		}
	}

	heapQ(item* arr) {

		size = 8;
		tailIndex = 0;
		heap = arr;

	}
};

int main() {

	int a[] = { 1, 2, 8, 3, 0, 2, 6, 2, 6, 1, 5, 3, 5, 4 };
	int len = sizeof(a) / sizeof(a[0]);

	int freqsCount = 8;
	item freqs[] = {
		item(1, 2),
		item(2, 3),
		item(8, 1),
		item(3, 2),
		item(0, 1),
		item(6, 2),
		item(5, 2),
		item(4, 1)
	};
  // should output
	// 2,1,3,6,5,8,0,4

	heapQ hq(freqs);

	for (int i = 0; i < freqsCount; i++) {
		hq.push(freqs[i]);
	}
	for (int i = 0; i < 8; i++) {
		cout << hq.heap[i].val << ' ';
	}cout << endl;

	return 0;
}
