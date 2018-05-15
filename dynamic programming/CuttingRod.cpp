#include <bits/stdc++.h>

using namespace std;

int arr[10000];

int maxProfit(int n){

	int d[n+1];
	d[0] = 0;
	d[1] = arr[0];

	for (int i = 2; i <= n; ++i)
	{
		d[i] = arr[i-1];

		for(int j = 1; j <= i/2; ++j){
			d[i] = max(d[i], d[j]+d[i-j]);
		}
	}

	return d[n];

}

int main(int argc, char const *argv[])
{
	int t, n;
	cin>>t;

	while(t--){
		cin>>n;

		for (int i = 0; i < n; ++i)
			cin>>arr[i];

		cout<<maxProfit(n)<<endl;

	}
	return 0;
}