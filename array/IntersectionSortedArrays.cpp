// https://www.interviewbit.com/problems/intersection-of-sorted-arrays/
#include<bits/stdc++.h>
using namespace std;


vector<int> intersect(const vector<int> &A, const vector<int> &B) {
    vector<int>v;

    int x = A.size(), y = B.size();
    int i=0,j=0;

    while(i<x && j<y){
        if(A[i]==B[j]){
            v.push_back(A[i]);
            i++;j++;
        } else if(A[i]<B[j]){
            i++;
        }else{
            j++;
        }
    }
    
    return v;
}