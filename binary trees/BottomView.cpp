#include <bits/stdc++.h>

using namespace std;

struct node
{
	int data; 
	int hd; 
	node *left, *right; 

	node(int key)
	{
		data = key;
		hd = INT_MAX;
		left = right = NULL;
	}
};


void bottomView(node *root) {

	if(!root)
		return;

	queue<node*> q;

	map<int, int> hash;

	root->hd = 0;
	q.push(root);

	while(!q.empty()){
 
		node* front =  q.front();

		hash[front->hd] = front->data;

		if(front->left){
			front->left->hd = front->hd - 1;
			q.push(front->left);
		}
		if(front->right){
			front->right->hd = front->hd + 1;
			q.push(front->right);
		}

		q.pop();

	}

	for(auto i = hash.begin(); i != hash.end(); ++i){
		cout<<i->second<<" ";
	}

}

int main()
{
	node *root = new node(20);
	root->left = new node(8);
	root->right = new node(22);
	root->left->left = new node(5);
	root->left->right = new node(3);
	root->right->left = new node(4);
	root->right->right = new node(25);
	root->left->right->left = new node(10);
	root->left->right->right = new node(14);
	cout << "Bottom view of the given binary tree :\n";
	bottomView(root);
	return 0;
}