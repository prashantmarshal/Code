// https://leetcode.com/problems/increasing-order-search-tree/

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
class Solution {
public:

    /*
    TreeNode *next = nullptr; // in reverse inorder traversal,
                              // `next` points to the next greater node to the root
    
    TreeNode* increasingBST(TreeNode* root) {
        if (!root) {
            return root;
        }

        increasingBST(root->right);
        
        // current root's context; do manipulations here
        root->right = next;
        next = root;
        
        increasingBST(root->left);
        root->left = nullptr;

        return next;
    }
    */

    // Revision
    TreeNode *next = nullptr;
    
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return nullptr;

        increasingBST(root->right);
        
        // Current root's context
        root->right = next;
        next = root;
        
        increasingBST(root->left);
        root->left = nullptr;
        return next; // Return the last node that becomes next
    }

};


