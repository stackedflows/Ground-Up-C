public:
    int binarysearch(int a[], int n, int k){
        int R = n - 1;
        int L = 0;
        int m;
        while(L <= R){
            m = floor((L + R)/2);
            if(a[m] < k){
                L = m + 1;
            }
            else if(a[m] > k){
                R = m - 1;
            }
            else{
                return m;
            }
        }
        return -1;
    }
};
