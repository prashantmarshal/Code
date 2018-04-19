#include <bits/stdc++.h>

using namespace std;


void printMinimumNumber(string str){
	int n = str.length();

	stack<int> s;

	for (int i = 0; i <= n; ++i)
	{
		s.push(i+1);
		if(str[i] == 'I' || i == n){
			while(!s.empty()){
				cout<<s.top();
				s.pop();
			}
		}

	}

}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		string seq;
		cin>>seq;
		printMinimumNumber(seq);
		cout<<endl;		
	}

	return 0;
}