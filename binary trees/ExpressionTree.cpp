
#include <bits/stdc++.h>
using namespace std;

struct et
{
	char value;
	et* left, *right;
	
	et(char x){
		value = x;
		left = right = NULL;
	}
};
bool isOperator(char c)
{
	if (c == '+' || c == '-' ||
		c == '*' || c == '/' ||
		c == '^')
		return true;
	return false;
}
void inorder(et *t)
{
	if(t)
	{
		inorder(t->left);
		printf("%c ", t->value);
		inorder(t->right);
	}
}
et* constructTree(char []);
int main()
{   
	int t;
	cin>>t;
	while(t--){
		char postfix[25];
		cin>>postfix;
		et* r = constructTree(postfix);
		inorder(r);
		cout<<endl;
	}
	return 0;
}

et* constructTree(char postfix[])
{
	stack<et*> s;
	int i = 0;
	
	et *node;
	for (int i = 0; postfix[i] != '\0'; i++)
	{
		node = new et(postfix[i]);
		if(postfix[i] >= 'a' && postfix[i] <= 'z'){
			s.push(node);
		} else {
			node->right = s.top(); s.pop();
			node->left = s.top(); s.pop();
			s.push(node);
		}
	}

	return node;
}