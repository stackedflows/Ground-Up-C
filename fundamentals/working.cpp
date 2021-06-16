
#include <iostream>
#include <vector>

using namespace std;

class heapQ {
private:
	struct item {
		int val;
		int pri;
	};
	vector<item> heap;
	// O(logn)
	void siftUp(int i) {
		int above = (i - 1) / 2;
		if (above >= 0 and heap[i].pri > heap[above].pri) {
			swap(heap[i], heap[above]);
			siftUp(above);
		}
	}
	// O(logn)
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
			swap(heap[largest], heap[i]);
			siftDown(largest);
		}
	}
public:
	void push(item i) {
		heap.push_back(i);
		siftUp(heap.size() - 1);
	}
	int pop() {
		swap(heap[0], heap[heap.size() - 1]);
		int out = heap.back().val;
		heap.pop_back();
		return out;
	}
	void disp() {
		for (int i = 0; i < heap.size(); i++) {
			cout << heap[i].val << ':' << heap[i].pri << ' ';
		}cout << endl;
	}
	heapQ() {
		int a[] = { 1, 2, 8, 3, 0, 2, 6, 2, 6, 1, 5, 3, 5, 1 };
		int len = sizeof(a) / sizeof(a[0]);
		// top frequencies 1,2,3,6,5,8,0
		vector<item> freqs_;
		for (int i = 0; i < len; i++) {
			item it = {0, -1};
			freqs_.push_back(it);
		}
		for (int i = 0; i < freqs_.size(); i++) {
			if (freqs_[a[i]].pri == -1) {
				freqs_[a[i]].val = a[i];
				freqs_[a[i]].pri = 1;
			}
			else {
				freqs_[a[i]].pri++;
			}
		}
		for (int i = 0; i < freqs_.size(); i++) {
			if (freqs_[i].pri == -1) {
				continue;
			}
			else {
				cout << freqs_[i].val << ':' << freqs_[i].pri << ' ';
			}
		}
		for (int i = 0; i < freqs_.size(); i++) {
			if (freqs_[i].pri >= 0) {
				push(freqs_[i]);
			}
		}
		//disp();
		while (heap.size() > 0) {
			//cout << pop() << endl;
		}
	}
};

int main() {
	heapQ hq;
	return 0;
}
