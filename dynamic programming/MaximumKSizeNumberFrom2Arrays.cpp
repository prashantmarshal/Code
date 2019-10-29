#include <bits/stdc++.h>
using namespace std;

#define  LEN 101
long int dp[LEN][LEN][LEN];

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int K) {

        int n = nums1.size(), m = nums2.size();
        for (int k = 1; k <= K; k++)
        {
            for (int i = 0; i <= n; i++)
            {
                for (int j = 0; j <= m; j++)
                {
                    if(i == 0 && j == 0){
                        dp[i][j][k] = 0;                        
                    } else if(i == 0){
                        dp[i][j][k] = dp[i][j-1][k-1] * 10 + nums2[j-1];
                        dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k]);
                    } else if(j == 0){
                        dp[i][j][k] = dp[i-1][j][k-1] * 10 + nums1[i-1];
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]);
                    } else{
                        dp[i][j][k] = max(dp[i-1][j][k-1] * 10 + nums1[i-1], dp[i][j-1][k-1] * 10 + nums2[j-1]);
                        dp[i][j][k] = max(dp[i][j][k], max(dp[i-1][j][k], dp[i][j-1][k]));
                    }
                }
            }
        }
        
        vector<int> v(K);
        int end = K;
        int i=n, j=m;
        while (end)
        {
            // implies i th character taken from nums1
            if(i > 0 && (dp[i][j][end] == dp[i-1][j][end-1] * 10 + nums1[i-1])) {
                v[end-1] = nums1[i-1];
                i--;
                end--;
            } else if(j > 0 && (dp[i][j][end] == dp[i][j-1][end-1] * 10 + nums2[j-1])) {
                v[end-1] = nums2[j-1];
                j--;
                end--;
            } else if(i > 0 && (dp[i][j][end] == dp[i-1][j][end])){
                i--;
            } else if(j > 0 && (dp[i][j][end] == dp[i][j-1][end])){
                j--;
            }
            
            i = max(0, i);
            j = max(0, j);
        }
        
        return v;
    }
};