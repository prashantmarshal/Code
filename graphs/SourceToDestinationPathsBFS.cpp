#include <bits/stdc++.h>
using namespace std;

class Graph{

public:
	vector<vector <int> > v;
};

void printPath(vector<int> v){
	int size = v.size();

	for (int i = 0; i < size; ++i)
		cout<<v[i]<<" ";
	
	cout<<endl;
}


bool isVisited(vector<int> v, int node){
	int size = v.size();

	for (int i = 0; i < size; ++i)
		if(v[i] == node)
			return true;

	return false;
}

void sourceToDestination(Graph g, int s, int d){
	
	queue<vector<int> > q;
	vector<int> path;

	path.push_back(s);
	q.push(path);

	while(!q.empty()){

		path = q.front();
		q.pop();

		if(path[path.size()-1] == d)
			printPath(path);

		int next = path[path.size()-1];

		int size = g.v[next].size();

		for (int i = 0; i < size; ++i){
			int adj = g.v[next][i];
			if(!isVisited(path, adj)){
				vector<int> v(path);
				v.push_back(adj);
				q.push(v);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	Graph g;

	// we are indexing from 1
	g.v.resize(6);
	g.v[1].push_back(2);
	g.v[2].push_back(3);
	g.v[3].push_back(5);
	g.v[2].push_back(5);
	g.v[4].push_back(5);
	g.v[5].push_back(4);

	int s, d;
	cout<<"Enter s and d\n";
	cin>>s>>d;

	sourceToDestination(g, s, d);
	return 0;
}
