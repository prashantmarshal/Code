
bool linkedListPalindrome(node** first, node* second){

	if(second == NULL)
		return true;

	bool p = linkedListPalindrome(first, second->next);

	if(p && *first->data ==  second->data){
		*first = *first->next;
		return true;
	}

	return false;


}


bool linkedListPalindrome_wrapper(node *head){
	node *first, *second;

	first = second = head;

	return linkedListPalindrome(&first, second);
}


// other approaches
/*
1. put all in stack.
2. traverse list again and compare stack tops.
*/

/*
1. reverse the list.
2. compare with original.
*/