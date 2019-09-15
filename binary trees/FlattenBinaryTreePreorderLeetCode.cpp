#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// Easier solution

/* void flattenUtil(TreeNode* root, TreeNode **last){
    if (root == NULL) 
        return; 

    TreeNode* left = root->left; 
    TreeNode* right = root->right; 

    // Avoid first iteration where root is 
    // the only node in the list 
    if (root != *last) { 
        (*last)->right = root; 
        (*last)->left = NULL; 
        *last = root; 
    } 

    flattenUtil(left, last); 
    flattenUtil(right, last); 
    if (left == NULL && right == NULL) 
        *last = root;
}

void flatten(TreeNode* root) {
    flattenUtil(root, &root);
}
 */

TreeNode* flattenUtil(TreeNode* root){
    if(!root) return NULL;
    
    TreeNode *res = flattenUtil(root->left);

    if(!res)
        res = root;

    res->right = root->right;

    // update res for this root node only if root->right has a new candidate    
    if (root->right){
        res = flattenUtil(root->right);
    }

    if(!res) 
        res = root;

    if(root->left)
        root->right = root->left;

    root->left = NULL;
    res->left = NULL;

    return res;
}

void flatten(TreeNode* root) {
    flattenUtil(root);
}


//
