#include <bits/stdc++.h>

using namespace std;


class dll_node{
public:

	dll_node *next;
	dll_node *prev;
	int data;

	dll_node(int data = -1){
		next = prev = NULL;
		this->data = data;
	}

	~dll_node(){
		next = NULL;
		prev = NULL;
	}
};


class dll{
public:
	dll_node *head;
	dll(){
		head = NULL;
	}

	void insert	(int data){

		if(head == NULL){
			head = new dll_node(data);
		}else{
			dll_node *start = head;
			while(start->next)
				start = start->next;
			
			start->next = new dll_node(data);
			start->next->prev = start;
		}
	}


	void delete_node (int data){
		
		if(head == NULL) return;

		dll_node *start = head;

		while(start != NULL){
			if(start->data == data) break;
			start = start->next;
		}

		if(start == NULL) printf("Node not found\n");
		else if(start == head){
			head = start->next;
			if(head) head->prev = NULL;
			
			start->next = NULL;
			
			delete(start);
		}else{
			start->prev->next = start->next;
			if(start->next)
				start->next->prev = start->prev;
			
			start->next = NULL;
			start->prev = NULL;
			
			delete start;
		}

	}

	void print_dll(){
		dll_node *start = head;
		while(start){
			printf("%d ", start->data);
			start = start->next;
		}
		printf("\n");
	}

	void removeduplicates(){
		if(head == NULL) return;

		dll_node *start = head;
		while(start && start->next){
			while(start->next && start->data == start->next->data){

				dll_node* dup = start->next;

				if(start->next->next){
					start->next->next->prev = start;
				}
				start->next = start->next->next;

				delete(dup);

			}
			
			start = start->next;

		}
	}

	void deletealloccurences(int data){
		if(head == NULL) return;

		dll_node *start = head;

		while(start){
			if(start->data == data){
				start = start->next;
				delete_node(data);
			}else
				start = start->next;
		}
	}

	void reverserecursion(dll_node **head){
		if(*head == NULL)
			return;

		dll_node *dup = (*head)->next;
		(*head)->next = (*head)->prev;
		(*head)->prev = dup;

		if((*head)->prev == NULL)
			return;

		*head = (*head)->prev;

		reverserecursion(head);

	}

};

void test_removeduplicates(dll);
void test_deletealloccurences(dll);
void test_reverserecursion(dll);

int main(int argc, char const *argv[])
{
	dll dllist;

	// test_removeduplicates(dllist);
	// test_deletealloccurences(dllist);
	test_reverserecursion(dllist);


	return 0;
}






void test_removeduplicates(dll dllist){
	dllist.insert(1);dllist.insert(1);dllist.insert(1);dllist.insert(1);
	dllist.insert(2);dllist.insert(2);
	dllist.insert(3);dllist.insert(3);dllist.insert(3);dllist.insert(3);dllist.insert(3);
	dllist.insert(4);
	dllist.insert(5);dllist.insert(5);

	dllist.print_dll();
	dllist.removeduplicates();
	dllist.print_dll();
}

void test_deletealloccurences(dll dllist){
	dllist.insert(1);dllist.insert(1);dllist.insert(1);dllist.insert(1);
	dllist.insert(2);dllist.insert(2);
	dllist.insert(3);dllist.insert(3);dllist.insert(3);dllist.insert(3);dllist.insert(3);
	dllist.insert(4);
	dllist.insert(5);dllist.insert(5);

	dllist.print_dll();
	dllist.deletealloccurences(2);
	dllist.deletealloccurences(1);
	dllist.deletealloccurences(3);
	dllist.deletealloccurences(5);
	dllist.print_dll();
}

void test_reverserecursion(dll dllist){
	dllist.insert(1);
	dllist.insert(2);
	dllist.insert(3);
	dllist.insert(4);
	dllist.insert(5);
	dllist.print_dll();
	dllist.reverserecursion(&dllist.head);
	dllist.print_dll();
}


/*

XOR doubly linked list

...  A        B         C         D         E  ...
         <–>  A⊕C  <->  B⊕D  <->  C⊕E  <->

When traversing the list from left to right: supposing the cursor is at C,
the previous item, B may be XORed with the value in the link field (B⊕D).
The address for D will then be obtained and list traversal may resume.

*/

