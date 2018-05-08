#include <bits/stdc++.h>

using namespace std;

int arr[1000];

void printZigZag(int n){
	bool flag = true;
	int temp;
	for (int i = 0; i < n-1; ++i)
	{
		if(flag){
			temp = arr[i];
			arr[i] = min(arr[i], arr[i+1]);
			arr[i+1] = max(temp, arr[i+1]);
		}else{
			temp = arr[i];
			arr[i] = max(arr[i], arr[i+1]);
			arr[i+1] = min(temp, arr[i+1]);
		}
		flag = !flag;
	}

	for (int i = 0; i < n; ++i)
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
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		printZigZag(n);
	}
	return 0;
}