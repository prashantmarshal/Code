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

#define ll long long int

class Solution {
public:

    bool util(TreeNode *root, ll minval, ll maxval) {
        if(!root)
            return true;
     
        // Check if root's value is valid
        // Comparing equality also as already sending val-1
        if(!(root->val >= minval && root->val <= maxval))
            return false;

        return util(root->left, minval, (ll)root->val-1)
            && util(root->right, (ll)root->val+1, maxval);
    }

    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;

        return util(root, -4147483648, 4147483648); 
    }
};


// Another solution

struct info {
    long long int min;
    long long int max;
    bool isBst;
};

class Solution {
public:

    info util(TreeNode *root) {
        if(!root) {
            struct info i = {4147483648, -4147483648, true};
            return i;
        }
        
        info left = util(root->left);
        info right = util(root->right);

        if(left.isBst && right.isBst && root->val > left.max && root->val < right.min) {
            info i = {min((long long int)root->val, left.min),
                      max((long long int)root->val, right.max), 
                      true};
            return i;
        }

        return {0, 0, false};
    }

    bool isValidBST(TreeNode* root) {
        info t = util(root);
        return t.isBst;
    }
};