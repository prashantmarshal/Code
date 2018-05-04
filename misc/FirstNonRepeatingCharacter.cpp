#include <bits/stdc++.h>

using namespace std;


void firstNonRepeatingCharacter(char s[], int n){
	char charset[256] = {0};

	for (int i = 0; i < n; ++i)
		charset[s[i]-'a']++;

	for (int i = 0; i < n; ++i)
		if(charset[s[i]-'a'] == 1){
			cout<<s[i]<<endl;
			return;
		}

	cout<<"-1"<<endl;

}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;

		char s[n];

		for (int i = 0; i < n; ++i)
				cin>>s[i];

		firstNonRepeatingCharacter(s, n);
	}

	return 0;
}