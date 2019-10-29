#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        *tree = new Node(val);
        return;
    }
    if(val < (*tree)->data)
    { insert(&(*tree)->left, val);}
    else if(val > (*tree)->data)
    { insert(&(*tree)->right, val);}
}
void merge(Node *root1,Node *root2);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root1;Node *root2;
        Node *tmp;
        root1 = NULL;
        root2=NULL;
        int N;
        cin>>N;
        int M;
        cin>>M;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root1, k);}
        for(int i=0;i<M;i++)
        {
            int k;
            cin>>k;
            insert(&root2, k);
        } 
        merge(root1,root2);
        cout<<endl;
    }
}

/*You are required to complete below method */
void merge(Node *root1, Node *root2)
{
    Node *curr1 = root1, *curr2 = root2;
    stack<Node*> s1, s2;
    bool flag1 = true, flag2 = true;

    while(!s1.empty() || !s2.empty() || curr1 || curr2) {
        
        if(flag1) {
            while(curr1){
                s1.push(curr1);
                curr1 = curr1->left;
            }

            if(s1.empty()){
                flag1 = false;
            } else {
                curr1 = s1.top();
                s1.pop();
            }
        }
        
        if(flag2) {
            while(curr2){
                s2.push(curr2);
                curr2 = curr2->left;
            }

            if(s2.empty()){
                flag2 = false;
            } else {
                curr2 = s2.top();
                s2.pop();
            }
        }
        
        int val1 = curr1?curr1->data:INT_MAX;
        int val2 = curr2?curr2->data:INT_MAX;
        
        cout<<min(val1, val2)<<" ";

        if(val1 <= val2){
            curr1 = curr1->right;
            flag2 = false; flag1 = true;
        }else{
            curr2 = curr2->right;
            flag1 = false; flag2 = true;
        }
    }
}