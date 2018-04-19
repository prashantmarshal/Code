#include <bits/stdc++.h>
using namespace std;

int longestValidSubstring(string str){
	int len = str.length();
	int longest = -1;
	stack <int> s;

	s.push(-1);

	for (int i = 0; i < len; ++i)
	{
		if(str[i] == '{'){
			s.push(i); // index at which an opening bracket occurred
		}else if(str[i] == '}'){
			s.pop();
			if(!s.empty()){
				longest = max(longest, i-s.top());
			}else{
				s.push(i);
			}
		}
	}

	return longest;
}


int longestValidSubstring2(string str){
	int len = str.length();

	int longest = 0;
	stack <int> s;
	s.push(-1);

	for (int i = 0; i < len; ++i)
	{
		if(str[i] == '{'){
			s.push(i);
		}else{

			int e = s.top();
			s.pop();
			if(str[e] == '{')
				longest = max(longest, i - s.top());
			else
				s.push(i); // maintaining some index in stack
		}
	}

	return longest;
}

int main(int argc, char const *argv[])
{
	string str = "{}{}}}}}{}{{{{}{{}}}}}}{{{{{{{}}}}}}}}}}}";
	cout<<longestValidSubstring(str)<<endl;
	cout<<longestValidSubstring2(str)<<endl;
	return 0;
}