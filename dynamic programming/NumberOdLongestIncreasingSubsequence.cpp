class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size(), ans;
        vector<int> dp(n, 1); // length of the longest subsequence ending at each element
        vector<int> dc(n, 1); // count of the longest subsequences ending at element
        unordered_map<int, int> m;
        m[1] = n;
        
        for(int i = 0; i < n; ++i) {
            int k = i;
            while(--k >= 0) {
                if(arr[i] > arr[k]) {
                    int curr_length = dp[k]+1; // current length is this element + max length at element arr[k]
                    if(curr_length > dp[i]) { // if current length exceeds the max length seen till now, update the count array
                        dc[i] = dc[k];
                    } else if (curr_length == dp[i]) { // if current length is seen previously, add the count
                        dc[i] += dc[k];
                    }

                    dp[i] = max(dp[i], curr_length); // update the max length for future uses
                    m[curr_length] += dc[k];
                }
            }
            ans = max(ans, dp[i]);
        }

        return m[ans];
    }
};
