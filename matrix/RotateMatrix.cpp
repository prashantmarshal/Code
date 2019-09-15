#include <bits/stdc++.h>

using namespace std;

#define N 4

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

void rotate_clockwise(int arr[N][N]){
	// rows will go from d to N/2-1
	// correspondingly columns will go horizontally from d offset from left to (N-1-d)- 1 offset from right
	for(int d = 0; d < N/2; d++){
		for(int y = d; y < N-d-1; ++y){
			int t = arr[d][y];
			
			// offset in column » y, will be equal to offset in row vv
			// offset in row vv d, will be equal to N-1-d
			arr[d][y] = arr[N-y-1][d];

			arr[N-y-1][d] = arr[N-1-d][N-1-y];

			arr[N-1-d][N-1-y] = arr[y][N-d-1];

			arr[y][N-d-1] = t;

		}
	}

	printMatrix(arr);	
}

// anti-clockwise
void rotate_anti_clockwise(int arr[N][N]){

	// rows will go from d to N/2-1
	// correspondingly columns will go horizontally from d offset from left to (N-1-d)- 1 offset from right
	for(int d = 0; d < N/2; d++){
		for(int y = d; y < N-d-1; ++y){
			int t = arr[d][y];
			
			// offset in column » y, will be equal to offset in row vv
			// offset in row vv d, will be equal to N-1-d
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
		{1, 2, 3, 4}, 
        {5, 6, 7, 8}, 
        {9, 10, 11, 12}, 
        {13, 14, 15, 16} 
	};

	rotate_anti_clockwise(arr);
	return 0;
}
