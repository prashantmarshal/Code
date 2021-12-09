class Solution {
public:
    string minWindow(string s, string t) {
        int size = s.length(), K = t.length(), start = 0, l = 0, minLength = INT_MAX;
        vector<int> m(256, 0);
        for(char ch: t) m[ch]++;

        for(int r = 0; r < size; r++) {
            char right = s[r];
            if(--m[right] >= 0) K--; // s[r] is present in t

            while(K == 0 && l <= r) { // try moving l ahead
                if (minLength > r-l+1) {
                    start = l;
                    minLength = r-l+1;
                }

                char left = s[l++];
                if(++m[left] > 0) K++;
            }
        }
        return minLength == INT_MAX ? "" : s.substr(start, minLength);
    }
};