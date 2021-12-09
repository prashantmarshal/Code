class Solution {
public:
    unordered_set<string> dict;
    unordered_map<string, vector<string>> m;
    
    vector<string> util(string s) {
        if(m.find(s) != m.end()) return m[s];
        if (s == "") return vector<string>();

        vector<string> result;
        for(int i = 0; i < s.size(); i++) {
            if(dict.count(s.substr(0, i+1))) {
                if (i == s.size()-1) {
                    result.push_back(s.substr(0, i+1));
                } else {
                    vector<string> tmp = util(s.substr(i+1));
                    for(auto it: tmp) result.push_back(s.substr(0, i+1) + " " + it);
                }
            }
        }
        
        m[s] = result;

        return result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto it: wordDict) dict.insert(it);
        return util(s);
    }
};

class Solution {
public:

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(auto it: wordDict) dict.insert(it);
        vector<vector<string>> dp(s.size());

        for(int i = 0; i < s.size(); i++) {
            for(int j = i-1; j >= 0; j--) {
                if(dict.count(s.substr(j+1, i-j))) {
                    for (auto it: dp[j]) {
                        dp[i].push_back(it + " " + s.substr(j+1, i-j));
                    }
                }
            }
            if(dict.count(s.substr(0, i+1))) {
                dp[i].push_back(s.substr(0, i+1));
            }
        }

        return dp[s.size()-1];
    }
};

