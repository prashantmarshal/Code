#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        int size = arr.size();

        //Segregate +ve -ve
        int i = -1, j = 0;
        for(; j < size; ++j){
            if(arr[j] <= 0) swap(arr[++i], arr[j]);
        }

        for (j = i+1; j < size; j++)
        {
            int e = abs(arr[j]);
            if(e < size-i) // e+i < size gives integer overflow
                arr[e+i] = -1*abs(arr[e+i]);
        }

        for (j = i+1; j < size; j++)
        {
            if(arr[j] > 0) return j-i;
        }
        return size-i;
    }
};