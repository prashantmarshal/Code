#include <bits/stdc++.h>
using namespace std;

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
	int util(TreeNode *root, int &maxsum) {
		if(!root) return 0;

		int left = util(root->left, maxsum);
		int right = util(root->right, maxsum);

		maxsum = max(maxsum, left+right+root->val);
		return max(0, max(left, right) + root->val);
	}

    int maxPathSum(TreeNode* root) {
    	int maxsum = 0;
    	util(root, maxsum);    
    	return maxsum;
    }
};