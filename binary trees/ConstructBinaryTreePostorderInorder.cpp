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

    TreeNode *util(vector<int>& post, vector<int>& in, int in_start, int in_end, int &post_index) {
        if(post_index == -1 || in_start > in_end) return NULL;

        TreeNode *root = new TreeNode(post[post_index]);

        int pivot = hash[post[post_index]];
        post_index--;

        root->right = util(post, in, pivot+1, in_end, post_index);
        root->left = util(post, in, in_start, pivot-1, post_index);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder) {
        int size = inorder.size();
        
        for (int i = 0; i < size; i++)
        {
            hash[inorder[i]] = i;
        }
        
        int iter = size-1;
        return util(postorder, inorder, 0, size-1, iter);
    }
};