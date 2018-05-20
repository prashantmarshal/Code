#include <bits/stdc++.h>

using namespace std;


void postfixToInfix(string str){
	stack<string> s;
	string s1,s2;

	int len = str.length();

	for (int i = 0; i < len; ++i)
	{
		if(str[i] <= 'z' && str[i] >= 'a'){
			s.push(string(1, str[i]));
		}else{
			s1 = s.top();
			s.pop();
			s2 = s.top();
			s.pop();
			s.push("("+s2+str[i]+s1+")");
		}
	}

	cout<<s.top()<<endl;
}

int main(int argc, char const *argv[])
{
	string s = "ab*c+ab++c*";
	postfixToInfix(s);
	return 0;
}
