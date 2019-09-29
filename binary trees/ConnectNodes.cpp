#include <bits/stdc++.h>

using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;
	struct node *nextRight;
};

struct node *getNextRight(struct node *p);
void connectRecur(struct node* p);

void connect (struct node *p)
{
	p->nextRight = NULL;
	connectRecur(p);
}

void connectRecur(struct node* p)
{
	if (!p)
		return;

	if (p->left){
		p->left->nextRight = (p->right)?p->right:getNextRight(p);
	}

	if(p->right){
		p->right->nextRight = getNextRight(p);
	}

	connectRecur(p->nextRight);

	if(p->left)
		connectRecur(p->left);
	else
		connectRecur(p->right);
}

struct node *getNextRight(struct node *p)
{
	struct node *temp = p->nextRight;

	while(temp != NULL)
	{
		if(temp->left != NULL)
			return temp->left;
		if(temp->right != NULL)
			return temp->right;
		temp = temp->nextRight;
	}

	return NULL;
}

void connectNodesIterative(struct node *root){
	if(!root) return;

	root->nextRight = NULL;
	struct node *p = root, *nextLevel = root;
	
	// We fix children of current level and go to leftmost next level child
	while(nextLevel) {
		
		p = nextLevel;

		while(p) {
			if(p->left)
				p->left->nextRight = (p->right)?p->right:getNextRight(p);
			
			if(p->right)
				p->right->nextRight = getNextRight(p);
			
			p = p->nextRight;
		}

		nextLevel = (nextLevel->left)?(nextLevel->left):(nextLevel->right)?(nextLevel->right):getNextRight(nextLevel);
	}
}

struct node* newnode(int data)
{
	struct node* node = (struct node*)
	malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->nextRight = NULL;

	return(node);
}

int main()
{
	struct node *root = newnode(10);
	root->left	 = newnode(8);
	root->right	 = newnode(2);
	root->left->left = newnode(3);
	root->right->right	 = newnode(90);
	root->left->left->right	 = newnode(30);
	root->right->right->left	 = newnode(60);
	root->right->right->right = newnode(50);
	root->right->right->left->left = newnode(80);
	root->right->right->right->left = newnode(90);

	connect(root);

	printf("Following are populated nextRight pointers in the tree "
		"(-1 is printed if there is no nextRight) \n");
	printf("nextRight of %d is %d \n", root->data,
		root->nextRight? root->nextRight->data: -1);

	printf("nextRight of %d is %d \n", root->left->data,
		root->left->nextRight? root->left->nextRight->data: -1);
	
	printf("nextRight of %d is %d \n", root->right->data,
		root->right->nextRight? root->right->nextRight->data: -1);
	
	printf("nextRight of %d is %d \n", root->left->left->data,
		root->left->left->nextRight? root->left->left->nextRight->data: -1);
	
	printf("nextRight of %d is %d \n", root->right->right->data,
		root->right->right->nextRight? root->right->right->nextRight->data: -1);
	
	printf("nextRight of %d is %d \n", root->left->left->right->data,
		root->left->left->right->nextRight? root->left->left->right->nextRight->data: -1);	

	printf("nextRight of %d is %d \n", root->right->right->left->data,
		root->right->right->left->nextRight? root->right->right->left->nextRight->data: -1);	

	printf("nextRight of %d is %d \n", root->right->right->right->data,
		root->right->right->right->nextRight? root->right->right->right->nextRight->data: -1);	

	printf("nextRight of %d is %d \n", root->right->right->left->left->data,
		root->right->right->left->left->nextRight? root->right->right->left->left->nextRight->data: -1);	

	printf("nextRight of %d is %d \n", root->right->right->right->left->data,
		root->right->right->right->left->nextRight? root->right->right->right->left->nextRight->data: -1);
	
	/* 
		nextRight of 10 is -1
		nextRight of 8 is 2
		nextRight of 2 is -1
		nextRight of 3 is 90
		nextRight of 90 is -1
		nextRight of 30 is 60
		nextRight of 60 is 50
		nextRight of 50 is -1
		nextRight of 80 is 90
		nextRight of 90 is -1
	*/
	return 0;
}
