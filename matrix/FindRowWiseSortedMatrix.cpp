// https://leetcode.com/problems/search-a-2d-matrix/

#include <bits/stdc++.h>
using namespace std;

bool searchRow(vector<int>&v, int target){
    int low = 0, high = v.size()-1;
    while(low <= high) {
        int mid = low + (high-low)/2;

        if(v[mid] == target){
            return true;
        } else if (v[mid] < target){
            low = mid+1;
        } else
        {
            high = mid-1;
        }
    }
    return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int R = matrix.size();
    if (R == 0){
        return false;
    }

    int C = matrix[0].size();
    if (C == 0){
        return false;
    }
    
    int top = 0, bottom = R-1;
    int high = C-1;// for column

        // binary search for row
    while (top <= bottom)
    {
        int mid = top+(bottom-top)/2;

        if(matrix[mid][0] <= target && matrix[mid][high] >= target){
            return searchRow(matrix[mid], target);
        } else if(matrix[mid][0] > target) {
            bottom = mid-1;
        } else {
            top = mid+1;
        }
    }

    return false;
    
}

int main(int argc, char const *argv[])
{
    return 0;
}
