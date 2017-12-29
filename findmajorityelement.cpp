#include <iostream>
using namespace std;

int findmajorityelement(int *arr, int size){
	if(size==1)
		return arr[0];
	int cnt=1;
	int elem = arr[0];
	for (int i = 1; i < size; ++i)
	{	
		if(arr[i]==elem){
			cnt++;
			continue;
		}else{
			cnt--;
			if(cnt==0){
				elem = arr[i];
				cnt=1;
			}
		}
	}

	cnt = 0;
	for (int i = 0; i < size; ++i)
	{
		if(arr[i]==elem)
			cnt++;
	}

	if(cnt >= size/2 +1)
		return elem;
	else
		return -1;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;

	for (int i = 0; i < t; ++i)
	{
		int s;
		cin>>s;
		int arr[s];
		for (int k=0;k<s; ++k)
		{
			cin>>arr[k];
		}

		int ans = findmajorityelement(arr,s);
		if(ans!=-1)
			cout<<ans<<endl;
		else
		printf("NO Majority Element\n");
	}
	return 0;
}