class Solution {

    int countNumberOfSmallerElements(vector<vector<int>> &arr, int target) {
        int row = 0, col = arr.size()-1;
        int cnt = 0;
        int num = arr[0][col];
        while(true) {
            if(target > num) {
                row++;
                cnt += col+1;
            }
            else if(target < num) {
                col--;
            } else {
                cnt += col;
            }
        }
        return cnt;
    }

public:

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0]0], high = matrix[n-1][n-1];

        while(low <= high) {
            int mid = (low + high) >> 1;
            // Check if there are k numbers lesser than mid
            // If mid is not the exact element found in the matrix, return an upper bound
            
            int cnt = countNumberOfSmallerElements(matrix, mid);
            if(cnt < k) low = mid+1;
            else if (cnt >= k) high = mid-1;
        }
    }
};