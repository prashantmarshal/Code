#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @param root: a TreeNode
     * @return: a list of integer
     */
	void printLeaves(TreeNode *root, vector<int> &res){
		if(!root) return;
		if(!root->left && !root->right) res.push_back(root->val);
		printLeaves(root->left, res);
		printLeaves(root->right, res);
	}

	void printLeft(TreeNode *root, std::vector<int> &res) {
		if(!root) return;
		res.push_back(root->val);
		if(!root->left) {
			printLeft(root->right, res);
		}else{
			printLeft(root->left, res);	
			printLeaves(root->right, res);		    
		}
	}

	void printRight(TreeNode *root, std::vector<int> &res) {
		if(!root) return;
		if(!root->right) {
			printRight(root->left, res);
		}else{
			printLeaves(root->left, res);
			printRight(root->right, res);
		}
		
		res.push_back(root->val);
	}

	vector<int> boundaryOfBinaryTree(TreeNode * root) {
		std::vector<int> res;
		if(!root) return res;
		res.push_back(root->val);
		printLeft(root->left, res);
		printRight(root->right, res);
		return res;
	}
};	