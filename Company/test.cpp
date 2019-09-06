/* will return root of tree*/
node *listtobinary(list* head){
	if(!head)
		return NULL;
	queue q;
	node* root;
	root = convertonode(head);
	q.push(root);

	head = head->next;
	while(head){
		left = right = NULL;
		parent = q.pop();
		left = convertonode(head);
		q.push(left);		
		parent->left = left;
		head = head->next;
		if(head){
			right = convertonode(head);
			head = head->next;
			q.push(right);
		}
		parent->right = right;
	}
	return root;
}
