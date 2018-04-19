#include <bits/stdc++.h>

using namespace std;

#define N 4


bool issafe(int arr[N][N], int x, int y){
	if(x>=0 && x<N && y>=0 && y<N && arr[x][y]){

		return true;
	}
	return false;
}

bool solvemazeutil(int arr[N][N], int sol[N][N], int x, int y){
	if(x == N-1 && y == N-1){
		sol[x][y] = 1;
		return true;
	}

	if(issafe(arr, x, y)){
		sol[x][y] = 1;
		if(solvemazeutil(arr, sol, x, y+1))
			return true;

		if(solvemazeutil(arr, sol, x+1, y))
			return true;
		sol[x][y] = 0;

		return false;
	}
	return false;

}
void printsol(int sol[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf(" %d ", sol[i][j]);
		printf("\n");
	}
}


void solvemaze(int arr[N][N]){
	int sol[N][N] = {0};

	if(solvemazeutil(arr, sol, 0, 0))
		printsol(sol);
	else
		printf("Cant\n");


}

int main(int argc, char const *argv[])
{
	int arr[N][N]  =  { {1, 0, 0, 0},
		{1, 1, 0, 1},
		{0, 1, 0, 0},
		{1, 1, 1, 1}
	};

	solvemaze(arr);
	return 0;
}
