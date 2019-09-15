// https://www.interviewbit.com/problems/minimize-the-absolute-difference/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int i = 0, j = 0, k = 0;
    int a, b, c;
    int mindiff = INT_MAX;

    while (i < A.size() && j < B.size() && k < C.size()) {
        
        a = A[i];
        b = B[j];
        c = C[k];

        mindiff = min(mindiff, abs(max(a,max(b,c))-min(a,min(b,c))));

        if(a <= b && a <= c){
            i++;
        }
        else if(b <= c && b <= a){
            j++;
        }
        else if(c <= a && c <= b){
            k++;
        }
    }

    return mindiff;  
    
}