#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /**
     * @param root: the root
     * @param k: an integer
     * @return: the value of the nearest leaf node to target k in the tree
     */
    TreeNode* findNode(TreeNode* root, int k, vector<TreeNode*> &ancestors){
        if(!root || root->val == k) return root;
        
        ancestors.push_back(root);
        TreeNode* left = findNode(root->left, k, ancestors);
        if(left) return left;

        TreeNode* right = findNode(root->right, k, ancestors);
        if(right) return right;

        ancestors.pop_back();
        return NULL;
    }

    void findLeaf(TreeNode *root, int &leaf, int &distance, int curr_distance){
        if(!root) return;

        if(root->left == NULL && root->right == NULL){
            if(distance > curr_distance){
                distance = curr_distance;
                leaf = root->val;
                return;
            }
        }

        findLeaf(root->left, leaf, distance, curr_distance+1);
        findLeaf(root->right, leaf, distance, curr_distance+1);
    }

    int findClosestLeaf(TreeNode * root, int k) {
        // Write your code here
        vector<TreeNode*>ancestors;

        TreeNode* curr = findNode(root, k, ancestors);
        int leaf, distance = INT_MAX;

        if(!curr->left && !curr->right)
            return curr->val;

        findLeaf(curr->left, leaf, distance, 1);
        findLeaf(curr->right, leaf, distance, 1);

        for (int i = ancestors.size()-1; i >= 0; --i)
        {
            if(curr == ancestors[i]->left){
                findLeaf(ancestors[i]->right, leaf, distance, ancestors.size()-i+1);
            }else{
                findLeaf(ancestors[i]->left, leaf, distance, ancestors.size()-i+1);
            }

            curr = ancestors[i];
        }

        return leaf;
    }
};