class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];

        int ans = 0;
        int left = 0, right = 0, res = 0;

        // Taking 1st element
        for(int i=0; i<nums.size()-1; ++i){
            res = max(res, max(nums[i] + left, right));
            left = right;
            right = res;
        }
        
        ans = max(ans, res);
        left = 0; right = 0; res = 0;

        for(int i=1; i<nums.size(); ++i){
            res = max(res, max(nums[i] + left, right));
            left = right;
            right = res;
        }

        ans = max(ans, res);
        return ans;
    }
};
