#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;
	struct node *nextRight;
};

/* This function returns the leftmost child of nodes at the same level as p.
This function is used to getNExt right of p's right child
If right child of is NULL then this can also be sued for the left child */
void connectRecur(struct node* p);
struct node *getNextRight(struct node *p);

void connectRecur2(struct node* p);

// Sets the nextRight of root and calls connectRecur() for other nodes
void connect (struct node *p)
{
    // Set the nextRight for root
	p->nextRight = NULL;

    // Set the next right for rest of the nodes (other than root)
	connectRecur(p);
}
void connect2 (struct node *p)
{
    // Set the nextRight for root
	p->nextRight = NULL;

    // Set the next right for rest of the nodes (other than root)
	connectRecur2(p);
}

void connectRecur(struct node* p)
{
    // Base case
	if (!p)
		return;

    /* Before setting nextRight of left and right children, set nextRight
    of children of other nodes at same level (because we can access 
    children of other nodes using p's nextRight only) */
	if (p->nextRight != NULL)
		connectRecur(p->nextRight);

    /* Set the nextRight pointer for p's left child */
	if (p->left)
	{
		if (p->right)
		{
			p->left->nextRight = p->right;
			p->right->nextRight = getNextRight(p);
		}
		else
			p->left->nextRight = getNextRight(p);

       /* Recursively call for next level nodes.  Note that we call only
       for left child. The call for left child will call for right child */
		connectRecur(p->left);
	}

    /* If left child is NULL then first node of next level will either be
      p->right or getNextRight(p) */
	else if (p->right)
	{
		p->right->nextRight = getNextRight(p);
		connectRecur(p->right);
	}
	else
		connectRecur(getNextRight(p));
}
/* Set next right of all descendents of p. This function makes sure that
nextRight of nodes ar level i is set before level i+1 nodes. */
void connectRecur2(struct node* p)
{
    // Base case
	if (!p)
		return;



    /* Set the nextRight pointer for p's left child */
	if (p->left)
	{
		if (p->right)
		{
			p->left->nextRight = p->right;
			p->right->nextRight = getNextRight(p);
		}
		else
			p->left->nextRight = getNextRight(p);
	}

	if (p->right)
	{
		p->right->nextRight = getNextRight(p);
	}
	connectRecur2(p->nextRight);

	if(p->left)
		connectRecur2(p->left);
	else
		connectRecur2(p->right);
}

/* This function returns the leftmost child of nodes at the same level as p.
   This function is used to getNExt right of p's right child
   If right child of p is NULL then this can also be used for the left child */
struct node *getNextRight(struct node *p)
{
	struct node *temp = p->nextRight;

    /* Traverse nodes at p's level and find and return
       the first node's first child */
	while(temp != NULL)
	{
		if(temp->left != NULL)
			return temp->left;
		if(temp->right != NULL)
			return temp->right;
		temp = temp->nextRight;
	}

    // If all the nodes at p's level are leaf nodes then return NULL
	return NULL;
}


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
	node->nextRight = NULL;

	return(node);
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
	struct node *root = newnode(10);
	root->left	 = newnode(8);
	root->right	 = newnode(2);
	root->left->left = newnode(3);
	root->right->right	 = newnode(90);
	root->left->left->right	 = newnode(30);
	root->right->right->left	 = newnode(60);
	root->right->right->right = newnode(50);

	// Populates nextRight pointer in all nodes
	connect(root);
	
	// Let us check the values of nextRight pointers
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
	

	connect2(root);
	// Let us check the values of nextRight pointers
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
	
	return 0;
}
