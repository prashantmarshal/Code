// https://www.interviewbit.com/problems/diffk/

#include <bits/stdc++.h>
#include<unordered_set>
using namespace std;

int diffPossibleSortedArray(vector<int> &A, int B) {
    int i = 0, j = 1;
    
    while(i < A.size() && j < A.size())
    {
        if(i != j && A[j]-A[i] == B)
            return 1;
        else if(A[j]-A[i] < B)
            j++;
        else 
            i++;
    }
    
    return 0;
}


int diffPossible(vector<int> &A, int B) {
    unordered_set<int>t;

    for (int i = 0; i < A.size(); i++)
    {
        if((t.count(A[i]+B) > 0) || (t.count(A[i]-B)>0))
            return 1;
        else t.insert(A[i]);
    }
    return 0;
}