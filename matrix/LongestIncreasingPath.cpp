// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int DFS(vector<vector<int>>& matrix, int x, int y, vector<vector<int>> &dp){
        if(dp[x][y]) return dp[x][y];

        int maxval = 0;
        if(x >= 1 && matrix[x-1][y] > matrix[x][y]) {
            maxval = max(maxval, DFS(matrix, x-1, y, dp));
        }

        if(x < matrix.size()-1 && matrix[x+1][y] > matrix[x][y]) {
            maxval = max(maxval, DFS(matrix, x+1, y, dp));
        }

        if(y >= 1 && matrix[x][y-1] > matrix[x][y]) {
            maxval = max(maxval, DFS(matrix, x, y-1, dp));
        }

        if(y < matrix[0].size()-1 && matrix[x][y+1] > matrix[x][y]) {
            maxval = max(maxval, DFS(matrix, x, y+1, dp));
        }

        dp[x][y] = 1+maxval;
        
        return dp[x][y];

    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if(!rows) return 0;

        int cols = matrix[0].size();
        int result = 0;

        vector<vector<int>> dp(rows,vector<int>(cols, 0));
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result = max(result, DFS(matrix, i, j, dp));
            }
        }
    
        return result;
    }
};