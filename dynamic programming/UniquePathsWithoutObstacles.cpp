// https://leetcode.com/problems/unique-paths/

int d[101][101];
int uniquePaths(int m, int n) {
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i == 0 || j == 0) {
                d[i][j] = 1;
            }else{
                d[i][j] += d[i-1][j-1];
            }
        }
    }
    return d[n-1][m-1];    
}
