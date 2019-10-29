#include <bits/stdc++.h> 
using namespace std; 

struct Node 
{ 
	struct Node *left, *right; 
	int key; 
}; 

Node* newNode(int key) 
{ 
	Node *temp = new Node; 
	temp->key = key; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

struct Node *findLCAUtil(struct Node* root, int n1, int n2, bool &v1, bool &v2) 
{ 
	if (root == NULL) return NULL; 

	bool curr = false;
	if (root->key == n1) 
	{ 
		v1 = true; 
		curr = true;
	} 
	if (root->key == n2) 
	{ 
		v2 = true; 
		curr = true;
	} 

	Node *left_lca = findLCAUtil(root->left, n1, n2, v1, v2); 
	Node *right_lca = findLCAUtil(root->right, n1, n2, v1, v2); 

	if(curr || (left_lca && right_lca)) return root; 

	return (left_lca != NULL)? left_lca: right_lca; 
}

Node *findLCA(Node *root, int n1, int n2) 
{ 
	bool v1 = false, v2 = false; 

	Node *lca = findLCAUtil(root, n1, n2, v1, v2); 

	if (v1 && v2) 
		return lca; 

	return NULL; 
} 

int main() 
{ 
	Node * root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	root->right->left = newNode(6); 
	root->right->right = newNode(7); 
	Node *lca = findLCA(root, 4, 5); 
	if (lca != NULL) 
		cout << "LCA(4, 5) = " << lca->key; 
	else
		cout << "Keys are not present "; 

	lca = findLCA(root, 4, 10); 
	if (lca != NULL) 
		cout << "\nLCA(4, 10) = " << lca->key; 
	else
		cout << "\nKeys are not present "; 

	return 0; 
}
