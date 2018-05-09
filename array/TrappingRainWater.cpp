#include<bits/stdc++.h>
using namespace std;

int arr[1000];
int findWater(int n)
{
	int l;
	int left[n];
	int right[n];

	int water = 0;

	l = arr[0];
	left[0] = 0;

	for (int i = 1; i < n; i++){
		l = max(l, arr[i]);
		left[i] = l;
	}

	l = arr[n-1];
	right[n-1] = 0;
	for (int i = n-2; i >= 0; i--){
		l = max(l, arr[i]);
		right[i] = l;
	}

	for (int i = 0; i < n; i++)
		if(min(left[i],right[i]) - arr[i] > 0)
			water += min(left[i],right[i]) - arr[i];

	return water;
}

int main()
{

	int t, n;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;++i )
			cin>>arr[i];
		cout <<findWater(n)<<endl;
	}
	return 0;
}

