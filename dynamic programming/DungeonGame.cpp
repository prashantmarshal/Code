class Solution {
public:
    
    // we should have at least one health available when we are at the
    // last index including the cost of that index. 
    
    // we create one extra row/col and make the required health for that row, col = 1
    // this is another way of making the row-1, col-1 index requiring 1+self_cost
        
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.size() == 0) return 0;
        int m = dungeon.size(), n = dungeon[0].size();

        vector<vector<int>> dp(m+1, vector<int> (n+1, INT_MAX));
        
        dp[m][n-1] = 1; dp[m-1][n] = 1;
        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                dp[i][j] = max(1, min(dp[i][j+1], dp[i+1][j]) - dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};