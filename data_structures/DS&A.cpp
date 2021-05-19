using namespace std;

#include <iostream>

class OOP {
private:
    int x = 2;
public:
    int y = 1;

    void abstract(int _x) {
        x = _x;
        cout << x << endl;
    }
};

class inherit : public OOP {
public:
    void inherits() {
        cout << y << endl;
        }
};

class poly {
protected:
    int x = 0;
public:
    poly(int _x = 0) {
        x = _x;
    }
    virtual int property() {
        return 0;
    }
};

class child_0 : public poly {
public:
    child_0(int _x = 0) : poly(_x) {}
    int property() {
        cout << x << endl;
        return x;
    }
};

class child_1 : public poly {
public:
    child_1(int _x = 0) : poly(_x) {}
    int property() {
        cout << x + 1 << endl;
        return x + 1;
    }
};

class sort {
public:
    void quicksort(int A[], int start, int end) {
        if (start >= end)return;
        int pivot = partition(A, start, end);
        quicksort(A, start, pivot - 1);
        quicksort(A, pivot + 1, end);
    }

    int partition(int A[], int start, int end) {
        int pivot = A[end];
        int p_index = start;
        for (int i = start; i < end; i++) {
            if (A[i] < pivot) {
                int temp = A[i];
                A[i] = A[p_index];
                A[p_index] = temp;
                p_index++;
            }
        }
        int _temp = A[end];
        A[end] = A[p_index];
        A[p_index] = _temp;
        return p_index;
    }

    void mergesort(int A[], int len) {
        if (len < 2) return;
        int mid = len / 2;
        int* L = new int[mid]();
        int* R = new int[len - mid]();
        for (int i = 0; i < mid; i++) {
            L[i] = A[i];
        }
        for (int i = mid; i < len; i++) {
            R[i - mid] = A[i];
        }
        mergesort(L, mid);
        mergesort(R, len - mid);
        merge(L, mid, R, len - mid, A);
    }

    void merge(int L[], int nL, int R[], int nR, int A[]) {
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < nL && j < nR) {
            if (L[i] < R[j]) {
                A[k] = L[i];
                i++;
            }
            else {
                A[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < nL) {
            A[k] = L[i];
            i++;
            k++;
        }
        while (j < nR) {
            A[k] = R[j];
            j++;
            k++;
        }
    }

    void print(int A[], int len) {
        for (int i = 0; i < len - 1; i++) {
            cout << A[i] << ',';
        }
        cout << A[len - 1] << endl;
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
    stack(int n) {
        head = NULL;
        struct node * init = new struct node;
        init->data = n;
        init->next = NULL;
    }

    void push(int n) {
        struct node* new_head = new struct node;
        new_head->data = n;
        new_head->next = head;
        head = new_head;
    }

    int pop() {
        int popped = head->data;
        if (popped == NULL) {
            cout << "pop err" << endl;
            return -1;
        }
        struct node* new_head = head->next;
        head = new_head;
        return popped;
    }

    bool search(int n) {
        struct node* curr = head;
        if (curr == NULL) {
            cout << "search err" << endl;
            return false;
        }
        while (curr != NULL) {
            if (curr->data == n) {
                cout << "true" << endl;
                return 0;
            }
            curr = curr->next;
        }
        cout << "false" << endl;
        return false;
    }
};

class linked_list {
private:
    struct node {
        int data;
        struct node* next;
    };

    struct node* head;

public:
    linked_list(int n) {
        head = NULL;
        struct node* new_head = new struct node;
        new_head->data = n;
        new_head->next = NULL;
        head = new_head;
    }

    void add(int n) {
        struct node* new_head = new struct node;
        new_head->data = n;
        new_head->next = head;
        head = new_head;
    }

    void remove() {
        if (head == NULL) { return; }
        struct node* new_head = head->next;
        head = new_head;
    }

    bool search(int n) {
        struct node* curr = head;
        if (curr == NULL) {
            cout << "false" << endl;
        }
        while (curr != NULL) {
            if (curr->data == n) {
                cout << "true" << endl;
                return true;
            }
            curr = curr->next;
        }
        cout << "false" << endl;
        return false;
    }
};

int main(){
    OOP o;
    inherit i;
    poly* p;
    child_0 c0(1);
    child_1 c1(1);

    o.abstract(5);

    i.inherits();

    p = &c0;
    p->property();

    p = &c1;
    p->property();

    sort s;

    int A0[] = { 1,2,4,-2,6,-2,-7,2,-2 };
    int len = sizeof(A0) / sizeof(A0[0]);

    s.quicksort(A0, 0, len - 1);
    s.print(A0, len);

    int A1[] = { 1,2,4,-2,6,-2,-7,2,-2 };

    s.mergesort(A1, len);
    s.print(A1, len);

    stack stk(1);

    for (int i = 0; i < 5; i++) {
        stk.push(i);
    }

    stk.search(8);

    linked_list ll(7);

    for (int i = 0; i < 13; i++) {
        ll.add(i);
    }

    ll.search(2);
}
