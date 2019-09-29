// https://leetcode.com/problems/unique-paths-ii/submissions/

long long d[101][101];

    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m <= 0)
            return m;
        
        int n = matrix[0].size();
                
        if(matrix[0][0] == 1)
            return 0;
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(matrix[i][j]){
                    d[i][j] = 0;
                } else if(!matrix[i][j] && !i && !j){
                    d[i][j] = 1;
                } else if(!matrix[i][j] && !i){
                    d[i][j] = d[i][j-1];
                } else if(!matrix[i][j] && !j){
                    d[i][j] = d[i-1][j];
                } else {
                    d[i][j] = d[i-1][j] + d[i][j-1];
                }
            }
        }
        return d[m-1][n-1]; 
    }


// idea is to set d[i][j] = 0 whenever we see obstacles
// also for first row and first column, if there's any obstacle in between, then positions ahead of them will be 0 as they can't be reached