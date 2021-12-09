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
    
    bool relaxation = true;
    int previous_level = 0;

    bool dfs(TreeNode *root, int depth) {
        if(!root) {
            if(!previous_level) {
                previous_level = depth;
                return true;
            }

            if(depth == previous_level) {
                return true;
            }

            if(depth == previous_level-1 && relaxation) {
                previous_level = depth;
                relaxation = false;
                return true;
            }
            return false;
        }
        
        return dfs(root->left, depth+1) && dfs(root->right, depth+1);
    }

    bool isCompleteTree(TreeNode* root) {
        if(!root) return true;
        return dfs(root, 1);
    }
};