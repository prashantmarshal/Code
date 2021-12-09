class Solution {
public:
    vector<pair<int, int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    vector<vector<int>> visited;
    int Rows, Cols;
    int dfs(vector<vector<int>> &grid, int i, int j) {
        if (i >= Rows && j >= Cols) return 0;
        if (visited[i][j]) return 0;
        if (grid[i][j] == 0) return 0;

        visited[i][j] = true;

        int ans = 0;
        for (auto dir: directions) {
            dfs(grid, i+dir.first, j+dir.second);
        }

        return 1;
    }

    int numIslands(vector<vector<char>>& grid) {
        Rows = grid.size();
        Cols = grid[0].size();
        visited.resize(Rows, vector<int>(Cols, 0));

        int ans = 0;
        for (int i = 0; i < Rows; i++) {
            for (int j = 0; j < Col; j++) {
                ans += dfs(grid, i, j);
            }
        }

        return
    }
};