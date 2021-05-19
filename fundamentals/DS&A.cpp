using namespace std;

#include <iostream>

void heapify(int A[], int len, int x) {
	int largest = x;
	int left = 2 * x + 1;
	int right = 2 * x + 2;

	if (left < len && A[left] > A[largest]) {
		largest = left;
	}

	if (right < len && A[right] > A[largest]) {
		largest = right;
	}

	if (largest != x) {
		swap(A[x], A[largest]);
		
		heapify(A, len, largest);
	}
}

void heapsort(int A[], int len) {
	for (int i = (len / 2) - 1; i >= 0; i--) {
		heapify(A, len, i);
	}

	for (int i = len - 1; i >= 0; i--) {
		swap(A[i], A[0]);
		heapify(A, i, 0);
	}
}

int main(){
	int arr[] = {-1, 6, -9, 5, 7, 3, 0, 4, -3};
	int len = sizeof(arr) / sizeof(arr[0]);

	heapsort(arr, len);

	for (int i = 0; i < len - 1; i++) {
		cout << arr[i] << ',';
	}
	cout << arr[len - 1] << endl;

	return 0;
}
