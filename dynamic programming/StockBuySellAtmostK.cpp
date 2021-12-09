class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int size = prices.size();
        
        if(k >= size/2) {
            int profit = 0;
            for(int i = 0; i < size-1; ++i) {
                if(prices[i+1] > prices[i]) profit += prices[i+1]-prices[i];
            }
            return profit;
        }
        
        vector<vector<int>> dp(size, vector<int>(k+1, 0)); // dp[size][k+1]

        for (int i = 1; i < size; i++) { // Day i
            for (int j = 1; j <= k; j++) { // Number of Transactions j
                int min_yet = prices[i], profit = 0; // Maximum profit with j transactions including i
                for (int index = i; index >= 0; index--) {
                    min_yet = min(min_yet, prices[index]);
                    profit = max(profit, dp[index][j-1] + prices[i] - min_yet);
                }
                dp[i][j] = max(profit, dp[i-1][j]); // Maximum profit with j transactions excluding i
            }
        }
        return dp[size-1][k];
    }
};