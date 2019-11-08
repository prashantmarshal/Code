#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n==0 || k == 0) return 0;
        
        int **dp = new int*[n];
        for (int i = 0; i < n; i++)
            dp[i] = new int[k+1];

        for (int i = 0; i <= k; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(i == 0){
                    dp[j][i] = 0; // No transaction allowed
                } else {
                    dp[j][i] = dp[j][i-1]; // Set base value excluding this transaction

                    // Assume we sell at this index
                    int minval = prices[j];
                    for (int l = j-1; l >= 0; l--)
                    {
                        dp[j][i] = max(dp[j][i], dp[l][i-1] + prices[j] - minval);
                        minval = min(prices[l], minval);
                    }
                    dp[j][i] = max(dp[j][i], prices[j] - minval);

                    /* 
                    if(j > 0)
                        dp[j][i] = max(dp[j][i], dp[j-1][i]); // If not doing transaction on this day
                    */
                }
            }
            
        }

        int maxval = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < k+1; j++)
                maxval = max(maxval, dp[i][j]);

        return maxval;
    }
};