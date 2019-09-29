#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:

    bool util(TreeNode *root, TreeNode **curr) {
        if(!root)
            return true;
        
        if(!util(root->left, curr))
            return false;
        
        // Inorder traversal printing code
        if(*curr && root->val <= (*curr)->val)
            return false;
        
        *curr = root;

        return util(root->right, curr);
    }

    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;

        TreeNode *curr = NULL;       
        return util(root, &curr); 
    }
};

// Another solution by passing ranges for recursive calls

bool util(TreeNode *root, int minval, int maxval) {
    if(!root)
        return true;
    // Check if root's value is valid
    // Comparing <= >= as already sending val-1
    if(!(root->val >= minval && root->val <= maxval))
        return false;

    return util(root->left, minval, root->val-1)
        && util(root->right, root->val+1, maxval);
}

bool isValidBST(TreeNode* root) {
    if(!root)
        return true;

    return util(root, INT_MIN, INT_MAX); 
}
