// impliments a bubble sort with an array ordered as a binary tree
// useful when we have high priority queues

#include <iostream>

using namespace std;

#define MAX 100

// in this array, each node has left child 2i + 1, right child 2i + 2
// each node has parent floor((i-1)/2)
int arr[MAX];

// tracks how many elements are inserted into heap
int count = 0;

// sorts heap
void sort(int position){
    if(count == 0){return;}
    else{
        int i = position - 1;
        int j = (position-1)/2;
        while(arr[j] > arr[i]){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i = (i-1)/2;
        }
    }
}

// handles insert
void insert(int data){
    if(count == MAX){
        return;
    }else{
        arr[count] = data;
        count++;
    }
    sort(count);
}

int main(){
    
    insert(10);
    insert(5);
    insert(13);
    insert(17);
    

    for(int i = 0; i < count; i++){
        cout << arr[i];
        cout << "\n";
    }

    return 0;
}
