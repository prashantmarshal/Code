// https://leetcode.com/problems/partition-array-for-maximum-sum/

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int K) {
        int size = arr.size();
        if(size == 0) return 0;
        
        vector<int> dp(size+1, 0);

        for(int i = 1; i <= size; i++) { // building on problem size
            int curr_max = 0, best = 0;
            for(int k = 1; k <= K && k <= i; ++k) { // subarray size
                curr_max = max(curr_max, arr[i-k]);
                best = max(best, dp[i-k] + curr_max*k);
            }
            dp[i] = best;
        }
        return dp[size];
    }
};