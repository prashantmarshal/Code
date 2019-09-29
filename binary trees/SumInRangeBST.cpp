// https://leetcode.com/problems/range-sum-of-bst/

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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(!root)
            return 0;
        
        if(root->val < L || root->val > R)
            return 0;

        long long int left = 0, right = 0;
        
        if (root->left)
            if(root->left->val >= L)
                left = rangeSumBST(root->left, L, R);

        if (root->right)
            if(root->right->val <= R)
                right = rangeSumBST(root->right, L, R);
            
        return root->val+left+right;
    }
};