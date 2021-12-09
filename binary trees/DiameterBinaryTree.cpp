/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    int diameter = 0;
    int dfs(TreeNode *root) {
        if(!root) return 0;

        int l = dfs(root->left);
        int r = dfs(root->right);

        diameter = max(diameter, l+r);
        return max(l, r) + 1;
    }
    int diameterOfBinaryTree(TreeNode * root) {
        dfs(root);
        return diameter;
    }
};