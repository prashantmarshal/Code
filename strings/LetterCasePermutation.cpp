// https://leetcode.com/problems/letter-case-permutation

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        res.push_back(s);

        for (int i = 0; i < s.size(); ++i) {
            if(s[i] >= '0' && s[i] <= '9') {
                continue;
            }

            int curr_size = res.size();
            for(int j = 0; j < curr_size; ++j) {
                string tmp = res[j];
                tmp[i] ^= 32;
                res.push_back(tmp);
            }
        }

        return res;
    }
};



class Solution {
public:

    void backtrack(string s, int start_index, vector<string> &res) {
        if (start_index == s.length()) {
            res.push_back(s);
            return;
        }

        backtrack(s, start_index+1, res);

        if(!(s[i] >= '0' && s[i] <= '9')) {
            s[start_index] ^= 32;
            backtrack(s, start_index+1, res);
        }
    }

    vector<string> letterCasePermutation(string s) {
        // Backtracking
        vector<string>res;
        backtrack(s, 0, res);
        return res;
    }
};

class Solution {
public:
    // Backtrack with for loop
    void backtrack(string s, int start_index, vector<string> &res) {
        res.push_back(s);

        // Performing operation within this stack and recursing
        for (int i = start_index; i < s.length(); ++i) {
            if(!(s[i] >= '0' && s[i] <= '9')) {
                s[i] ^= 32;
                backtrack(s, i+1, res);
                s[i] ^= 32;
            }
        }
    }

    vector<string> letterCasePermutation(string s) {
        // Backtracking
        vector<string>res;
        backtrack(s, 0, res);
        return res;
    }
};

