class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int with_curr = 0, without_curr = 0, with_previous = 0, without_previous = 0;

        dp[0][0]=arr[0];
        int res = 0;
        for(int i = 0; i < arr.size(); i++) { 
            with_curr = max(arr[i], with_previous + arr[i]);
            
            without_curr = max(arr[i], max(without_previous))
            dp[i][0]=max(arr[i], dp[i-1][0]+arr[i]);
            dp[i][1]=max(arr[i], max(dp[i-1][1]+arr[i], dp[i-1][0]));
            res=max(res, max(dp[i][0], dp[i][1])); 
        }
        return res;
    }
};