#include <bits/stdc++.h>

using namespace std;


class node{
public:
	int data;
	node* next;

	node(int data){
		this->data = data;
		this->next = NULL;
	}
};


class linkedlist
{
public:
	node *head;
	linkedlist(){
		head = NULL;
	}

	void insert(int data){
		if(!head) {
			head = new node(data);
			cout<<&head<<endl;
		} else {
			node *start = head;
			while(start->next){
				start = start->next;
			}
			start->next = new node(data);
		}
	}

	void printlist(){

		node *start = head;
		while(start){
			cout<<start->data<<" ";
			start = start->next;
		}
		cout<<endl;
	}
};

node* reverse(node **head){

	if(!head || !*head){
		return NULL;
	}

	if(!(*head)->next){
		return *head;
	}

	// store current pointer
	node *c = *head;

	// change *head to point to next node
	*head = (*head)->next;

	// next of pointer returned to point current
	node *temp = reverse(head);
	temp->next = c;

	// current->next point to NULL
	c->next = NULL;

	// return current so that it will be temp and 
	// temp->next = current of previous stack
	return c;

}



int main(int argc, char const *argv[])
{
	linkedlist l;
	for (int i = 0; i < 20; ++i)
	{
		l.insert(i+1);
	}
	l.printlist();
	reverse(&(l.head));
	l.printlist();

	return 0;
}
