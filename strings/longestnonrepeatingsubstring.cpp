#include <bits/stdc++.h>
using namespace std;

int longnonrepeatsub(string s){
	if (s == "") return 0;
	
	int hash[26];
	memset(hash, -1, 26);

	int start_index = 0, len = 0, maxlen = 1;
	int size = s.length();
	
	int i = 0;

	while(i < size){
		if(hash[s[i]-'a'] != -1){
			// if occurred before current starting index
			if(hash[s[i]-'a'] < start_index){
				len++;
			}else{
				// update starting index
				start_index = hash[s[i]-'a'] + 1;
				len = i-start_index+1;
			}
		}else{
			len++;
		}

		// updated element index
		hash[s[i]-'a'] = i;
		maxlen = max(maxlen, len);
		++i;
	}

	return maxlen;
}

int main(int argc, char const *argv[])
{
	string s = "geeksforgeeks";
	cin>>s;
	cout<<longnonrepeatsub(s)<<endl;
	return 0;
}


/* 
Leetcode having ' ' (32) character

if (s == "") return s.length();

int hash[256];
for(int i=0; i<256; ++i) hash[i] = -1;

int start_index = 0, len = 0, maxlen = 1;
int size = s.length();

int i = 0;

while(i < size){
	if(hash[s[i]-' '] != -1){
		// if occurred before current starting index
		if(hash[s[i]-' '] < start_index){
			len++;
		}else{
			// update starting index
			start_index = hash[s[i]-' '] + 1;
			len = i-start_index+1;
		}
	}else{
		len++;
	}

	// updated element index
	hash[s[i]-' '] = i;
	maxlen = max(maxlen, len);
	++i;
}

return maxlen;
*/
