// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1/?ref=self

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


// function should print the topView of the binary tree
void printTopView(Node *root, map<int, pair<int, int> > &hd, int level, int height, int *minlevel){
    if (!root) return;

    if(hd.find(level) != hd.end()){
        int prevheight = hd[level].second;
        if(prevheight > height){
            hd[level] = make_pair(root->data, height);
        }
    } else {
            hd[level] = make_pair(root->data, height);
    }

    if(level < *minlevel) *minlevel = level;

    printTopView(root->left, hd, level-1, height+1, minlevel);
    printTopView(root->right, hd, level+1, height+1, minlevel);
}

// Method that prints the top view.
void topView(Node *root)
{
    if (!root)
        return;
    
    // horizontal level, (height, value)
    map<int, pair<int, int> >hd;
    int minlevel = INT_MAX;
    printTopView(root, hd, 0, 0, &minlevel);
    
    while(hd.find(minlevel) != hd.end()){
        cout<<hd[minlevel].first<<" ";
        minlevel++;
    }
}