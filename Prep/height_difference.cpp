#include <iostream>
#include <algorithm>
using namespace std;

void func(int *arr, int *arr2, int n, int k){
	int small=INT_MAX, big=INT_MIN;
	int smalli=-1, bigi=-1;
	
	for (int i = 0; i < n; ++i){
		if(arr[i]>big){
			big=arr[i];
			bigi=i;
		}
		if(arr[i]<small){
			small=arr[i];
			smalli=i;
		}
	}
	if(big-small < k){
		for (int i = 0; i < n; ++i)
			cout<<arr[i]+k<<" ";
		cout<<endl;
		return;
	}

	int ans = big-small;

	arr[smalli]+=k;
	arr[bigi]-=k;

	big=max(arr[smalli],arr[bigi]);
	small=min(arr[smalli],arr[bigi]);

	for (int i = 0; i < n; ++i){
		if(i!=smalli && i!=bigi){
			if(arr[i]+k < big){
				arr[i]+=k;
				continue;
			}else if(arr[i]-k > small){
				arr[i]-=k;
				continue;
			}else{
				if((big - (arr[i]-k)) > ((arr[i]+k) - small)){
					big=max(big,arr[i]+k);
					arr[i]+=k;
				}else{
					small=min(small,arr[i]-k);
					arr[i]-=k;
				}
			}
		}
	}
	sort(arr,arr+n);
	sort(arr2,arr2+n);
	if(ans > (big-small)){
		for (int i = 0; i < n; ++i)
			cout<<arr[i]<<" ";
		cout<<endl;
	}else{
		for (int i = 0; i < n; ++i)
			cout<<arr2[i]<<" ";
		cout<<endl;
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter n size\n";
	cin>>n;
	int k;
	cout<<"Enter k size\n";
	cin>>k;
	int arr[n], arr2[n];
	cout<<"Enter array elements\n";
	for (int i = 0; i < n; ++i){
		cin>>arr[i];
		arr2[i]=arr[i];
	}
	func(arr,arr2,n,k);
	return 0;
}