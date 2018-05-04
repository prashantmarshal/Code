#include <iostream>
using namespace std;


void findNumberOfSubarraysProductLessThanK(int arr[], int size, int k){
	int i = 0, j = 0, cnt = 0;
	int product = 1;

	while(i < size){

		product *= arr[i];

		while(product >= k && j <= i){
			product /= arr[j];
			++j;
		}

		if(product < k){
			cnt += i-j+1;
		}

		++i;
	}

	cout<<cnt<<endl;

}


int main(int argc, char const *argv[])
{
	int arr[] = {1,2,2,2,4,4,3,4,3,4,34,2,342,34,34,5};
	int size = sizeof(arr)/sizeof(arr[0]);
	int k = 100;

	findNumberOfSubarraysProductLessThanK(arr, size, k);
	return 0;
}