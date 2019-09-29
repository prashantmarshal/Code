// https://leetcode.com/problems/longest-palindromic-subsequence/

#include <bits/stdc++.h>
using namespace std;

int d[1001][1001];

int longestPalindromeSubseq(string s) {
    int n = s.size();
    
    for (int i = 0; i < n; i++)
    {
        d[i][i] = 1;
    }
    
    for (int i = 0; i < n-1; i++)
    {
        if(s[i] == s[i+1])
            d[i][i+1] = 2;
    }
    
    for(int len = 3; len <= n; len++){
        for (int i = 0; i <= n-len+1; i++)
        {
            if(s[i] == s[i+len-1]){
                d[i][i+len-1] = 2 + d[i+1][i+len-2];
            }else{
                d[i][i+len-1] = max(d[i+1][i+len-1], d[i][i+len-2]);
            }
        }
    }
    return d[0][n-1];
}