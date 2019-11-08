#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

void diagonalPrint(Node *root)
{
    if(!root) return;

    queue<Node*>q;
    q.push(root);
    
    Node *top;
    
    while(!q.empty()){
        int size = q.size();

        while(size--){
            top = q.front();
            q.pop();
            while(top){
                cout<<top->data<<" ";
                if(top->left) {
                    q.push(top->left);
                }
                top = top->right;
            }
        }
        cout<<endl;
    }
}