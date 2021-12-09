// https://leetcode.com/problems/coin-change-2/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount+1, vector<int>(coins.size()+1, 0));

        for (int i = 0; i <= coins.size(); i++) dp[0][i] = 1;

        for (int sum = 0; sum <= amount; sum++) {
            for (int j = 1; j <= coins.size(); j++) {
                if (sum >= coins[j-1])
                    dp[sum][j] = dp[sum-coins[j-1]][j] + dp[sum][j-1];
                else
                    dp[sum][j] = dp[sum][j-1];
            }
        }

        return dp[amount][coins.size()];
    }
};