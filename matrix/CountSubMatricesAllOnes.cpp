// https://leetcode.com/problems/count-square-submatrices-with-all-ones/

int calculateKSumSubarrays(vector<int> &sum, int target) {
    unordered_map<int, int> f;
    f[0] = 1;

    int curr_sum = 0, count = 0;

    for (int i = 0; i < sum.size(); i++) {
        curr_sum += sum[i];
        // check for current 'sum - k' key in map
        count += f[curr_sum - target];
        f[curr_sum]++;
    }

    return count;
}

class Solution {
public:
    int numSubmat(vector<vector<int>>& matrix, int target) {
        int R = 0, row = 0, col = 0;
        int numMatrices = 0;

        for (int row = 0; row < matrix.size(); ++row) {
            for (int col = 0; col < matrix[0].size(); ++col) {
                matrix[row][col] = matrix[row][col] ? 0 : 1;
            }
        }
    
        for (int R = 0; R < matrix.size(); ++R) {
            vector<int> sum(matrix[0].size(), 0);
            for (int row = R; row < matrix.size(); ++row) {
                for (int col = 0; col < matrix[0].size(); ++col) {
                    sum[col] += matrix[row][col];
                }
                numMatrices += calculateKSumSubarrays(sum, 0);
            }
        }
        
        return numMatrices;
    }
};