#include <bits/stdc++.h>

using namespace std;

#define N 3

void printMatrix(int arr[][N]){
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

void printRotated(int arr[N][N]){

	int t1,t2,t3,t4;

	for(int d = 0; d < N/2; d++){
		for(int y = d; y < N-d-1; ++y){

			// this d and y are same initially
			// this means they always take the diagonal positions first
			int t = arr[d][y];

			// while filling a top row with last column
			// row is constant and column increases proportionally 
			// column is constant and row increases  proportionally
			
			arr[d][y] = arr[y][N-1-d];

			arr[y][N-1-d] = arr[N-1-d][N-1-y];

			arr[N-1-d][N-1-y] = arr[N-1-y][d];

			arr[N-1-y][d] = t;

		}
	}

	printMatrix(arr);
}

int main(int argc, char const *argv[])
{
	int arr[N][N] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	printRotated(arr);
	return 0;
}