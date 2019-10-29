// https://leetcode.com/problems/all-paths-from-source-to-target/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(vector<vector<int>>&g, int src, int dest, vector<int> &res, vector<vector<int>>&v){
        res.push_back(src);
        if(src == dest){
            // Add the current path
            v.push_back(res);
            res.pop_back();
            return;
        }

        for(auto i : g[src]){
            dfs(g, i, dest, res, v);                
        }

        res.pop_back();
    }

    void bfs(vector<vector<int>>&g, int src, int dest, vector<int>&res, vector<vector<int>> &v){
        queue<vector<int>>q;
        res.push_back(src);
        q.push(res);

        while(!q.empty()){
            res = q.front();
            q.pop();

            int curr = res[res.size()-1];
            if(curr == dest){
                v.push_back(res);
                continue;
            }

            for(auto i : g[curr]){
                res.push_back(i);
                q.push(res);
                res.pop_back();
            }
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> res;
        vector<vector<int> >v;

        if(n == 0){
            return v;
        }

        dfs(graph, 0, n-1, res, v);
        bfs(graph, 0, n-1, res, v);
        return v;
    }
};