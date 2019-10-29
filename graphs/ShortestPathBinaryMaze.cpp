#include <bits/stdc++.h>
using namespace std;

struct Position {
	pair<int, int> point;
	int length;
	
	Position (pair<int, int> xy, int len = 0){
		point = xy;
		length = len;
	}
};

bool isSafe(vector<vector<int> >&graph, Position xy, int N){
	
	if(xy.point.first >= 0 && xy.point.second >= 0 && xy.point.first < N && xy.point.second < N && !graph[xy.point.first][xy.point.second] && !hashed[xy.point.first][xy.point.second])
		return true;

	return false;
}

Position directions[8] = {make_pair(1,0), make_pair(0,1), make_pair(-1,0), make_pair(0,-1), make_pair(1,1), make_pair(-1,-1), make_pair(1,-1), make_pair(-1,1)};

bool hashed[501][501];

// In this question we are finding minimum distance path from src to dest with obstacles in between
int shortestPathBinaryMatrix(vector<vector<int> > &graph) {
	int N = graph.size();
	vector<int> s({0,0}), d({N-1,N-1});

	if(graph[s[0]][s[1]]) return -1;

	Position src(make_pair(s[0], s[1]));
	Position dest(make_pair(d[0], d[1]));

	queue<Position>q;
	q.push(src);

	memset(hashed, 0, 501*501);
	hashed[s[0]][s[1]] = true;

	while(!q.empty()){
		Position curr = q.front();
		q.pop();

		if(curr.point.first == d[0] && curr.point.second == d[1]){
			return curr.length;
		}

		for(int dir = 0; dir < 8; ++dir) {
			Position newCurr(make_pair(curr.point.first+directions[dir].point.first, curr.point.second+directions[dir].point.second), curr.length+1);
			if(isSafe(graph, newCurr, N)){
				hashed[newCurr.point.first][newCurr.point.second] = true;
				q.push(newCurr);
			}
		}
	}
	return -1;
}

int main(){

}