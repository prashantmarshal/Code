// https://leetcode.com/problems/rotate-array/
class Solution {
public:

    void _swap(vector<int> &nums, int start, int end) {
        // starting from index 'start',
        // do swapping for these many times:
        // No. of elements/2 = (end - start + 1)/2        
        for (int i = 0; i < (end - start + 1)/2; i++) {
            swap(nums[start + i], nums[end - i]);
        }
    }

    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        _swap(nums, 0, nums.size() - 1);
        _swap(nums, 0, k - 1);
        _swap(nums, k, nums.size() - 1);
    }
};


class Solution 
    {
    public:
        void rotate(int nums[], int n, int k) 
        {
            k = k%n;

            reverse(nums, nums + n - k);
            reverse(nums + n - k, nums + n);
            reverse(nums, nums + n);
        }
    };