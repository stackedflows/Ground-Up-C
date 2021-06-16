#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class heapQ {
private:
	struct item {
		int val;
		int pri;
	};
	vector<item> heap;
	void siftUp(int i) {
		int above = floor((i - 1) / 2);
		if (above >= 0 and heap[i].pri > heap[above].pri) {
			swap(heap[i], heap[above]);
			siftUp(above);
		}
	}
	void siftDown(int i) {
		int largest = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		if (left < heap.size() and heap[largest].pri < heap[left].pri) {
			largest = left;
		}
		if (right < heap.size() and heap[largest].pri < heap[right].pri) {
			largest = right;
		}
		if (largest != i) {
			swap(heap[i], heap[largest]);
			siftDown(largest);
		}
	}
public:
	void push(item i) {
		heap.push_back(i);
		siftUp(heap.size() - 1);
	}
	int pop() {
		int top = heap.front().val;
		item bottom = heap.back();
		heap.front() = bottom;
		heap.pop_back();
		siftDown(0);
		return top;
	}

	heapQ() {
		int a[] = { 1,2,6,3,0,2,8,2,8,5,7,3,0,4,2,6,3 };
		int len = sizeof(a) / sizeof(a[0]);
		vector<item> pFreqs;
		for (int i = 0; i < len; i++) {
			item it;
			it.pri = -1;
			pFreqs.push_back(it);
		}
		
		for (int i = 0; i < pFreqs.size(); i++) {
			if (pFreqs[a[i]].pri == -1) {
				pFreqs[a[i]].pri = 1;
				pFreqs[a[i]].val = a[i];
			}
			else {
				pFreqs[a[i]].pri++;
			}
		}
		for (int i = 0; i < pFreqs.size(); i++) {
			if (pFreqs[i].pri != -1) {
				push(pFreqs[i]);
			}
		}
		while (heap.size() > 0) {
			cout << pop() << endl;
		}
	}
};

int main() {
	heapQ hq;
	return 0;
}
