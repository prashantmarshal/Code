// https://leetcode.com/problems/longest-continuous-increasing-subsequence/class Solution {
    
class Solution {
public:
    int findLengthOfLCIS(vector<int>& arr) {
        int ans = 1, n = arr.size();
        int len = 1;
        for(int i = 1; i < n; ++i) {
            if(arr[i] > arr[i-1]) {
                len++;
            } else {
                ans = max(ans, len);
                len = 1;
            }
        }
        ans = max(ans, len);
        return ans;
    }
};
