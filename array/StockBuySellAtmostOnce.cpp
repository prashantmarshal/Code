#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& A) {
    int maxr = 0, maxp = 0; //max element from right, max profit
    int n = A.size();

    for (int i = n-1; i >= 0; i--)
    {
        if(A[i] > maxr)
            maxr = A[i];
        
        maxp = max(maxp, maxr-A[i]);
    }

    return maxp;
}
