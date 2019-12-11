/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void paths(TreeNode *root, vector<vector<int>> &V, vector<int>&v, int sum) {
        if(!root)
            return;

        if(root->left == NULL && root->right == NULL) {
            if (sum == root->val){
                v.push_back(root->val);
                V.push_back(v);
                v.pop_back();
                return;
            }
        }

        v.push_back(root->val);

        paths(root->left, V, v, sum-root->val);
        paths(root->right, V, v, sum-root->val);
        v.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> V;
        vector<int> v;

        paths(root, V, v, sum);
        return V;
    }
};