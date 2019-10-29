// C program to Print all combinations
// of balanced parentheses

#include <bits/stdc++.h>
using namespace std;


void count(int n, int open, int close, string str){
	if(close == n/2){
		cout<<str<<endl;
		return;
	}

	if(open < n/2){
		count(n, open+1, close, str + '{');
	}
	if(close < open)   
		count(n, open, close+1, str + '}');

}

void printParenthesis(int n){
	string str = "";
	count(n, 0, 0, str);
}

int main()
{
	int n = 6;
	printParenthesis(n);
	return 0;
}

