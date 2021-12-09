// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

class Solution {
public:
    multiset<int> m;

    bool okay(int limit) {
        if (abs(*m.begin() - *m.rbegin()) <= limit) return true;
        return false;
    }

    int longestSubarray(vector<int>& nums, int limit) {
        int size = nums.size(); if(size == 0) return 0;
        int l = 0, r = -1;
        int maxSize = 0;

        while(r < size-1) {
            r++;
            m.insert(nums[r]);

            if(okay(limit)) {
                maxSize = max(maxSize, r-l+1);
                continue;
            }
            while(l <= r && !okay(limit)) {
                m.erase(m.find(nums[l]));
                l++;
            }
        }

        return maxSize;
    }
};