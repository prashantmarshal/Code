#include <bits/stdc++.h>

using namespace std;

void sorted(int arr1[], int arr2[], int n1, int n2){
	int i = 0, j = 0, k = 0;
	int arr3[n1+n2];
	while(i < n1 && j < n2){
		if(arr1[i] < arr2[j]){
			arr3[k] = arr1[i];
			k++;
			i++;
		}else{
			arr3[k] = arr2[j];
			k++;
			j++;
		}
	}

	while(i < n1){
		arr3[k] = arr1[i];
		k++;
		i++;
	}

	while(j < n2){
		arr3[k] = arr2[j];
		k++;
		j++;
	}

	for (int i = 0; i < n1+n2; ++i)
		cout<<arr3[i]<<" ";

	cout<<endl;
	if((n1+n2)%2 == 0)
		cout<<(arr3[(n1+n2)/2] + arr3[(n1+n2)/2+1])/2;
	else
		cout<<arr3[(n1+n2)/2];
	
	cout<<endl;
}

int main(int argc, char const *argv[])
{

	int arr1[] = {1,3,4,5,7, 8,10};
	int arr2[] = {1,3,5,9,12};
	int n1,n2;
	n1 = sizeof(arr1)/sizeof(arr1[0]);
	n2 = sizeof(arr2)/sizeof(arr2[0]);

	sorted(arr1, arr2, n1, n2);
	return 0;
}