class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int size = nums.size();
        vector<int> v(nums.begin(), nums.end());
        sort(v.begin(), v.end());
        unordered_map<int, int> hash;

        int prev = -1;
        for (int i = 0; i < size; i++) {
            if(v[i] != prev)
                hash[v[i]] = i;
            prev = v[i];
        }

        vector<int> result;
        for (int i = 0; i < size; i++) {
            result.push_back(hash[nums[i]]);
        }

        return result;
    }
};