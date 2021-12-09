// https://leetcode.com/problems/validate-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

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