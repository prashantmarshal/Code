#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
  
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    stack<int> s;
    queue<TreeNode*>q;
    vector<vector<int>> v;  

    if(!root)   
        return v;

    q.push(root);
    bool flag = true;
    while(!q.empty()){
        int size = q.size();
        vector<int>v1;

        while(size--){
            root = q.front();
            q.pop();

            if(flag){
                v1.push_back(root->val);
            } else {
                s.push(root->val);
            }

            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);
        }

        if(!flag){
            int sz = s.size();
            while(sz--){
                v1.push_back(s.top());
                s.pop();
            }
        }

        flag = !flag;
        v.push_back(v1);
    }

    return v;
}