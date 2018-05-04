#include <iostream>
#include <algorithm>

using namespace std;


int longestRepeatingSubsequence(string s){
	int n = s.length();

	int d[n][n];

	d[0][0] = 0;

	for (int i = 1; i < n; ++i)
		d[0][i] = (s[0] == s[i] || d[0][i-1]);

	for (int i = 1; i < n; ++i)
		d[i][0] = (s[0] == s[i] || d[i-1][0]);


	for (int i = 1; i < n; ++i)
		for (int j = 1; j < n; ++j)
			if(s[i] == s[j] && i != j){
				d[i][j] = d[i-1][j-1] + 1;
			}
			else{
				d[i][j] = max(d[i-1][j], d[i][j-1]);
			}

	return d[n-1][n-1];
}



int main(){
	int t, n;

	cin>>t;
	string s;
	while(t--){
		cin>>n;
		cin>>s;
		cout<<longestRepeatingSubsequence(s)<<endl;
	}
}