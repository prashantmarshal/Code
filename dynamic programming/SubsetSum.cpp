// https://leetcode.com/problems/partition-equal-subset-sum/

#include <bits/stdc++.h>
using namespace std;

int d[20001][20001];

bool canPartition(vector<int>& nums) {
    int sum = 0;
    int n = nums.size();

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }

    if(sum%2)
        return false;

    sum /= 2;

    for (int i = 0; i <= n; i++)
    {
        d[i][0] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j>= nums[i-1])
                d[i][j] = d[i-1][j-nums[i-1]] || d[i-1][j];
            else
                d[i][j] = d[i-1][j];
        }
    }

    return d[n][sum];        
}
