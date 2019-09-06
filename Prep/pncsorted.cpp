#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

vector<string> v;

void pnc(string s, int c, int l){
	if(c == l){
		v.push_back(s);
		return;
	}

	for(int i = c; i < l; ++i){
		swap(s[c], s[i]);
		pnc(s, c+1, l);
		swap(s[i], s[c]);
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	string s[10000];
	for(int i=0; i<n; ++i)
		cin>>s[i];
	for(int i=0;i<n;++i){
		pnc(s[i], 0, s[i].length());
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); ++i)
			cout<<v[i]<<" ";
		cout<<endl;
		v.clear();
	}
	return 0;
}