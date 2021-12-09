// https://leetcode.com/problems/split-array-largest-sum/

class Solution {
public:

    vector<vector<int> >memo;

    int split(vector<int> &nums, int start, int k) {
        if (start == nums.size()) {
            return 0;
        }
        
        // Maximum partitions exhausted. 
        // Return a high value implying that the current combination is very costly
        if (k == 0) {
            return INT_MAX;
        }
        
        if (memo[start][k] != -1) {
            return memo[start][k];
        }

        int curr_sum = 0;
        int max_sum = INT_MAX;
        for (int i = start; i < nums.size(); i++) {
            curr_sum += nums[i];
            max_sum = min(max_sum, max(curr_sum, split(nums, i+1, k-1)));
        }

        memo[start][k] = max_sum;
        return max_sum;
    }

    int splitArray(vector<int>& nums, int m) {
        memo.resize(nums.size());
        for (int i = 0; i < memo.size(); i++) {
            memo[i].resize(m+1);
            for (int j = 0; j < m+1; j++) {
                memo[i][j] = -1;
            }
        }

        return split(nums, 0, m);
    }
};