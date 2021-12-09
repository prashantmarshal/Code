// https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k

class Solution {
public:

    int maxSumSubarray(vector<int>& sum, int k) {

        int maxSum = INT_MIN;
        // generate prefix sum array
        vector<int> prefixSum(sum.size(), 0);
        prefixSum[0] = sum[0];
        for (int i = 1; i < sum.size(); i++) {
            prefixSum[i] += prefixSum[i-1] + sum[i];
        }

        // searching for maximum sum subarray ending at i
        // prefixSum[i] - prefixSum[j] <= k
        // the difference should approach as near as possible to k
        // hence, prefixSum[i] - k <= prefixSum[j]
        // for every i, find such a j

        set <int> bst; // balanced search tree - insert all the elements of prefixSum till i-1
        bst.insert(0);
        for (int i = 0; i < prefixSum.size(); i++) {
            auto iter = bst.lower_bound(prefixSum[i]-k);
            if (iter != bst.end()) {
                maxSum = max(maxSum, prefixSum[i] - *iter);
            }
            bst.insert(prefixSum[i]);
        }

        return maxSum;
    }

    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.size()==0) return 0;
        
        int maxSum = INT_MIN;

        for (int sr = 0; sr < matrix.size(); ++sr) {
            vector<int> sum(matrix[0].size(), 0);
            for (int r = sr; r < matrix.size(); ++r) {
                for (int c = 0; c < matrix[0].size(); ++c) {
                    sum[c] += matrix[r][c];
                }
                maxSum = max(maxSum, maxSumSubarray(sum, k));
            }
        }

        return maxSum;
    }
};



int Solution::solve(vector<vector<int> > &A) {
    if(A.size()==0) return 0;
    int count=0;
    int n=A.size(),m=A[0].size();
    for(int i=0;i<n;i++){
        vector<int>dp(A[0].size(),0);
        for(int j=i;j<n;j++){
            for(int k=0;k<m;k++) dp[k]+=A[j][k];
            map<int,int>mp;
            int sum=0;
            mp[0]=1;
            for(int k=0;k<m;k++){
                sum+=dp[k];
                count+=mp[sum];
                mp[sum]++;
            }
        }
    }
    return count;
}