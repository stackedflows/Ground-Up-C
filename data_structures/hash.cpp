#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// max size of hash map
#define MAX 1000

// hash map
int hash_map[MAX][2];

// search for element in array
bool search(int X){
  
  // X positive
  if(X >= 0){
    if(hash_map[X][0] == 1){
        return true; 
     }else{
        return false;
      }
  }  
  
  // X negative
  if(hash_map[abs(X)][1] == 1){
    return true; 
  }else{
    return false;
  }
}

// insert method
void insert(int a[], int n){
   for(int i = 0; i < n; i++){
     if(a[i] > 0){
       hash_map[a[i]][0] = 1;
     }else{
       hash_map[abs(a[i])][1] = 1;
     }
   }
}

// test methods
int main(){
    int a[] = { -1, 9, -5, -8, -5, -2 };
    int n = sizeof(a)/sizeof(a[0]);
    insert(a, n);
    int X = -5;
    if (search(X) == true)
       cout << "Present"; 
    else
       cout << "Not Present";
    return 0
}
