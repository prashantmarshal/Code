class Solution {
public:

    int N;
    vector<vector<vector<int>>> dp;

    int util(vector<vector<int>> &grid, int r1, int c1, int c2) {
        int r2 = r1 + c1 - c2;

        // If moving to a location breached matrix boundaries, return INT_MIN (-INF cherries collected)
        if(r1 >= N || c1 >= N || r2 >= N || c2 >= N || grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return INT_MIN;
        if (dp[r1][c1][c2] != -1)
            return dp[r1][c1][c2];

        // Return if we have reached the final cell. 
        if (r1 == N-1 && c1 == N-1) return dp[r1][c1][c2] = grid[r1][c1];

        int ans = grid[r1][c1];
        if(r1 != r2)
            ans += grid[r2][c2]; // Add grid[i][j] if both positions are not same
            
        int temp = max(util(grid, r1+1, c1, c2), util(grid, r1+1, c1, c2+1));
        temp = max(temp, util(grid, r1, c1+1, c2));
        temp = max(temp, util(grid, r1, c1+1, c2+1));
        
        ans += temp;

        return dp[r1][c1][c2] = ans;
    }


    int cherryPickup(vector<vector<int>>& grid) {
        N = grid.size();
        dp.resize(N);
        for(int i = 0; i < N; i++) dp[i].resize(N, vector<int>(N, -1));
        return max(0, util(grid, 0, 0, 0));
    }
};