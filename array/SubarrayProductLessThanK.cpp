// https://leetcode.com/problems/subarray-product-less-than-k/

#include <iostream>
using namespace std;


void subarraysProductLessThanK(int arr[], int size, int k){
	int i = 0, j = 0, cnt = 0; // righ end, left end and count
	int product = 1;

	while(i < size){

		product *= arr[i];

		while(product >= k && j <= i){
			product /= arr[j];
			++j;
		}

		// adding count of subarrays ending at i and starting at j
		if(product < k){
			cnt += i-j+1;
		}

		++i;
	}

	printf("%d\n", cnt);
}


int main(int argc, char const *argv[])
{
	int arr[] = {2, 1, 5};
	int size = sizeof(arr)/sizeof(arr[0]);
	int k = 3;

	subarraysProductLessThanK(arr, size, k);
	return 0;
}
