# COMPLEXITY ANALYSIS

### bubble sort

    int a[] = {...}
    int n = len(a)
    
    void bubblesort(a, n)
        for(int i = 0; i < n; i++)
          for(int j = i; j < n - 1; j++)
            if(a[j] > a[j+1])
              int temp = a[j]
              a[j] = a[j+1]
              a[j+1] = temp

loop:

    passes n + n-1 + n-2 ... + 1 = n(n+1)/2 times
            
        time complexity: O(n^2)
            shifts quadratically based on size of input array
        
int temp:
    
        space complexity = O(1)
            does not shift based on size of input array
    
  