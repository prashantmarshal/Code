// https://leetcode.com/problems/maximal-square/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int> >dp;
        dp.resize(matrix.size());
        for (int i = 0; i < matrix.size(); i++) dp[i].resize(matrix.size(), 0);

        int maxSize = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                if(i == 0) dp[i][j] = matrix[i][j]-'0';
                else if(j == 0) dp[i][j] = matrix[i][j]-'0';
                else dp[i][j] = (matrix[i][j] == '1') ? (min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1) : 0;
                maxSize = max(maxSize, dp[i][j]);
            }
        }

        return maxSize*maxSize;
    }
};