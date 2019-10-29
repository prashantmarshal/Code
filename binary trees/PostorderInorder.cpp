#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

int pi = 0;

unordered_map<int, int> hasht;

int findInInorder(int val) {
    return hasht[val];
}

Node *util(int post[], int in[], int ins, int ine) {
    if(ins > ine) return NULL;

    if(ins == ine) return new Node(post[pi--]);

    Node *root = new Node(post[pi]);
    int index = findInInorder(post[pi]);

    pi--;

    root->right = util(post, in, index+1, ine);
    root->left = util(post, in, ins, index-1);

    return root;
}

Node *buildTree(int in[], int post[], int n)
{
    for (int i = 0; i < n; i++)
    {
        hasht[in[i]] = i;
    }
    
    pi = n-1;
    return util(post, in, 0, pi);
}