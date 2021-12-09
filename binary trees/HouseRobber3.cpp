class Solution {
public:
    unordered_map<TreeNode*, int> robbed;
    int rob(TreeNode* root) {
        if(!root) return 0;
        if(robbed.find(root) != robbed.end()) {
            return robbed[root];
        }

        int ans = 0;

        // Consider root
        if(root->left) {
            ans += rob(root->left->left) + rob(root->left->right);
        }
        if(root->right) {
            ans += rob(root->right->left) + rob(root->right->right);
        }

        robbed[root] = max(root->val + ans, rob(root->left) + rob(root->right));
        return robbed[root];
    }
};