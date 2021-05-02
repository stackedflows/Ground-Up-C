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
// N: input array
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
