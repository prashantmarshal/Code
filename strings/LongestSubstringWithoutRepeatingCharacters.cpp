#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = -1, right = 0;
        int curr = 0, max_len = 0;
        
        int len = s.length();
        bool chars[26];
        memset(chars, 0, sizeof(chars));
        
        while(right < len) {
            if (chars[s[right]]) {                                
                left++;
                while(s[left] != s[right]) {
                    chars[s[left]] = 0;
                    left++;
                }
            }
            chars[s[right]] = 1;
            curr = max(curr, right-left);
            max_len = max(max_len, curr);
        }
        
        return max_len;
    }
};