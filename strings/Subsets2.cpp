// https://leetcode.com/problems/subsets-ii/

class Solution {
public:

    void util(int curr, vector<int> &nums, vector<int> &tmp, vector<vector<int>> &res) {
        res.push_back(tmp);

        for (int i = curr; i < nums.size(); ++i) {
            if (i > curr && nums[i] == nums[i-1]) {
                continue;
            }

            tmp.push_back(nums[i]);
            util(i+1, nums, tmp, res);
            tmp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        vector<vector<int>> res;
        util(0, nums, tmp, res);
        return res;
    }
};



class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Solving via BFS queue
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> tmp;

        res.push_back(tmp);

        int curr_size = 1, start_pos = 0;
        for (int i = 0; i < nums.size(); i++) { // Creating subsets by appending each element to the already created subsets
            // We should skip the duplicates only if the current element was not considered for append, and that is, from [0, curr_size-1]
            start_pos = 0;

            // If current element is same as the previous element, append to only those subsets which include the previous element
            if (i > 0 && nums[i-1] == nums[i]) {
                start_pos = curr_size;
            }

            curr_size = res.size();

            for (int j = start_pos; j < curr_size; ++j) { // Iterate over each subset
                tmp = res[j];
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
        }

        return res;
    }
};

