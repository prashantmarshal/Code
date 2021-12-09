// https://leetcode.com/problems/time-needed-to-inform-all-employees/


int dfs(vector<vector<int> > &tree, int root, vector<int> &informTime) {
    int time = 0;
    for (int i = 0; i < tree[root].size(); i++) {
        time += dfs(tree, tree[root][i], informTime);
    }

    return informTime[root] + time;
}

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int> > tree(n);

        int root;
        for (int i = 0; i < manager.size(); i++) {
            if (manager[i] == -1) {
                root = i; 
            } else {
                tree[manager[i]].push_back(i);
            }
        }

        return dfs(tree, root, informTime);
    }
};