#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;
};


/* UTILITY FUNCTIONS */
/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct node* newnode(int data)
{
	struct node* node = (struct node*)
	malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return(node);
}

node * flatten2(node* root){
    
    if(!root) return NULL;

    node *res = flatten2(root->left);
    node *tmp = root->right;

    if(!res)
        res = root;

    if(tmp){
        res->right = tmp;
        res = flatten2(tmp);
    }

    
    if(root->left)
        root->right = root->left;
    
    if(!res) 
        res = root;


    root->left = NULL;
    res->left = NULL;

    return res;
}

node *flatten(node *root){
    flatten2(root);
    while(root){
        cout<<root->data<<" ";
        root=root->right;
    }
}

/* Driver program to test above functions*/
int main()
{

	/* Constructed binary tree is
			10
			/ \
		   8   2
		  /	   \
	     3	   90
	*/
	struct node *root = newnode(1);
	root->left	 = newnode(2);
	root->right	 = newnode(6);
	root->left->left = newnode(3);
    root->left->left->right = newnode(4);
	root->left->right	 = newnode(5);
	root->right->right	 = newnode(7);
    root->right->right->right	 = newnode(8);

    node *res = flatten(root);
}
