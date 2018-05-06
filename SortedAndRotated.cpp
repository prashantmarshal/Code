#include <iostream>
using namespace std;

// you need to classify on the basis of Where is mid?

int findRotated(int *arr, int l, int h, int element){
	if(l > h)
		return -1;

	int mid = (l+h)/2;

	if(element==arr[mid])
		return mid;
	
	else if(arr[h] < arr[mid]){

		if(element > arr[mid])
			return findRotated(arr, mid+1, h, element);
		else {
			if(element < arr[l])
				return findRotated(arr, mid+1, h, element);
			return findRotated(arr, l, mid-1, element);
		}
	
	}else if(arr[h] > arr[mid]){
	
		if(element < arr[mid])
			return findRotated(arr, l, mid-1, element);
		else {
			if(element > arr[h])
				return findRotated(arr, l, mid-1, element);
			return findRotated(arr, mid+1, h, element);
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
		cout<<findRotated(arr, 0, size-1, elem)<<endl;
	}
	return 0;
}
