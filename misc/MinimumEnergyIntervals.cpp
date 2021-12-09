// https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/
class Solution {
    struct Compare {
        bool operator() (const vector<int> &a, const vector<int> &b) {
            return a[0]+b[1] < a[1]+b[0];
            // this is same as sorting by decreasing profit (a1-a0 > b1-b0)
        }
    };
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), Compare());

        int ans = 0, required = 0, remaining = 0, total = 0;
        for(auto it: tasks) {
            total += it[0];
            required = it[1];
            ans += max(0, required - remaining);
            remaining = ans-total;
        }

        return ans;
    }
};