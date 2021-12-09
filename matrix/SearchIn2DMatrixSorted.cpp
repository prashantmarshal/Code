// https://leetcode.com/problems/search-a-2d-matrix/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // first find the row
        int Rows = matrix.size(); if (Rows == 0) return -1;
        int Cols = matrix[0].size();

        int l = 0, r = Rows-1;
        int midRow;
        while(l <= r) {
            midRow = (l + r) >> 1;
            if(target < matrix[midRow][0]) r = midRow-1;
            else if(target > matrix[midRow][Cols-1]) l = midRow+1;
            else break;
        }

        // midRow is the row, find the column
        l = 0, r = Cols-1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(matrix[midRow][mid] < target) l = mid+1;
            else if(matrix[midRow][mid] < target) r = mid-1;
            else return true;
        }

        return false;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // considering as an array
        int Rows = matrix.size(); if (Rows == 0) return -1;
        int Cols = matrix[0].size();

        int l = 0, r = Rows*Cols-1;

        while(l <= r) {
            int mid = (l + r) >> 1;
            if(target > matrix[mid/Cols][mid%Cols]) l = mid+1;
            else if (target < matrix[mid/Cols][mid%Cols]) r = mid-1;
            else return true;
        }

        return false;
    }
};

