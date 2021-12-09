bool Compare (const vector<int> &a, const vector<int> &b) {
    return a[1] < b[1];
}

class Solution {
public:

    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<int>dp(n+1, 0);
        sort(arr.begin(), arr.end(), Compare);

        for (int i = 1; i <= n; ++i) {
            int k = i-1;
            while(k > 0 && arr[i-1][0] < arr[k-1][1]) {
                dp[i] = max(dp[i], dp[k--]);
            }
            if(k >= 0) dp[i] = max(dp[i], dp[k]+1);
        }

        return n-dp[n];
    }
};

bool Compare (const vector<int> &a, const vector<int> &b) {
    return a[1] < b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end(), Compare);

        int end = INT_MIN, ans = 0;
        for (auto it: arr)
            if(it[0] >= end) end = it[1];
            else ans++;

        return ans;
    }
};