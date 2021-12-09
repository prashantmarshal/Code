// https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    struct Compare {
        bool operator() (vector<int> &a, vector<int> &b) {
            return a[0] < b [0];
        }
    };
	
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), Compare());
        
		vector<vector<int>> res;
        vector<int> curr = intervals[0];
        
        for (auto it: intervals) {
            if(curr[1] >= it[0]) {
                curr[1] = max(curr[1], it[1]);
            } else {
                res.push_back(curr);
                curr = it;
            }
        }
        res.push_back(it);
  
        return res;
    }
};