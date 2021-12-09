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

    vector<vector<int>> res;

    void DFS(TreeNode* root, int depth) {
        
        if (root == nullptr) return; // Don't add any new vector to res for this depth

        if (depth > res.size()) {
            // Insert an empty vector into res if the current depth is reached
            // for the first time
            res.push_back(vector<int>());
        }

        res[depth - 1].push_back(root->val);
        DFS(root->left, depth + 1);
        DFS(root->right, depth + 1);
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        DFS(root, 1);
        return vector<vector<int>>(res.rbegin(), res.rend());
    }
};