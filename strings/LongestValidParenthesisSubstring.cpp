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

int main(int argc, char const *argv[])
{
	string str = "{}{}}}}}{}{{{}{}{}{}{}{}}}}}}}}{{{{}{}{{}{}{{}{}{{{}{{{{{{{{}}}}}}}}";
	cout<<longestValidSubstring(str)<<endl;
	return 0;
}