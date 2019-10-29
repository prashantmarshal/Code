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
    int minDepth(TreeNode* A) {
        if(A == NULL) return 0;
        
        if( A->left == NULL && A->right == NULL )
            return 1;

        int h1=INT_MAX, h2=INT_MAX;

        if( A->left != NULL )
            h1 = minDepth( A->left ) + 1;

        if( A->right != NULL )    
            h2 = minDepth( A->right ) + 1;

        return min( h1, h2 );
    }
};