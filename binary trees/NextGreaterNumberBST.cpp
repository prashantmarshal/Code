#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *findRight(TreeNode *root){
    root = root->right;
    while(root->left){
        root = root->left;
    }
    return root;
}

TreeNode* getSuccessor(TreeNode*root, int val) {
    TreeNode *curr = root, *ng = NULL; // NULL ~ INT_MAX

    while(curr){
        if(val > curr->val){
            curr = curr->right;
        }else if(val < curr->val){
            ng = curr;
            curr = curr->left;
        }else if(val == curr->val){
            if(curr->right) {
                return findRight(curr);
            }else{
                return ng;
            }
        }
    }

    return NULL;
}
