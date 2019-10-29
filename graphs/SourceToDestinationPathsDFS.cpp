#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int> > Graph;

void printPath(vector<int> v){
	int size = v.size();

	for (int i = 0; i < size; ++i)
		cout<<v[i]<<" ";
	
	cout<<endl;
}

// To check if this vertex is part of current curr_path already
bool isVisited(vector<int> v, int vertex){
	int size = v.size();

	for (int i = 0; i < size; ++i)
		if(v[i] == vertex)
			return true;

	return false;
}

void DFS(Graph g, vector<int> path, int s, int d, int &count){
	// Push current vertex into the vector
	path.push_back(s);		
	
	if(s == d) {
		count++;
		path.pop_back();
		return;
	}

	int size = g[s].size();

	for (int i = 0; i < size; i++)
	{
		int adj = g[s][i];
		if(!isVisited(path, adj)) { // To check for cycle, we do not want to go back to the vertex already included in the current stack
			DFS(g, path, adj, d, count);
		}
	}

	// Pop current vertex from the vector
	path.pop_back();
}

void sourceToDestination(Graph g, int s, int d){
	int path_count = 0;
	vector<int>path;

	DFS(g, path, s, d, path_count);
	
	cout<<path_count<<endl;
}

void solve(){
	Graph g;
	int V, E;
	cin>>V>>E;

	g.resize(V);
	int u, v;

	for (int i = 0; i < E; i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
	}

	int s, d;
	cin>>s>>d;
	
	sourceToDestination(g, s, d);
}

int main(int argc, char const *argv[])
{

	int t; cin>>t;

	while (t--)
	{
		solve();
	}

	return 0;	
}
