#include <iostream>

using namespace std;

//// class for sorting algorithms and their complexity analysis
class sort {
public:
    
    // Heap sort implimentatiion and complexity analysis
    void heapify(int a[], int len, int x) {
        int largest = x; // O(1)
        int left = 2 * x + 1; // O(1)
        int right = 2 * x + 2;  // O(1)

        if (left < len && a[left] > a[largest]) {
            largest = left; 
        }
        if (right < len && a[right] > a[largest]) {
            largest = right; 
        }
        if (largest != x) {
            swap(a[x], a[largest]); // O(1)
            heapify(a, len, largest); // O(log(n))
        }
        // worst case time: left and right are at the bottom of the tree, and are the largest elements, then: O(log(n))
        // worst case space: O(1)
    }
    
    void heapsort(int a[], int len) {
        for (int i = (len / 2) - 1; i >= 0; i--) {
            heapify(a, len, i);
        }  // worst case time: (n/2) * log(n) 
        // worst case space: O(1)
        for (int i = len - 1; i >= 0; i--) {
            swap(a[i], a[0]);
            heapify(a, i, 0);
        } // worst case time: n * log(n)
        // worst case space: O(n)

        // total asymptotic time complexity: O(nlogn)
        // total asymptotic space complexity: O(n)
    }

    // Merge sort implimentation and analysis
    void merge(int l[], int nl, int r[], int nr, int a[]) {
        int i = 0; // O(1)
        int j = 0; // O(1)
        int k = 0; // O(1)

        while (i < nl && j < nr) {
            if (l[i] < r[j]) {
                a[k] = l[i];
                i++;
            }
            else {
                a[k] = r[j];
                j++;
            }
            k++;
        } // worst case time complexity: l[0]/r[0] is the smallest element: max(nl, nr) iterations
        while (i < nl) {
            a[k] = l[i];
            i++;
            k++;
        } // worst case time complexity: nr == 0, then we set O(nl)
        while (j < nr) {
            a[k] = r[j];
            j++;
            k++;
        } // worst case time complexity: nl == 0, then we set O(nr)

        // total time complexity: O(n)
        // total space complexity O(1)
    }

    void mergesort(int a[], int len) {
        if (len < 2)return;
        int mid = len / 2; // O(1)
        int* l = new int[mid](); // O(n)
        int* r = new int[len - mid](); // O(n)

        for (int i = 0; i < mid; i++) {
            l[i] = a[i];
        } // worst case time complexity: O(n)
        for (int i = mid; i < len; i++) {
            r[i - mid] = a[i];
        } // worst case time complexity: O(n)

        mergesort(l, mid); // called untill mid < 2: O(log(n))
        mergesort(r, len - mid); // O(log(n))
        merge(l, mid, r, len - mid, a); // O(n)

        // total asymptotic time complexity: O(nlog(n))
        // total asymptotic space complexity: O(n)
    }

    // quicksort implimentation with complexity analysis
    int partition(int a[], int start, int end) {
        int pivot = a[end]; // O(1)
        int pIndex = start; // O(1)
        for (int i = start; i < end; i++) {
            if (a[i] > pivot) {
                swap(a[i], a[pIndex]); // O(1)
                pIndex++;
            }
        } // worst case time complexity: O(n)
        swap(a[end], a[pIndex]); // O(1)
        return pIndex;
    }

    void quicksort(int a[], int start, int end) {
        if (start >= end)return;
        int pivot = partition(a, start, end); // time complexity: O(n)
        // space complexity: O(1)
        quicksort(a, start, pivot - 1); // called untill start >= end: worst case, pivot is the largest element: n calls, n - 1 comparisons
        quicksort(a, pivot + 1, end); // O(n^2)

        // total asymptotic time complexity: O(n^2)
        // total asymptotic space complexity: O(log(n))
    }
};

//// section for Object Orientated Principles
class OOP {
private:
    int encap = 1;
public:
    void abstract(int e) {
        encap = e;
    }
};

// inheritance
class inherit : public OOP {};

// polymorphism
class poly {
protected:
    int x = 0;
public:
    poly(int _x = 0) {
        x = _x;
    }
    virtual int prop() {
        return 0;
    }
};

class child0 : public poly {
public:
    child0(int _x = 0) : poly(_x) {}
    int prop() {
        return x + 1;
    }
};

class child1 : public poly {
public:
    child1(int _x = 0) : poly(_x){}
    int prop() {
        return x * 10;
    }
};

//// data structures section
class linked_list {
private:
    struct node {
        int data;
        struct node* next;
    };
    struct node* head;
public:
    linked_list() {
        head = NULL;
    }
    void add(int n) {
        struct node* nn = new struct node;
        nn->data - n;
        nn->next = head;
        head = nn;
    }
    bool search(int n) {
        struct node* nn = head;
        while (nn != NULL) {
            if (nn->data == n)return true;
            nn = nn->next;
        }
        return false;
    }
};

class stack {
private:
    struct node {
        int data;
        struct node* next;
    };
    struct node* head;
public:
    stack() {
        head = NULL;
    }
    void push(int n) {
        struct node* nn = new struct node;
        nn->data = n;
        nn->next->head;
        head = nn;
    }
    int pop() {
        if (head == NULL) {
            cout << "empty" << endl;
            return 0;
        }
        int popped = head->data;
        struct node* nn = head->next;
        head = nn;
        return popped;
    }
    bool search(int n) {
        int p = pop();
        while (p != NULL) {
            if (p == n)return true;
            p = pop();
        }
        return false;
    }
};

int main() {

    return 0;
}
