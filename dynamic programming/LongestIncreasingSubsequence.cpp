#include <bits/stdc++.h>

using namespace std;


int arr[2000];


int longestIncreasingSubsequence(int n){
	
	int d[n];

	for (int i = 0; i < n; ++i)
	{
		d[i] = 1;
	}

	d[0] = 1;

	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if(arr[j] < arr[i]){
				d[i] = max(d[i], d[j] + 1);
			}
		}
	}

	int maxLen = 0;

	for (int i = 0; i < n; ++i)
	{
		maxLen = max(maxLen, d[i]);
	}

	return maxLen;

}

int main(int argc, char const *argv[])
{
	int t, n;
	cin>>t;

	while(t--){
		cin>>n;

		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
		}
		cout<<longestIncreasingSubsequence(n)<<endl;
	}
	return 0;
}