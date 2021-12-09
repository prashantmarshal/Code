// https://leetcode.com/problems/split-array-largest-sum/

class Solution {
public:
    
    // return true if we don't need more than k subarrays to accomodate
    // 'sum' in each subarray
    bool isValid(vector<int> &nums, int k, int sum) {
        int count = 1;
        int curr_sum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            curr_sum += nums[i];
            if(curr_sum > sum) {
                count++;
                curr_sum = nums[i];
            }
        }

        return (count <= k);
    }

    int splitArray(vector<int>& nums, int m) {
        
        int minSum = INT_MIN, maxSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            minSum = max(minSum, nums[i]);
            maxSum += nums[i];
        }

        // subarray sums would be in range [minSum, maxSum]
        // we greedily find the lowest possible subarray sum
        // such that all the m subarrays have sum less than that
        // we don't require more than m subarrays

        int low = minSum, high = maxSum;
        while(low <= high) {
            int mid = (low + high)/2;

            if(isValid(nums, m, mid)) {
                // save this potential sum and greed for lesser
                minSum = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return minSum;
    }
};