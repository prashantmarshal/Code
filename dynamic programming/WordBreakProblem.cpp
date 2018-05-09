#include <bits/stdc++.h>
#include <string.h>

using namespace std;

string dictionary[] = {"mobile","samsung","sam","sung",
	"man","mango","icecream","and",
	"go","i","like","ice","cream"};

// w[i] will be true if string from ith index to last index is valid
int w[100];

bool doesContain(string s){
	int size = sizeof(dictionary)/sizeof(dictionary[0]);
	for (int i = 0; i < size; ++i)
		if(s == dictionary[i])
			return true;
	return false;
}

bool wordbreak2(string s, int l, int r){

	for(int i = l; i <= r; ++i){

		if(doesContain(s.substr(l, i-l+1))){

			// if this contained word is the last part of the string
			// then return true no further checking
			if(i == r){
				cout<<s.substr(l, i-l+1)<<" ";
				return true;
			}

			// if the part of string ahead of ith index is unchecked
			// call recursively
			if(w[i+1] == -1){
				w[i+1] = wordbreak2(s, i+1, r);

				// if the remaining part returned true
				// print the current substring and return true
				if(w[i+1] == 1){
					cout<<s.substr(l, i-l+1)<<" ";
					return true;
				}
			}else if(w[i+1] == false)
				continue;
			else
				return true;
		}
	}
	cout<<endl;
	return false;
}

int main(int argc, char const *argv[])
{


	string s;
	while(1){

		cin>>s;
		for (int i = 0; i < s.size(); ++i)
			w[i] = -1;

		wordbreak2(s, 0, s.size()-1);
		cout<<endl;
	}
	return 0;
}
