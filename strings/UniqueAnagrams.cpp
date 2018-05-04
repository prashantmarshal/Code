#include <bits/stdc++.h>

using namespace std;


void printAnagramsCount(string s[], int n){

	for (int i = 0; i < n; ++i)
		sort(s[i].begin(), s[i].end());

	map<string, int> hash;

	for (int i = 0; i < n; ++i)
		hash[s[i]]++;

	std::map<string, int>::iterator it;

	int size = hash.size();
	int arr[size];

	for (it = hash.begin(); it != hash.end(); ++it)
		arr[i] = it->second;

	sort(arr, arr+size);

	for (int i = 0; i < size; ++i)
		cout<<arr[i]<<" ";
	cout<<endl;

}


int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	int n;
	while(t--){
		cin>>n;
		string s[n];
		for (int i = 0; i < n; ++i)
			cin>>s[i];
		printAnagramsCount(s, n);
	}

	return 0;
}
