// https://leetcode.com/problems/maximum-width-of-binary-tree/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#define LL unsigned long long
#define NodeLevelPair pair<TreeNode*, LL>

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        
        // Faster than map 
        queue<NodeLevelPair>q;

        LL maxWidth = 1;
        q.push(make_pair(root, 0));

        while(!q.empty()){
            LL size = q.size();
            LL lmax = INT_MAX, rmax = 0; // Treating as complete binary tree in an array

            while(size--){
                NodeLevelPair temp = q.front();
                q.pop();

                if(temp.first->left){
                    lmax = min(temp.second*2+1, lmax);
                    rmax = max(temp.second*2+1, rmax);
                    q.push(make_pair(temp.first->left, temp.second*2+1));
                }

                if(temp.first->right){
                    lmax = min(temp.second*2+2, lmax);
                    rmax = max(temp.second*2+2, rmax);
                    q.push(make_pair(temp.first->right, temp.second*2+2));
                }
            }

            if(lmax != INT_MAX && rmax) {
                maxWidth = max(maxWidth, rmax-lmax+1);
            }
            
        }
        return maxWidth;
    }
};

// Another good solution using dequeue
/* queue<pair<TreeNode*, unsigned long>> q;
    int maxW = 0;
    
    if(root)
        q.push({root, 1});
    
    while(!q.empty()){
        int n = q.size();
        int w = q.back().second - q.front().second + 1; 
        maxW = max(maxW, w);
        
        for(int i = 0; i < n; i++){
            auto p = q.front();
            q.pop();
            
            if(p.first->left)
                q.push({p.first->left, p.second * 2});
            if(p.first->right)
                q.push({p.first->right, (p.second * 2) + 1});
        }
    }
    
    return maxW; */