#include <iostream>

using namespace std;

// various primes for hash function
#define P0 17
#define P1 701
#define P2 1001

// max size of hash map
#define MAX 10000

// hash structure
int hash_map[MAX][2];

// hash the input
int _hash(int X){
    int h = (int) (P0 * X * P1 / P2 + P2);
    return h;
}

// search the hash map
bool search(int X){
    int h_code = _hash(X);
    
    if(h_code >= 0){
        if(hash_map[h_code][0] == 1){
            return true;
        }else{
            return false;
        }
    }
    
    if(hash_map[abs(h_code)][1] == 1){
        return true;
    }else{
        return false;
    }
}

// insert new inputs into hash map
void insert(int arr[], int n){
    for(int i = 0; i < n; i++){
        int h_code = _hash(arr[i]);
        if(h_code > 0){
            hash_map[h_code][0] = 1;
        }else{
            hash_map[abs(h_code)][1] = 1;
        }
    }
}

// test medthods
int main(){
    int a[] = {1 ,2 ,4 ,-2 ,-12 ,123 ,-443};
    int len = sizeof(a)/sizeof(a[0]);
    insert(a, len);
    if(search(5)){
        cout << "true";
    }else{
        cout << "false";
    }
    return 0;
}

