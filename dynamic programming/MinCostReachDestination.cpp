#include <bits/stdc++.h>

using namespace std;

#define N 4

int minCost(int cost[][N]){

	int d[N];

	for (int i = 0; i < N; ++i)
		d[i] = INT_MAX;

	d[0] = 0;

	for (int i = 1; i < N; ++i){
		for (int j = 0; j < i; ++j){
			if(d[i] > d[j] + cost[j][i]){
				d[i] = d[j] + cost[j][i];
			}

		}
	}

	return d[N-1];
}

int main(int argc, char const *argv[])
{
	int cost[N][N] = { {0, 155, 850, 930},
		{INT_MAX, 0, 445, 550},
		{INT_MAX, INT_MAX, 0, 740},
		{INT_MAX, INT_MAX, INT_MAX, 060}
	};
	cout<<minCost(cost)<<endl;
	return 0;
}
