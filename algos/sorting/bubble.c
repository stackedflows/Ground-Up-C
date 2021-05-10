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
