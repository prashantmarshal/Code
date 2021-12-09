class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int prefix = 0;
        unordered_map<int, int> m;

        m[0] = -1;
        for (int i = 0; i < n; ++i) {
            prefix = (prefix + nums[i])%k;
            if(m.count(prefix)) {
                if(i-m[prefix] >= 2) {
                    return true;
                }
            } else {
                m[prefix] = i;
            }
        }

        return false;
    }
};