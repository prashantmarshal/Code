#include <bits/stdc++.h>

using namespace std;


int longnonrepeatsub(string s){
	map<char, int> hash;
	int beg = 0, len = 1, longest = 1;
	int size = s.length();
	hash[s[0]] = 0;

	int i = 1;

	while(i < size){
		if(hash.find(s[i]) != hash.end()){
			// if occurred before current starting index
			if(hash[s[i]] < beg){
				// updated element index
				hash[s[i]] = i;
				len++;
				longest = max(longest, len);
			}else {
				// update starting index
				beg = hash[s[i]] + 1;
				hash[s[i]] = i;
				len = i-beg+1;
			}
		}else{
			hash[s[i]] = i;
			len++;
			longest = max(longest, len);
		}
		++i;
	}
	return longest;
}

int main(int argc, char const *argv[])
{
	string s = "geeksforgeeks";
	cin>>s;
	cout<<longnonrepeatsub(s)<<endl;
	return 0;
}
