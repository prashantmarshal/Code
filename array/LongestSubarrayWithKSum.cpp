// https://www.lintcode.com/problem/911/description

class Solution {
public:

    int maxSubArrayLen(vector<int> &nums, int k) {
        
        unordered_map<int, int> sums;
        sums[0] = -1;

        int s = 0;
        int maxSize = 0;
        for (int i = 0; i < nums.size(); ++i) {
            s += nums[i];
            if (sums.find(s-k) != sums.end()) {
                maxSize = max(maxSize, i - sums[s-k]);
            } else if (sums.find(s) == sums.end()) {
                sums[s] = i;
            }
        }

        return maxSize;
    }
};