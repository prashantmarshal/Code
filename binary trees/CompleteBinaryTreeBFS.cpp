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
    bool isCompleteTree(TreeNode* root) {

        bool levelFilled = false;
        queue <TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            
            if(front == nullptr) {
                levelFilled = true;
            } else {
                if(levelFilled) return false;
                q.push(front->left);
                q.push(front->right);
            }
        }
        return true;
    }
};