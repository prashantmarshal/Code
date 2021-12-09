// https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1);
        
        int k, ans = 0;
        for(int i = 1; i < n; ++i) {
            k = i;
            while(--k >= 0) {
                if (arr[k] < arr[i]) {
                    dp[i] = max(dp[i], dp[k]+1);
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};