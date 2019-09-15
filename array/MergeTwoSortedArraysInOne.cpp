#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &A, vector<int> &B) {
    int x = A.size();
    int y = B.size();
    A.resize(x+y);
    
    int i = x-1, j=y-1, k = x+y-1;
    
    while (i>=0 && j>=0)
    {
        if(A[i] >= B[j]){
            A[k] = A[i];
            i--;
            k--;
        } else {
            A[k] = B[j];
            j--;
            k--;            
        }
    }
    
    while(i >= 0){
        A[k] = A[i];
        i--;
        k--;
    }

    while(j >= 0){
        A[k] = B[j];
        j--;
        k--;
    }
    
}
