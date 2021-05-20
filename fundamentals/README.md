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

first loop:

    passes n times
    
inner loop:

    passes n + n-1 + n-2 ... + 1 times
            
        time complexity: O(n) * O(n) = O(n^2)
            shifts quadratically bases on size of input array
        
int temp:
    
        space complexity = O(1)
            does not shift based on size of input array
    
  
