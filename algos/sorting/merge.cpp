class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        
        int n1 = m - l + 1;
        int n2 = r - m;
        
        int L[n1], M[n2];
        
        // copy arrays from 
        for(int i = 0; i < n1; i++){
            L[i] = arr[l + i];
        }
        for(int i = 0; i < n2; i++){
            M[i] = arr[m + 1 + i];
        }
        
        
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        // 
        if(l >= r){
            return;
        }
        // calculate new midpoint and seperate arrays
        int mid = l + (r - 1) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        // merge new sorted arrays
        merge(arr, l, mid, r);
    }
};
