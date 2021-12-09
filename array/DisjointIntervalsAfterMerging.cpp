bool Compare(const vector<int> &a, const vector<int> &b) {
    return a[1] < b[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end(), Compare);
        
        int end = arr[0][1], ans = 1;
        for(auto it: arr) {
            if(it[0] <= end) continue;

            end = it[1];
            ans++;
        }

        return ans;
    }
};