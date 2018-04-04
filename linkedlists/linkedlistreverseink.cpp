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

node* reverseinkutil(node **head, int k){
	if(!*head) return *head;

	node* _head = *head;
	int _k = k;
	node* p = NULL, *c = *head, *n = (*head)->next;
	
	while(k-- && c){
		c->next = p;
		p = c;
		c = n;
		if(n) n = n->next;
	}

	_head->next = reverseinkutil(&c, _k);
	*head = p;
	return p;
}

void reverseinkutil2(node **head, int k, node* tail){
	
	if(!*head) return;

	int _k = k;
	node* p = NULL, *c = *head, *n = (*head)->next;

	while(k-- && c){
		c->next = p;
		p = c;
		c = n;
		if(n) n = n->next;
	}

	if(tail)
		tail->next = p;
	
	tail = *head;

	reverseinkutil2(&c, _k, tail);

	*head = p;

}

void reverseink(node **head, int k){
	if(!head || !(*head))
		return;

	reverseinkutil(head, k);
	reverseinkutil2(head, k, NULL);
}


int main(int argc, char const *argv[])
{
	linkedlist l;
	for (int i = 0; i < 7; ++i)
	{
		l.insert(i+1);
	}
	l.printlist();
	reverseink(&(l.head), 3);
	l.printlist();

	return 0;
}