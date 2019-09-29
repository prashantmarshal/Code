// https://leetcode.com/problems/increasing-triplet-subsequence/

#include <bits/stdc++.h>
using namespace std;

// if left minimum exists
bool leftmin[100001];

bool increasingTriplet(vector<int>& arr) {
    int n = arr.size();
    if(n <= 2)
        return false;
    
    memset(leftmin, 0, n);
    
    int currmin = arr[0];

    for (int i = 1; i < n; i++)
    {
        if(arr[i] > currmin) {
            leftmin[i] = true;
        } else if(arr[i] < currmin){
            currmin = arr[i];
        }
    }
    
    int currmax = arr[n-1];
    for (int i = n-2; i >= 0; i--)
    {
        if(arr[i] < currmax && leftmin[i]) {
            return true;
        } else if(arr[i] > currmax){
            currmax = arr[i];
        }
    }

    return false;
}


/*
bool increasingTriplet(vector<int>& nums) {
    int min = INT_MAX;
    int mid= INT_MAX;
    for(int n : nums){
        if(n<min)min=n;
        else if(n>min && n<mid) mid=n;
        else if(n>mid) return true;
    }
    return false;
}
*/