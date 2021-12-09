// https://leetcode.com/problems/unique-binary-search-trees-ii/


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


    vector<TreeNode*> util(int low, int high) {
        if(low > high) {
            return vector<TreeNode*>{NULL};
        }

        // Contains root nodes of every possible subtree
        // root nodes range from low to high
        vector<TreeNode*> subtrees;

        for (int i = low; i < high; i++) {
            vector<TreeNode*> left = util(low, i-1);
            vector<TreeNode*> right = util(i+1, high);
            
            for (TreeNode* l : left) {
                for (TreeNode* r : right) {
                    TreeNode *root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    subtrees.push_back(root);
                }
            }
        }

        return subtrees;
    }

    vector<TreeNode*> generateTrees(int n) {
        return util(1, n);
    }
};