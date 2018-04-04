#include <iostream>
using namespace std;


int findinsortedrotatearray(int *arr, int l, int h, int element){
	if(l > h)
		return -1;

	int mid = (l+h)/2;

	if(element==arr[mid])
		return mid;
	
	else if(arr[h] < arr[mid]){

		if(element > arr[mid])
			return findinsortedrotatearray(arr, mid+1, h, element);
		else {
			if(element < arr[l])
				return findinsortedrotatearray(arr, mid+1, h, element);
			return findinsortedrotatearray(arr, l, mid-1, element);
		}
	
	}else if(arr[h] > arr[mid]){
	
		if(element < arr[mid])
			return findinsortedrotatearray(arr, l, mid-1, element);
		else {
			if(element > arr[h])
				return findinsortedrotatearray(arr, l, mid-1, element);
			return findinsortedrotatearray(arr, mid+1, h, element);
		}
	}

	return -1;
}

int main(int argc, char const *argv[])
{
	int test_cases;
	cin>>test_cases;
	
	for (int i = 0; i < test_cases; ++i)
	{
		int size;
		cin>>size;
		int arr[size];
		for(int k=0;k<size;++k){
			cin>>arr[k];
		}
		int elem;
		cin>>elem;
		cout<<findinsortedrotatearray(arr, 0, size-1, elem)<<endl;
	}
	return 0;
}