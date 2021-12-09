// https://www.interviewbit.com/problems/maximum-sum-square-submatrix/

int Solution::solve(vector<vector<int> > &matrix, int k) {
    int Rows = matrix.size();
    int Cols = matrix[0].size();

    int maxSum = INT_MIN;
    vector <int> prefixSum(Cols, 0);

    for(int i = 0; i < Rows-k+1; i++) {
        if(i == 0) {
            for(int j = 0; j < k; ++j) { // adding first k rows
                for(int c = 0; c < Cols; ++c) {
                    prefixSum[c] += matrix[j][c];
                }
            }
        } else {
            for(int c = 0; c < Cols; ++c) {
                prefixSum[c] += matrix[i+k-1][c] - matrix[i-1][c];
            }
        }

        /* 
        int sum = 0, j = 0;
        while(j < Cols) {
            sum += prefixSum[j];
            if (j-k >= 0) { // if current window size is greater than k
                sum -= prefixSum[j-k];
            }
            if (j >= k-1) {
                maxSum = max(maxSum, sum);
            }
            j++;
        }
        */
        
        int sum = 0;
        for (int j = 0; j < k; ++j) {
            sum += prefixSum[j];
        }
 
        // j = k;
        maxSum = max(maxSum, sum);
        for (int j = k; j < Cols; ++j) {
            sum += prefixSum[j] - prefixSum[j-k];
            maxSum = max(maxSum, sum);
        }
    }

    return maxSum;
}
