#include <iostream>
#include <stack>

using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;

	node(){
		data = 0;
		left = right = NULL;
	}

	node(int data){
		this->data = data;
		left = right = NULL;
	}

};

class bst {
public:
	node *root;

	bst(){
		root = NULL;
	}

	void inorder_util(node* root){
		if(!root)
			return;
		inorder_util(root->left);
		cout<<root->data<<" ";
		inorder_util(root->right);
	}

	void inorder(){
		inorder_util(root);
	}

	void preorder_util(node* root){
		if(!root)
			return;
		cout<<root->data<<" ";
		preorder_util(root->left);
		preorder_util(root->right);	
	}

	void preorder(){
		preorder_util(root);
	}

	void postorder_util(node* root){
		if(!root)
			return;
		postorder_util(root->left);
		postorder_util(root->right);	
		cout<<root->data<<" ";
	}

	void postorder(){
		postorder_util(root);
	}
	node* insert_util(node* root, int data){
		if(!root)
			return new node(data);
		if(data < root->data)
			root->left = insert_util(root->left, data);
		else
			root->right = insert_util(root->right, data);
		return root;
	}

	void insert(int data){
		if(!root){
			root = new node(data);
			return;
		}
		insert_util(root, data);
	}

	node* delete_util(node* root, int data){
		if(!root)
			return NULL;

		if(data == root->data){
			
			if(!root->left){
				node* temp = root->right;
				delete(root);
				return temp;
			}else if(!root->right){
				node* temp = root->left;
				delete(root);
				return temp;
			}else{
				node* temp = root->right;
				while(temp->left)
					temp = temp->left;
				root->data = temp->data;
				root->right = delete_util(root->right, temp->data);
			}

		}else if(data < root->data){
			root->left = delete_util(root->left, data);
		}
		else if(data > root->data){
			root->right = delete_util(root->right, data);
		}
		return root;

	}

	void delete_node(int data){
		delete_util(root, data);
	}

	bool find_util(node* root, int data){
		if(!root)
			return false;
		if(data < root->data)
			return find_util(root->left, data);
		else if(data > root->data)
			return find_util(root->right, data);
		else
			return true;
	}

	bool find(int data){
		return find_util(root, data);
	}

	void inorder_iterative(node* root)
	{
		node *current = root;
		stack<node*> s;
		bool flag = true;

		s.push(current);

		while (!s.empty())
		{
			if(flag){
				while(current->left){
					s.push(current->left);
					current = current->left;
				}
			}

			current = s.top();
			s.pop();
			printf("%d ", current->data);

			if(current->right){
				s.push(current->right);
				current = current->right;
				flag = true;
			}else{
				flag = false;
			}
		}
	}

	void preorder_iterative(node* root)
	{
		node *current = root;
		stack<node*> s;
		bool flag = true;

		printf("%d ", current->data);
		s.push(current);

		while (!s.empty())
		{
			if(flag){
				while(current->left){
					printf("%d ", current->left->data);
					s.push(current->left);
					current = current->left;
				}
			}

			current = s.top();
			s.pop();
			
			if(current->right){
				printf("%d ", current->right->data);
				s.push(current->right);
				current = current->right;
				flag = true;
			}else{
				flag = false;
			}
		}
	}

	void postorder_iterative(node *root){
		if(!root)
			return;

		node* current = root;
		stack<node*> s;
		s.push(current);
		
		while(!s.empty()){

			while(current->left){
				s.push(current->left);
				current = current->left;
			}

			if(current->right){
				current = current->right;
				s.push(current);
			}else{
				while(1){
					current = s.top();
					s.pop();
					cout<<current->data<<" ";
					fflush(stdout);
					if(s.empty())return;
					node *parent = s.top();
					if(!parent)
						return;
					if(current == parent->left){
						current = parent->right;
						if(current){
							s.push(current);
							break;
						}
					}
					else 
						continue;	
				}

			}
		}
	}


	int sumofleftleaves(node* root);

	int diameter_2(node* root){
		if(!root)
			return 0;

		int left = diameter_2(root->left);
		int right = diameter_2(root->right);

		static int res = 0;

		res = max(left+right+1, res);
		if(root == this->root)
			return res;
		return max(left,right)+1;
	}

	int height( node* node)
	{
		if(node == NULL)
			return 0;

		return 1 + max(height(node->left), height(node->right));
	} 

	int diameter( node * tree)
	{
		if (tree == NULL)
			return 0;

		int lheight = height(tree->left);
		int rheight = height(tree->right);

		int ldiameter = diameter(tree->left);
		int rdiameter = diameter(tree->right);

		return max(lheight + rheight + 1, max(ldiameter, rdiameter));
	}

	node* lca(node* root, int data1, int data2){
		if(!root)
			return NULL;
		node* left, * right;
		// cout<<root->data<<endl;

		if(root->data == data1 || root->data == data2){
			/*left = lca(root->left, data1, data2);
			if(left)
				return root;
			right = lca(root->right, data1, data2);
			if(right)
				return root;*/
			return root;
		}

		left = lca(root->left, data1, data2);
		right = lca(root->right, data1, data2);
		if(left && right)
			return root;
		if(left)
			return left;
		else if(right)
			return right;
		return NULL;
	}

};

int bst::sumofleftleaves(node* root){
	if(!root)
		return 0;

	if(root->left){
		if(root->left->left==NULL && root->left->right==NULL)
			return root->left->data;
	}

	return sumofleftleaves(root->left)+sumofleftleaves(root->right);
}


int main(int argc, char const *argv[])
{
	bst *tree =  new bst();
	int data;

	for (int i = 0; i < 10; ++i){
		data = rand()%100*5/2*8/3;
		cout<<data<<" ";
		tree->insert(data);
	}
	cout<<endl;
	node* t = tree->lca(tree->root, 480, 520);
	if(t!=NULL)cout<<t->data<<endl;else printf("t NULL\n");
	delete(tree);
	cout<<endl;

	return 0;
}
