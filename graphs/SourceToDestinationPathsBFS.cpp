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

void sourceToDestination(Graph g, int s, int d){
	
	queue<vector<int> > q;
	vector<int> curr_path;

	curr_path.push_back(s);
	q.push(curr_path);

	int path_count = 0;

	while(!q.empty()){

		curr_path = q.front();
		q.pop();

		int last = curr_path[curr_path.size()-1];
		if(last == d)
			// printPath(curr_path);
			path_count++;

		int size = g[last].size();

		for (int i = 0; i < size; ++i){
			int adj = g[last][i];
			
			if(!isVisited(curr_path, adj)){
				vector<int> v(curr_path);
				v.push_back(adj);
				q.push(v);
			}
		}
	}

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
