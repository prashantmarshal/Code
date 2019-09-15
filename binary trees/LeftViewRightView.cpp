#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void fu(TreeNode *root, int level, int *maxlevel, vector<int>&v){
    if(!root)
        return;

    if(*maxlevel < level){
        v.push_back(root->val);
        *maxlevel = level;
    }

    fu(root->right, level+1, maxlevel, v);
    fu(root->left, level+1, maxlevel, v);
    // interchange above two for left / right view
}

vector<int> rightSideView(TreeNode* root) {
    vector<int>v;
    if(!root)
        return v;

    int maxlevel = 0;
    fu(root, 1, &maxlevel, v);
    return v;
    
}