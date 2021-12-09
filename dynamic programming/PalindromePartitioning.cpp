class Solution {
public:
    
    bool isPalin(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return s == t;
    }
    
    void util(vector<vector<string>> &res, vector<string> &tmp, string s) {
        if(s == "") {
            res.push_back(tmp);
            return;
        }
        
        for(int i = 0; i < s.size(); i++) {
            if(isPalin(s.substr(0, i+1))) {
                tmp.push_back(s.substr(0, i+1));
                util(res, tmp, s.substr(i+1));
                tmp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> tmp;
        util(res, tmp, s);
        return res;
    }
};

class Solution {
public:
    vector<vector<bool>> dp;
    void util(vector<vector<string>> &res, vector<string> &tmp, string &s, int index) {
        if(index == s.size()) {
            res.push_back(tmp);
            return;
        }
        
        for(int i = index; i < s.size(); i++) {
            if(dp[index][i]) {
                tmp.push_back(s.substr(index, i-index+1));
                util(res, tmp, s, i+1);
                tmp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        dp.resize(s.size(), vector<bool>(s.size(), false));
        for (int i = 0; i < s.size(); i++) dp[i][i] = true;

        for(int L = 2; L <= s.size(); L++) {
            for(int i = 0; i < s.size()-L+1; i++) {
                int j = i+L-1;
                if((L == 2 && s[i] == s[j]) || 
                   (s[i] == s[j] && dp[i+1][j-1])) dp[i][j] = true;
            }
        }
        
        vector<vector<string>> res;
        vector<string> tmp;
        util(res, tmp, s, 0);
        return res;
    }
};

