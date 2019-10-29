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

    unordered_map<int, int> hash;

    TreeNode *util(vector<int>& pre, vector<int>& in, int in_start, int in_end, int &pre_index, int n) {
        if(pre_index == n || in_start > in_end) return NULL;

        TreeNode *root = new TreeNode(pre[pre_index]);

        int pivot = hash[pre[pre_index]];
        pre_index++;

        root->left = util(pre, in, in_start, pivot-1, pre_index, n);
        root->right = util(pre, in, pivot+1, in_end, pre_index, n);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = inorder.size();
        
        for (int i = 0; i < size; i++)
        {
            hash[inorder[i]] = i;
        }
        
        int iter = 0;
        return util(preorder, inorder, 0, size-1, iter, size);
    }
};