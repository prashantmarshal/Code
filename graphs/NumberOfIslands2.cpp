/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:

    vector<int> numIslands2(int Rows, int Cols, vector<Point> &operators) {
        vector<vector<int>> visited(Rows, vector<int>(Cols, 0));
        vector<pair<int, int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};

        int ans = 0;
        vector<int> res;

        for (auto pos: operators) {
            visited[pos.x][pos.y] = 1;
            bool found = false;
            for (auto dir: directions) {
                int x = pos.x+dir.first;
                int y = pos.y+dir.second;
                
                if(x < Rows && y < Cols && x >= 0 && y >= 0 && visited[x][y]) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                ans++;
            }
            res.push_back(ans);
        }

        return res;
    }
};