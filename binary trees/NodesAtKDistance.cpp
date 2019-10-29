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

    void printDown(TreeNode *root, int K, vector<int>&v){
        if(!root) return;
        if(K==0){
            v.push_back(root->val);
            return;
        }

        printDown(root->left, K-1, v);
        printDown(root->right, K-1, v);
    }

    int printK(TreeNode *root, int val, int K, vector<int> &v){
        if(!root) return -1;

        if(root->val == val) {
            printDown(root, K, v);
            return K-1;
        }

        int left = printK(root->left, val, K, v);
        if(left >= 0) {
            if(left == 0){
                v.push_back(root->val);
            }else{
                printDown(root->right, left-1, v);
            }
            return left-1;
        }

        
        int right = printK(root->right, val, K, v);
        if(right >= 0) {
            if(right == 0){
                v.push_back(root->val);
            }else{
                printDown(root->left, right-1, v);
            }
            return right-1;
        }
        return -1;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> v;
        printK(root, target->val, K, v);
        return v;
    }
};