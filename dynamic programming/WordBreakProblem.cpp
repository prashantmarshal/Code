#include <bits/stdc++.h>
#include <string.h>

using namespace std;

string dictionary[] = {"mobile","samsung","sam","sung",
                            "man","mango","icecream","and",
                             "go","i","like","ice","cream"};

<<<<<<< HEAD
// w[i] will be true if string from ith index to last index is valid
=======
>>>>>>> a6e78bb4405484318dc2c755222b8e04875cadf5
int w[100];
bool doesContain(string s){
	int size = sizeof(dictionary)/sizeof(dictionary[0]);
	for (int i = 0; i < size; ++i)
		if(s == dictionary[i])
			return true;
	return false;
}


bool wordbreak(string s, int l, int r){
	if(l > r)
		return true;
	for (int i = 1; i <= (r-l+1); ++i)
	{
		if(doesContain(s.substr(l, i))){
<<<<<<< HEAD
			
			// if this is the last piece of the string
			if(l+i-1 == r) {
				w[l] = 1;
				cout<<s.substr(l, i)<<endl;
				return true;
			}

			// if the rest of the string is undiscovered
			if(w[l+i] == -1) {
				w[l+i] = wordbreak(s, l+i, r);
				if(w[l+i] == 1){
					cout<<s.substr(l, i)<<endl;
					return true;
				}
			} else if(w[l+i] == 0) // if the remaining string cannot be broken, the current partition at length i is not valid
=======
			if(l+i-1 == r) {
				w[l] = 1;
				return true;
			}

			if(w[l+i] == -1) {
				w[l+i] = wordbreak(s, l+i, r);
				if(w[l+i] == 1)
					return true;
			} else if(w[l+i] == 0)
>>>>>>> a6e78bb4405484318dc2c755222b8e04875cadf5
				continue;
			else
				return true;
		}
	}

	return false;
}

int main(int argc, char const *argv[])
{
	

	string s;
	while(1){
		
		cin>>s;
		for (int i = 0; i < s.size(); ++i)
			w[i] = -1;
		if(wordbreak(s, 0, s.size()-1))
			cout<<"String "<<s<<" is in dictionary\n";
		else
			cout<<"String "<<s<<" is not in dictionary\n";
	}
	return 0;
}