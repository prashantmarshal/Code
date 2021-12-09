// https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sums;
        sums[0]++; // 0 sum is already present

        int cum_sum = 0, count = 0; // cumulative sum
        for (int i = 0; i < nums.size(); i++) {
            cum_sum += nums[i];
            count += sums[cum_sum-k];
            sums[cum_sum]++;
        }

        return count;
    }
};