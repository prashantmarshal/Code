// https://leetcode.com/problems/russian-doll-envelopes/

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty()) return 0;
        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(envelopes.size(), 1);
        
        int ans = 1;
        for (int i = 0; i < envelopes.size(); ++i)
            for (int j = 0; j < i; ++j)
                if (envelopes[j][0] < envelopes[i][0] && envelopes[j][0] < envelopes[i][0]) {
                    dp[i]  = max(dp[i] , dp[j] + 1);
                    ans = max(ans, dp[i]);
                }
        
        return ans;
    }
};