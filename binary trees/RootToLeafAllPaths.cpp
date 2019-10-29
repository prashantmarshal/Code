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
    void util(TreeNode *root, string str, vector<string> &v){
        if(!root) return;

        if(!root->left && !root->right) {
            str += to_string(root->val);
            v.push_back(str);
            return;
        }

        str += to_string(root->val) + "->";
        util(root->left, str, v);
        util(root->right, str, v);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        string str = "";
        vector<string> v;
        util(root, str, v);
        return v;
    }
};