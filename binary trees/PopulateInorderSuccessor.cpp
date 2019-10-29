#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;
	struct node *next;
	
	node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	    next = NULL;
	}
};


/* 
void populateNext(struct node* p)
{
// Your code goes here
    if(!p) return;
    static struct node* ptr = NULL;
    
    populateNext(p->right);
    
    //Printing code
    p->next = ptr;
    ptr = p;
    
    populateNext(p->left);
}

 */

void util(node* p, vector<node*> &a)
{
	if(!p)
		return;
	util(p->left, a);
	a.push_back(p);
	util(p->right, a);
}

void populateNext(struct node* p)
{
	vector<node*> a;
	util(p, a);
	for(int i = 0; i < a.size() - 1; i++)
	{
		a[i]->next = a[i+1];
	}
	a[a.size() - 1]->next = NULL;
}