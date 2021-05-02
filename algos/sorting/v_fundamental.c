#include<stdio.h>
#include<stdbool.h>

// is array sorted?
// time complexity o(n)
bool arraySortedOrNot(int arr[], int n) {
    for(int i = 0; i < n - 1; i++){
        if(arr[i + 1] < arr[i]){
            return 0;
        }
    }
    return 1;
}

// A[]: input array
// N: input size
//Function to sort the binary array.
// time complexity o(2N)
// space complexity N
void binSort(int A[], int N)
{   
    int count_0 = 0;
    for(int i = 0; i < N; i++){
        if(A[i] == 0){
            count_0++;
        }
    }
    for(int i = 0; i < N; i++){
        if(i < count_0){
            A[i] = 0;
        }else{
            A[i] = 1;
        }
    }
}

//Function to sort the array using bubble sort algorithm.
void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++){
        int curr = arr[i];
        int temp = arr[i + 1];
        int count = 0;
        while(curr > temp){
            arr[i + 1] = curr;
            arr[i] = temp;
            temp = arr[i + count + 1];
            count++;
        }
    }    
}

//Heap sort

 void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }

void heapify(int arr[], int n, int i) {
    // Find largest among root, left child and right child
    
    // root = arr[i]
    // left child of arr[i] = arr[2i + 2]
    // right child of arr[i] = arr[2i + 1]

    // find largest of 3 elements
    // Find largest among root, left child and right child
    int root = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[root])
      root = left;
  
    if (right < n && arr[right] > arr[root])
      root = right;
  
    // Swap and continue heapifying if root is not largest
    if (root != i) {
      swap(&arr[i], &arr[root]);
      heapify(arr, n, root);
    }
}

// Main function to do heap sort
void buildHeap(int arr[], int n) {
    
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
  
      // Heapify root element to get highest element at root again
      heapify(arr, i, 0);
    }
}
