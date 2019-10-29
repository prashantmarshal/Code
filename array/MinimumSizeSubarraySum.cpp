#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int i=0,j=0;
        int sum=0,minlen=INT_MAX;
        int n=nums.size();

        while(j<n){
            while(j<n && sum<k){
                sum+=nums[j];
                j++;
            }

            while(i<n && sum>=k){
                minlen = min(minlen, j-i);
                sum-=nums[i];
                i++;
            }
        }
        return minlen;
    }
};