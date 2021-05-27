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

    time complexity: O(n^2)
    
    space complexity: O(1)
  
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
        
    time complexity: O(n^2)
                

    space complexity: O(n)
                
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
            
    time complexity: O(nlog(n))
    
    space complexity: O(n)

### mergesort

    
    time complexity: O(nlog(n))
    
    space complexity: O(n)
    
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
            q.enqueue(root)
            while(len(q) > 0):
                s = q.dequeue()
                for k in s.neibours:
                    if !k.discovered:
                        k.discovered
                        q.enqueue(k)
                        
