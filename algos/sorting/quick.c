int partition(int arr[], int low, int high){
    // call the highest point the pivot
    int piv = arr[high];
    // initialise a counter
    int j = low;
    for(int i = low; i < high; i++){
        // if item in subarray is smaller than pivot, switch and move counter
        if(arr[i] < piv){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }
    // swap the counter and high point
    int temp = arr[j];
    arr[j] = arr[high];
    arr[high] = temp;
    // return new pivot
    return j;
}

//Function to sort an array using quick sort algorithm.
void quickSort(int arr[], int low, int high)
{
    if(low < high){
        // calculate partition point
        int piv = partition(arr, low, high);
        // sort arrays on either side of pivot recursively
        quickSort(arr, low, piv - 1);
        quickSort(arr, piv + 1, high);
    }
}
