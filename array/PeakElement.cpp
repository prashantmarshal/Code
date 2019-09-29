// https://www.interviewbit.com/problems/find-a-peak-element/

#include <bits/stdc++.h>
using namespace std;

int l[100001], r[100001];

int solve(vector<int> &A) {
    int size = A.size();
    
    int currmax = 0;

    for (int i = 0; i < size; i++)
    {
        l[i] = currmax;
        currmax = max(currmax, A[i]);
    }

    currmax = 0;
    for (int i = size-1; i >= 0; i--)
    {
        r[i] = currmax;
        currmax = max(currmax, A[i]);
    }
    
    for (int i = 0; i < size; i++)
    {
        if(A[i]>= max(l[i], r[i]))
        return A[i];
    }
    
    return -1;
}
