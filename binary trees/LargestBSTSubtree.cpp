#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Info
{
    int maxval;
    int minval;
    int size;
    bool isbst;

    Info(int maxv, int minv, int sz, bool flag): maxval(maxv), minval(minv), size(sz), isbst(flag){}
};

Info solveUtil(TreeNode* root) {
    if(!root) return Info(INT_MIN, INT_MAX, 0, true);

    Info leftinfo = solveUtil(root->left);
    Info rightinfo = solveUtil(root->right);

    if(leftinfo.maxval < root->val && rightinfo.minval > root->val
    && leftinfo.isbst && rightinfo.isbst)
        return Info(max(root->val, rightinfo.maxval), min(root->val, leftinfo.minval), leftinfo.size+rightinfo.size+1, true);
    
    return Info(0, 0, max(leftinfo.size, rightinfo.size), false);
}

int solve(TreeNode *root){
    Info x = solveUtil(root);
    return x.size;
}