#include <bits/stdc++.h>

using namespace std;

int arr[1000];

// finding pivot

int findMin(int l, int h){
	if(l > h){
		return -1;
	}
	if(l == h){
		return arr[l];
	}

	int mid = (l+h)/2;

	if(arr[mid+1] < arr[mid])
		return arr[mid+1];

	if(mid >= 1 && arr[mid-1] > arr[mid])
		return arr[mid];

	if(arr[mid] <= arr[h]){
		return findMin(l, mid-1);
	}else{
		return findMin(mid+1, h);
	}

}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	int n;
	while(t--){
		cin>>n;
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		int ans = findMin(0, n-1);
		if(ans == -1)
			cout<<arr[0]<<endl;
		else
			cout<<ans<<endl;
	}

	return 0;
}