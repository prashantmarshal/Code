class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curr = 1, size = nums.size();
        for (int i = 0; i < size-1; ++i) {
            curr = max(curr-1, nums[i]);
            if (curr == 0) return false;
        }
        return true;
    }
};