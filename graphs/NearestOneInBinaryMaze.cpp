#include <bits/stdc++.h>

using namespace std;

#define N 25

int arr[N][N];

class Point
{
	public:
		int x;
		int y;

		Point(int i, int j){
			x = i;
			y = j;
		}
};

bool isSafe(int x, int y, int n, int m){
	if(x >= n || y >= m || x < 0 || y < 0)
		return false;
	return true;
}

int d[2][4] = {
	{0,1,0,-1},
	{1,0,-1,0}
};

void nearestOne(int n, int m){
	queue<Point> q;
	int dist[n][m];
	bool visited[n][m];
	memset(dist, 0, sizeof(int)*n*m);
	memset(visited, 0, n*m);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if(arr[i][j] == 1){
				q.push(Point(i,j));
				visited[i][j] = 1;
				dist[i][j] = 0;
			}

	while(!q.empty()){
		Point p = q.front();
		q.pop();

		// going in all directions
		for (int i = 0; i < 4; ++i)
		{
			if(isSafe(p.x + d[0][i], p.y + d[1][i], n, m) && !visited[p.x + d[0][i]][p.y + d[1][i]]){
				visited[p.x + d[0][i]][p.y + d[1][i]] = 1;
				dist[p.x + d[0][i]][p.y + d[1][i]] = dist[p.x][p.y] + 1;
				q.push(Point(p.x + d[0][i], p.y + d[1][i]));
			}
		}
	}

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j)
			cout<<dist[i][j]<<" ";
	}
	cout<<endl;	
}

int main(int argc, char const *argv[])
{
	int t, n, m;
	cin>>t;

	while(t--){
		cin>>n>>m;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				cin>>arr[i][j];

		nearestOne(n, m);
	}
	return 0;
}
