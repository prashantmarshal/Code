#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        int size = arr.size();

        //Segregate +ve -ve
        int i = -1, j = 0;
        for(; j < size; ++j){
            if(arr[j] > 0) swap(arr[++i], arr[j]);
        }

        // i points to right most positive element
        for (j = 0; j <= i; j++)
        {
            int e = abs(arr[j]);
            if(e <= i+1)
                arr[e-1] = -1*abs(arr[e-1]);
        }

        for (j = 0; j <= i; j++)
        {
            if(arr[j] > 0) return j+1;
        }
        return i+1;
    }
};