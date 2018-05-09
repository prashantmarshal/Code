#include <bits/stdc++.h>

using namespace std;

// kadane product
int maxproduct(int arr[], int n){
	int p=0,cp=0,cn=0,temp;


	if(arr[0] > 0)
		p = cp = arr[0];
	else
		cn = arr[0];

	for (int i = 1; i < n; ++i)
	{
		if(arr[i] > 0){
			cn = cn*arr[i];
			cp = max(cp*arr[i], arr[i]);

		}else if(arr[i]<0){
			temp = cp;
			cp = cn*arr[i];
			cn = min(temp*arr[i], arr[i]);
		}else{
			cp = cn = 0;
		}
		p = max(cp, p);
	
	}

	return p;

}

int main(int argc, char const *argv[])
{
	int n; cout<<"Enter array size: "; cin>>n;
	cout<<"Enter array: ";
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}

	cout<<maxproduct(arr, n)<<endl;
	return 0;
}
