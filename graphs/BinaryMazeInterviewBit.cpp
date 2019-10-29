#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dirs = {{0,1}, {0,-1}, {-1,0}, {1,0}};
void dfs(vector<vector<int>>& M, vector<int> start, vector<vector<int>>& dist){
    int m = M.size(), n=m>0?(M[0].size()):0;
    for(vector<int> dir: dirs){
        int x = start[0] + dir[0],
            y = start[1] + dir[1];
        int count = 0; /// go as much as you can
        while(x>=0 && y>=0 && x<m && y<n && M[x][y]==0){
            x += dir[0],
            y += dir[1];
            count++;
        }
        if(dist[start[0]][start[1]] + count < dist[x-dir[0]][y-dir[1]]){
            dist[x-dir[0]][y-dir[1]] = dist[start[0]][start[1]] + count;
            dfs(M, {x-dir[0], y-dir[1]}, dist);
        }
    }
}

int solve(vector<vector<int> > &M, vector<int> &B, vector<int> &C){
    int m = M.size(), n=m>0?(M[0].size()):0;
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    dist[B[0]][B[1]] = 0;
    dfs(M, B, dist);
    return dist[C[0]][C[1]]==INT_MAX ? -1 : dist[C[0]][C[1]];
}