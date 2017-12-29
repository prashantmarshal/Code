#include <bits/stdc++.h>
using namespace std;

#define INT_MAX_2 10000000
struct Node{
	char key;
	struct Node* left, *right;
};

Node *newNode(char k){
	Node *node = new Node;
	node->key = k;
	node->right = node->left = NULL;
	return node;
}

int getMin(int x, int y){
	return (x < y)? x :y;
}

int closestDown(struct Node *root){
	if (root == NULL)
		return INT_MAX_2;
	if (root->left == NULL && root->right == NULL)
		return 0;

	return 1 + getMin(closestDown(root->left), closestDown(root->right));
}

int findClosestUtil(struct Node *root, char k, struct Node *ancestors[],
	int index){
	if (root == NULL)
		return INT_MAX_2;

	if (root->key == k){
		int res = closestDown(root);

		for (int i = index-1; i>=0; i--)
			res = getMin(res, index - i + closestDown(ancestors[i]));
		return res;
	}

	ancestors[index] = root;
	return getMin(findClosestUtil(root->left, k, ancestors, index+1),
		findClosestUtil(root->right, k, ancestors, index+1));

}

int findClosest(struct Node *root, char k){
	struct Node *ancestors[100];
	const clock_t begin_time = clock();
	
	for (int i = 0; i < 10000000; ++i)

	return findClosestUtil(root, k, ancestors, 0);
	std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC;

}


Node* findNode(Node* root, char k, vector<Node*> &v){
	if(!root)
		return NULL;

	if(root->key == k){
		v.push_back(root);
		return root;
	}

	Node *left = findNode(root->left, k, v);
	Node *right = findNode(root->right, k, v);

	if(left){
		v.push_back(root);
		return left;
	}
	else if(right){
		v.push_back(root);
		return right;
	}
	
	return NULL;
}


// find closest leaf in tree rooted with this node
int findClosestDown(Node *root){

	if(!root)
		return INT_MAX_2;

	if(!root->left && !root->right){
		return 1;
	}

	return min(1 + findClosestDown(root->left), 1 + findClosestDown(root->right));
}

int searchinancestors(vector<Node*> ancestors, int index){

	int distance = INT_MAX_2;
	int size = ancestors.size();

	for (; index < size; ++index){
		if(ancestors[index]->left == ancestors[index-1]){
			distance = min(distance, index + 1 + findClosestDown(ancestors[index]->right));
		}
		else{
			distance = min(distance, index + findClosestDown(ancestors[index]->left));
		}
	}

	return distance;

}


int _findClosest(Node *root, char k){
	vector<Node*> ancestors;
	Node* node = findNode(root, k, ancestors);
	const clock_t begin_time = clock();
	int distance = INT_MAX_2;

	for (int i = 0; i < 10000000; ++i)

	// find in left and right subtree of node
		if(node && (node->left || node->right)){
			distance = min(distance, min(findClosestDown(node->left), findClosestDown(node->right)));
			distance = min(distance, searchinancestors(ancestors, 1));
		}else if(node && node->left==NULL && node->right==NULL){
			return 0;
		}

		std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC;

		return distance;
	}



	int main(){
		struct Node *root	 = newNode('A');
		root->left			 = newNode('B');
		root->right			 = newNode('C');
		root->right->left	 = newNode('E');
		root->right->right	 = newNode('F');
		root->right->left->left = newNode('G');
		root->right->left->left->left = newNode('I');
		root->right->left->left->right = newNode('J');
		root->right->right->right	 = newNode('H');
		root->right->right->right->left = newNode('K');


		for (int i = 0; i < 1; ++i)
		{
			char k = 'H';
			cout << "Distace of the closest key from " << k << " is "
			<< _findClosest(root, k) << endl;
			k = 'C';
			cout << "Distace of the closest key from " << k << " is "
			<< _findClosest(root, k) << endl;
			k = 'E';
			cout << "Distace of the closest key from " << k << " is "
			<< _findClosest(root, k) << endl;
			k = 'B';
			cout << "Distace of the closest key from " << k << " is "
			<< _findClosest(root, k) << endl;

		}
		return 0;
	}
