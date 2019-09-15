#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& A) {
    int totalp = 0;

    int n = A.size(), i = 0;
    if(n == 0)
        return totalp;

    while(i < n){
        // find minima
        int curr_min = A[i];
        while(A[i] <= curr_min) {
            curr_min = A[i];
            i++;
            if(i == n)
                return totalp;
        }

        // find maxima

        int curr_max = A[i];
        while(A[i] >= curr_max){
            curr_max = A[i];
            i++;
            if(i == n)
                break;
        }

        totalp += curr_max-curr_min;
        // now i points to next phase of local minima and maxima
    }

    return totalp;
}

