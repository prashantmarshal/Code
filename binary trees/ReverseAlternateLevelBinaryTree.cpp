#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

// We swap first and last node's data and keep moving towards
void util(Node *left, Node *right, int level){
    if(!left || !right){
        return;
    }    
    
    if(level&1) swap(left->data, right->data);
    
    util(left->left, right->right, level+1);
    util(left->right, right->left, level+1);
}

void reverseAlternate(Node *root)
{
    if(!root) return;
    util(root->left, root->right, 1);
}