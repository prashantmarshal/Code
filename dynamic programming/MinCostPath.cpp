#include <bits/stdc++.h>

using namespace std;


int arr[30][30];

void findMinCost(int n){
	int d[n][n];

	for(int i = 0; i < n; ++i)
		d[0][i] = arr[0][i];

	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int o = INT_MIN,t = INT_MIN,r=INT_MIN;
			if(i > 0)
				o = d[i-1][j];
			if(i>0 && j>0) 
				t = d[i-1][j-1];
			if(j < n - 1)
				r = d[i-1][j+1];

			d[i][j] = arr[i][j] + max(max(o,t),r);
		}
	}

	int low = d[n-1][0];

	for (int i = 1; i < n; ++i)
		low = max(low, d[n-1][i]);

	cout<<low<<endl;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	int n;
	while(t--){
		cin>>n;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin>>arr[i][j];
			}
		}

		findMinCost(n);
	}
	return 0;
}
