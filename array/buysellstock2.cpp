#include<iostream>
using namespace std;

int profit(int arr[], int n){

	int *profit = new int[n];
	int min = arr[0];


	for (int i = 1; i < n; ++i){
		if(arr[i] < min){
			min = arr[i];
			profit[i] = profit[i-1];
		}else{
			profit[i] = max(profit[i-1], arr[i] - min);
		}
	}

	int maxx = arr[n-1];

	for (int i = n-2; i >= 0; --i)
	{
		if(arr[i] > maxx){
			maxx = arr[i];
		}else{
			profit[i] = max(profit[i+1], maxx - arr[i] + profit[i]);
		}
	}

	int result = profit[0];

	delete profit[]; // delete profit will delete only first pointer 
	return result;

}

int main()
{
	int price[] = {2, 30, 15, 10, 8, 4, 7, 20, 10, 12, 34, 21, 34, 10, 25, 80};
	int n = sizeof(price)/sizeof(price[0]);
	cout <<profit(price, n)<<endl;
	return 0;
}
