#include <bits/stdc++.h>
using namespace std;

#define INF 100000

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(amount+1, vector<int>(coins.size()+1, 0));

        for (int sum = 0; sum <= amount; sum++){
            for (int i = 0; i <= coins.size(); i++){
                if(sum == 0) 
                    dp[sum][i] = 0;
                else if(i == 0) 
                    dp[sum][i] = INF;
                else {
                    if(sum-coins[i-1] >= 0)
                        dp[sum][i] = min(dp[sum][i-1], 1 + dp[sum-coins[i-1]][i]);
                    else
                        dp[sum][i] = dp[sum][i-1];
                }
            }
        }

        return dp[amount][coins.size()] == INF?-1:dp[amount][coins.size()];
    }
};

int topDown(vector<int>& coins, vector<vector<int>>&dp, int sum, int index){
    if(sum == 0) return 0;
    if(index == coins.size()) return INF;
    
    if(dp[sum][index]!=-1) 
        return dp[sum][index];

    if(sum - coins[index] >= 0){
        dp[sum][index] = min(1 + topDown(coins, dp, sum - coins[index], index), topDown(coins, dp, sum, index+1));
    } else {
        dp[sum][index] = topDown(coins, dp, sum, index+1);
    }
    return dp[sum][index];
}

int coinChange(vector<int>& coins, int amount) {
    vector<vector<int>>dp(amount+1, vector<int>(coins.size(), -1));
    int res = topDown(coins, dp, amount, 0);
    return res == INF?-1:res;
}


// https://leetcode.com/problems/coin-change/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(amount+1, vector<int>(coins.size()+1, 0));
        
        // If amount > 0 and we don't have any coins (array is empty),
        // we require infinite selections from that empty array
        for (int i = 1; i <= amount; i++) dp[i][0] = INT_MAX-1;
        // If amount == 0, we require 0 selections
        for (int i = 0; i <= coins.size(); i++) dp[0][i] = 0;

        for (int sum = 0; sum <= amount; sum++) {
            for (int j = 1; j <= coins.size(); j++) {
                if (sum-coins[j-1] >= 0)
                    dp[sum][j] = min(1 + dp[sum-coins[j-1]][j], dp[sum][j-1]);
                else
                    dp[sum][j] = dp[sum][j-1];
            }
        }

        return dp[amount][coins.size()] == INT_MAX-1 ? -1 : dp[amount][coins.size()];
    }
};