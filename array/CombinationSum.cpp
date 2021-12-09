class Solution {
public:

    vector<vector<int> > res;

    void util(vector<int> &candidates, int sum, int index, vector<int> &ret) {
        if(sum<0) return;
        if(sum==0) {res.push_back(ret); return;}
        if(index == candidates.size()) return;

        for(int i=index; i<candidates.size(); i++){
            ret.push_back(candidates[i]);
            util(candidates, sum-candidates[i], i, ret); // Important
            ret.pop_back();

            while(i+1<candidates.size() && candidates[i] == candidates[i+1]) i++;
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ret;
        sort(candidates.begin(), candidates.end());
        util(candidates, target, 0, ret);
        return res;
    }
};