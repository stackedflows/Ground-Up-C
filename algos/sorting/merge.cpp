class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        //new array sizes
        int n1 = m - l + 1;
        int n2 = r - m;
        
        // arrays to be sorted
        int L[n1], R[n2];
        
        // copy arrays within recursive restraints
        for(int i = 0; i < n1; i++){
            L[i] = arr[l + i];
        }
        for(int j = 0; j < n2; j++){
            R[j] = arr[m + 1 + j];
        }
        
        // merge arrays back into main array
        //tracks array L
        int i = 0;
        // tracks array M
        int j = 0;
        // tracks overall array
        int k = l;
        
        // will sort the main part of the output array
        while(i < n1 && j < n2){
            if(L[i] <= R[j]){
                arr[k] = L[i];
                i++;
            }else{
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        
        // handle remaining L elements
        while(i < n1){
            arr[k] = L[i];
            i++;
            k++;
        }
        
        // handle remaining M elements
        while(j < n2){
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l>=r){
            return;//returns recursively
        }
        int m =l+ (r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
};
