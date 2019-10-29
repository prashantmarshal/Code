// https://leetcode.com/problems/as-far-from-land-as-possible/
#include <bits/stdc++.h>
using namespace std;

int dist[101][101];
typedef pair<int, int> tup;

int directions[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        memset(dist, 10000, 101*101);
        int size = grid.size();
        queue<tup>q;

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if(grid[i][j] == 1) {
                    q.push(make_pair(i,j));
                    dist[i][j] = 0;
                }
            }
        }

        if(q.empty() || q.size() == size*size) return -1;

        while(!q.empty()){
            tup t = q.front();
            q.pop();

            int x = t.first, y = t.second;
            for (int i = 0; i < 4; i++)
            {
                if(x+directions[i][0] < 0 || x+directions[i][0] >= size ||
                    y+directions[i][1] < 0 || y+directions[i][1] >= size)
                    continue;

                if(dist[x+directions[i][0]][y+directions[i][1]] > dist[x][y] + 1) {
                    dist[x+directions[i][0]][y+directions[i][1]] = dist[x][y] + 1;
                    q.push(make_pair(x+directions[i][0],y+directions[i][1]));
                }
            }            
        }

        int res = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                res = max(res, dist[i][j]);
            }
            
        }
        
        return res;
    }
};