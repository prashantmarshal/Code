#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;   
        }
        
        int curr_sum = nums[0], max_sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            curr_sum = max(curr_sum + nums[i], nums[i]);
            max_sum = max(max_sum, curr_sum);
        }
        
        return max_sum;
    }
};

// Approach:
// We want to provided the maximum value subarray to the rest of the array.
// Hence, either [previous+current] OR [current] is selected.