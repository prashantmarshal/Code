// https://www.lintcode.com/problem/516

class Solution {
public:
    int minCostII(vector<vector<int>> &costs) {
        int n = costs.size();
        if(n == 0) return 0;
        int k = costs[0].size();

        vector<vector<int>> dp(n, vector<int>(k, 0)); // ith wall, jth color
        dp[0] = costs[0];

        for (int i = 1; i < n; ++i) {
            for(int j = 0; j < k; ++j) {
                int minval = INT_MAX;
                for(int l = 0; l < k; ++l) {
                    if(l != j)
                        minval = min(minval, dp[i-1][l]);
                }
                dp[i][j] = costs[i][j] + minval;
            }
        }

        int ans = INT_MAX;
        for (auto &item : dp[n-1]) {
            ans = min(ans, item);
        }
        return ans;
    }
};