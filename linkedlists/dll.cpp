#include <bits/stdc++.h>

using namespace std;


class dll_node{
public:

	dll_node *next;
	dll_node *prev;
	int data;

	dll_node(){
		next = prev = NULL;
		data = -1;
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
			head = new dll_node();
			head->data = data;
		}else{
			dll_node *start = head;
			while(start->next)
				start = start->next;
			
			start->next = new dll_node();
			start->next->data = data;
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
			delete(start);
		}else{
			start->prev->next = start->next;
			if(start->next)
				start->next->prev = start->prev;
			delete start;
		}

	}

	void delete_node_all (int data){
		dll_node *start = head;
		while(start){
			if(start->data == data)
				delete_node(data);
			start = start->next;
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

};




int main(int argc, char const *argv[])
{
	dll dllist;
	for (int i = 0; i < 20; ++i)
	{
		dllist.insert(i+1);
	}
	dllist.print_dll();

	for (int i = 0; i < 10; ++i)
	{
		dllist.delete_node(i+1);
	}
	dllist.print_dll();
	for (int i = 10; i < 15; ++i)
	{
		dllist.delete_node(i);
	}
	dllist.print_dll();
	return 0;
}