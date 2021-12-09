// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

class Solution {
public:

    void _reverse(string &s, int l, int r) {
        int mid = (r - l)/2;
        for (int i = 0; i <= mid; i++) {
            swap(s[l+i], s[r-i]);
        }
    }

    string reverseParentheses(string str) {
        stack<int> s;

        for (int i = 0; i < str.size(); i++) {
            if(str[i] == '(') s.push(i);
            else if(str[i] == ')') {
                _reverse(str, s.top()+1, i-1);
                s.pop();
            }
        }

        string res = "";
        for (int i = 0; i < str.size(); i++) {
            if(str[i] != '(' && str[i] != ')') res += str[i];
        }
        return res;
    }
};

(abcd)

s = 0,