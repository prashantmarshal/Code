// https://leetcode.com/problems/search-a-2d-matrix-ii/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        int Rows = matrix.size(); int Cols = matrix[0].size();

        int r = 0, col = Cols-1;
        while(r >= 0 && r < Rows && col >= 0 && col < Cols) {
            if(matrix[r][col] == target) return true;
            if(matrix[r][col] < target) r++;
            else col--;
        }

        return false;
    }
};