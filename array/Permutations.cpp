// https://leetcode.com/problems/permutations/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // BFS queue approach
        vector<vector<int>> res;
        res.push_back(nums);

        vector<int> tmp;
        for (int i = 0; i < nums.size(); i++) {
            int size = res.size();
            for (int j = 0; j < res.size(); j++) {
                tmp = res[j];
                for (int k = i+1; k < nums.size(); k++) {
                    swap(tmp[i], tmp[k]);
                    res.push_back(tmp);
                    swap(tmp[i], tmp[k]);
                }
            }
        }

        return res;
    }
};


class Solution {
public:

    void permute(vector<int> nums, vector<vector<int>> &res, int start_index) {
        res.push_back(nums);

        for (int i = start_index; i < nums.size(); i++) {
            for (int k = i+1; k < nums.size(); k++) {
                swap(nums[i], nums[k]);
                permute(nums, res, i+1);
                swap(nums[i], nums[k]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permute(nums, res, 0);
        return res;
    }
};


class Solution {
public:

    void permute(vector<int> nums, vector<vector<int>> &res, int index) {
        if(index == nums.size()) res.push_back(nums);

        for (int i = index; i < nums.size(); i++) { // We are starting from the same index as we want to call "without-change" case also
            swap(nums[index], nums[i]);
            permute(nums, res, index+1);
            // swap(nums[index], nums[i]); Not needed because we just want to divide our problem into {curr_elelemnt} and [rest]
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permute(nums, res, 0);
        return res;
    }
};