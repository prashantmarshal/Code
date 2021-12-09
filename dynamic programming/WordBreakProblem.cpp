class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (auto word: wordDict) dict.insert(word);

        int size = s.size();
        vector<bool>dp(size+1, 0);

        for (int i = 1; i <= size; i++) { // Considering size in each loop
            string current = "";
            for (int j = i; j > 0; j--) {
                current += s[j-1];
                if(dict.count(current) && dp[j-1]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[size];
    }
};