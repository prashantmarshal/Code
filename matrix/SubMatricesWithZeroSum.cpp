// https://www.interviewbit.com/problems/sub-matrices-with-sum-zero/

int calculateZeroSubarrays(vector<int>& A) {
    unordered_map<int,int>f;

    int curr_sum = 0, cnt = 0;
    f[curr_sum] = 1;

    for (int i = 0; i < A.size(); i++)
    {
        curr_sum = curr_sum + A[i];
        int freq = f[curr_sum];
        cnt += freq;
        f[curr_sum]++;
    }

    return cnt;  
}

int Solution::solve(vector<vector<int> > &matrix) {
    if (matrix.size() == 0) return 0;
    
    int numMatrices = 0;

    for (int sr = 0; sr < matrix.size(); sr++) {
        vector<int> sum(matrix[0].size(), 0);
        for (int r = sr; r < matrix.size(); r++) {
            for (int c = 0; c < matrix[0].size(); c++) {
                sum[c] += matrix[r][c];
            }
            numMatrices += calculateZeroSubarrays(sum);
        }
    }

    return numMatrices;
}

