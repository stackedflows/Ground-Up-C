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
    
  
### quicksort

    void quicksort(int a, int l, int r)
        if(l < r)
            int pivot = partition(a, l, r)
            quicksort(a, l, pivot - 1)
            quicksort(a, pivot + 1, r)
            
    int partition(int a, int l, int r)
        int pivot = a[r]
        int index = l
        for(int i = l; i < r; i++)
            if(a[l] > pivot)
                swap(a[l], a[index])
                index++
        swap(a[r], a[index])
        return index
        
    average/best case: each time the quicksort algorithm picks the middle element as pivot
        this means the tree is balanced and so is height log(n)
            algorihm passes n times
                time complexity is O(nlog(n))
                
    worst case: quicksort algorithm chooses leftmost element each time
        tree is right heavy
            each step n makes n - 1 comparisons
                time complexity n(n-1)/2

    space complexity:
        quicksort partitions the array into two:
            each call to partition generates a constant space complexity with the swap methods
                quicksort is called with an upper bound of n times
                
### heapsort

    void heapify(int a, int len, int x)
        int largest = x
        int left = 2x + 1
        int right = 2x + 2
        if(left < len && a[left] > a[largest])
            largest = left
        if(right < len && a[right] > a[largest])
            largest = right
        if(largest != x)
            swap(a[x], a[largest])
            heapify(a, len, largest)
            
    void heapsort(int a, int len)
        for(int i = (len/2) - 1; i >= 0; i--)
            heapify(a, len, i)
        for(int i = len - 1; i >= 0; i--)
            swap(a[0], a[len])
            heapify(a, i, 0)
            
    upper bound: height of heap is at most log(n)
        heapify is called O(n) times
            time complexity is O(nlog(n))
            
    space complexity: no extra space is required to run the algorithm, it operates on the original array only
        O(1)


### dfs

        time complexity: O(V + E)
        space complexity: O(V)
        
        dfs(g, v)
            v.discovered
            for w in v.neibours:
                if !w.discovered:
                    dfs(g, w)
                    
        for k in g.verticies:
            if !k.discovered:
                dfs(g, k)
                
###  bfs

        time complexity: O(V + E)
        space complexity: O(V)
        
        bfs(g, root):
            queue(verts) q
            root.discovered
            while(len(q) > 0):
                s = q.dequeue()
                for k in s.neibours:
                    if !k.discovered:
                        q.enqueue(k)
                        bfs(g, s)
