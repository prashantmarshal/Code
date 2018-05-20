// (1)
void binarytodll(node *root, node **head){

	if(root == NULL)
		return;

	// this will store previous node in inorder traversal
	static node *prev = NULL;

	binarytodll(root->left, head);

	if(prev == NULL){
		*head = root;
	}else{
		prev->right = root;
		root->left = prev;
	}

	prev = root;

	binarytodll(root->right, head);

}

void binarytodll(node *root){
	node *head;
	binarytodll(root, &head);
	printdll(head);
}

// (2)
void binarytodll(node *root, node **head){
	if(root == NULL) 
		return;

	binarytodll(root->right, head);

	root->right = *head;

	if(*head)
		(*head)->left = root;

	*head = root;

	binarytodll(root->left, head);


}
