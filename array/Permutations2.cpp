// https://leetcode.com/problems/permutations-ii/

lass Solution {
public:

    void permute(vector<int> nums, vector<vector<int>> &res, int index) {
        if(index == nums.size()) res.push_back(nums);

        for (int i = index; i < nums.size(); i++) { // We are starting from the same index as we want to call "without-change" case also
            if(index != i && nums[index] == nums[i]) continue;
            swap(nums[index], nums[i]);
            permute(nums, res, index+1); 
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        permute(nums, res, 0);
        return res;
    }
};


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back(nums);

        for(int i = 0; i < nums.size(); i++) { 
            int size = res.size(); // Replace elements at ith position for all the current elements in res
            for (int j = 0; j < size; j++) {
                vector<int> tmp = res[j];
                for (int k = i+1; k < nums.size(); k++) {
                    if (tmp[i] == tmp[k]) continue;
                    swap(tmp[i], tmp[k]);
                    res.push_back(tmp);
                }
            }
        }

        return res;
    }
};