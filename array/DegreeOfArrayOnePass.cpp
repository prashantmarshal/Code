class Solution {
public:
    int findShortestSubArray(vector<int>& nums, int k) {
        unordered_map<int, vector<int> >shortest;

        int degree = 0;
        int shortestSubarray = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            shortest[nums[i]].push_back(i);
            if(shortest[nums[i]].size() >= degree) {
                shortestSubarray = min(shortestSubarray, i-shortest[nums[i]][0]+1);
                degree = max(degree, (int)shortest[nums[i]].size());
            }
        }
        return shortestSubarray;
    }
};