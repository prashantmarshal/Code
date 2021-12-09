// https://leetcode.com/problems/maximum-length-of-pair-chain/
class Solution {
    struct Compare {
        bool operator() (vector<int> &a, vector<int> &b) {
            return a[0] < b [0];
        }
    };
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), Compare());
        int ans = 0;
        vector<int> curr = {INT_MIN, INT_MIN};
        for (auto& pair : pairs) {
            if(curr[1] < pair[0]) {
                curr = pair;
                ans++;
            }
        }

        return ans;
    }
};