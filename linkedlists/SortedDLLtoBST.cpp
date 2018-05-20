void sortedDLLtoBST(node **head, int n){
	
	if(n <= 0)
		return NULL;

	node* left = sortedDLLtoBST(head, n/2);
	node *root = *head;

	root->prev = left;

	*head = (*head)->next;

	root->next = sortedDLLtoBST(head, n/2-1);

	return root;

}