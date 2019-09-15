#include<bits/stdc++.h>
using namespace std;


int removeDuplicates(vector<int> &A){
    int x = A.size();
    
    if(x <= 1)
        return x;

    int lastval = A[0];
    int j = 1;
    for (int i = 1; i < x; i++)
    {
        if(A[i] == lastval) {
            continue;
        }
        lastval = A[i];
        A[j++] = lastval;
    }

    return j;
}