// https://leetcode.com/problems/edit-distance/

class Solution {
public:

    vector<vector<int>> dp;
    int utilRecursive(string word1, string word2, int i, int j) {
        if(i < 0) return j+1;
        if(j < 0) return i+1;

        if(dp[i][j] != -1) return dp[i][j];
        
        if(word1[i] == word2[j]) {
            dp[i][j] = utilRecursive(word1, word2, i-1, j-1);
        } else {
            dp[i][j] = 1 + min(utilRecursive(word1, word2, i-1, j-1), // replace and recurs for i-1,j-1
                               min(utilRecursive(word1, word2, i, j-1), // replace and recurs for i, j-1
                               utilRecursive(word1, word2, i-1, j))); // replace and recurs for i-1, j
        }

        return dp[i][j];
    }

    int minDistance(string word1, string word2) {
        dp.resize(word1.length());
        for (int i = 0; i < word1.length(); i++) {
            for (int j = 0; j < word2.length(); j++) dp[i].push_back(-1);
        }

        return utilRecursive(word1, word2, word1.size()-1, word2.size()-1);
    }

    int minDistance(string word1, string word2) {
        // Iterative DP solution
        int R = word1.length(); 
        int C = word2.length();
        vector<vector<int>> dp;
        dp.resize(R+1); 
        for (int i = 0; i <= R; i++) {
            dp[i].resize(C+1, 0);
        }
        
        for (int i=0; i<=R; ++i) {
            for(int j=0; j<=C; ++j) {
                if(i==0 || j==0) {
                    dp[i][j] = max(i, j);
                } else if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + min(dp[i-1][j-1],
                                        min(dp[i-1][j], dp[i][j-1]));
                }
            }
        }
        return dp[R][C];
    }
};