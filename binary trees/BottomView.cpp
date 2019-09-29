// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1/?ref=self

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references
    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
};

void printBottomView(Node *root, map<int, int> &hd, int level, int *minlevel){
    if (!root) return;

    hd[level] = root->data;

    if(level < *minlevel) *minlevel = level;

    printBottomView(root->left, hd, level-1, minlevel);
    printBottomView(root->right, hd, level+1, minlevel);
}

// Method that prints the bottom view.
void bottomView(Node *root)
{
    map<int, int> hd;
    int minlevel = INT_MAX;
    printBottomView(root, hd, 0, &minlevel);
    
    while(hd.find(minlevel) != hd.end()){
        cout<<hd[minlevel]<<" ";
        minlevel++;
    }
}