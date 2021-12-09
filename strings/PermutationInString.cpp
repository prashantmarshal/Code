// https://leetcode.com/problems/permutation-in-string/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int size = s2.length();
        vector<int> m(256, 0);
        for(char ch: s1) m[ch]++;

        int l = 0, K = s1.length();
        for(int r = 0; r < size; ++r) {
            char right = s2[r];
            if(--m[right] >= 0) K--; // suppressed the histogram

            if(r-l+1 > s1.length()) { // since fixed size window, remove left if size > K
                char left = s2[l++];
                if (++m[left] > 0) K++; // since > 0, removing this char leaves it uncovered
            }

            if(K == 0) {
                return true;
            }
        }
        return false;
    }
};