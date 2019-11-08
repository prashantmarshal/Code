// https://leetcode.com/problems/next-permutation

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return;
        int i = n-1;

        while(i > 0 && nums[i-1] >= nums[i]) {
            i--;
        }

        if(i == 0){
            return sort(nums.begin(), nums.end());
        }
        
        int j = i-1;
        int min_index = i;
        while(i < n){
            if(nums[i] < nums[min_index] && nums[i] > nums[j]){
                min_index = i;
            }
            i++;
        }
        
        swap(nums[j], nums[min_index]);
        sort(nums.begin()+j+1, nums.end());
    }
};