// https://leetcode.com/problems/combination-sum-iii/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<vector<int>> res;
        vector<int> tmp;

        res.push_back(tmp);

        for (int i = 1; i <= 9; i++) {
            int size = res.size();
            for (int j = 0; j < size; ++j) {
                tmp = res[j];
                
                // Push into res (probable answer) conditionally
                // 1. Number of elements shouldnot be more than k
                // 2. Sum should not be more than n
                tmp.push_back(i);
                res.push_back(tmp);
            }
        }
        
        for (auto it : res) {
            if (it.size() == k && accumulate(it.begin(), it.end(), 0) == n) {
                ans.push_back(it);
            }
        }
        
        return ans;
    }
};