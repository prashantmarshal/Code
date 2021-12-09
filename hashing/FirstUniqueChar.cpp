class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> v(256, 0);
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (v[ch] > 0) 
                v[ch] = -1;
            else if (v[ch] == 0) 
                v[ch] = i+1;
        }

        int first = INT_MAX;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] > 0 && v[i] < first) first = v[i];
        }

        return first != INT_MAX ? first-1 : -1;
    }
};