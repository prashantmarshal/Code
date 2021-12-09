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
    /*
     * @param root: the root of binary tree
     * @return: collect and remove all leaves
     */
     
    map<int, vector<int> > nodes;

    int heights(TreeNode *root) {
        if (root == NULL) return 0;
        // If I am going to left before right, then I am always encountering
        // nodes from left to right for a particular level.
        int h = max(heights(root->left), heights(root->right)) + 1;
        nodes[h].push_back(root->val);
        return h;
    }

    vector<vector<int>> findLeaves(TreeNode * root) {
        int max_height = heights(root);

        vector<vector<int> > res;
        for (int i = 1; i <= max_height; i++) {
            res.push_back(nodes[i]);
        }
        return res;
    }
};