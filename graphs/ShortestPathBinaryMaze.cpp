#include <bits/stdc++.h>
using namespace std;


class Graph {
public:
	int V;
	list<int*> adj;

	Graph(int s){
		V = s;
		adj = new list<int>[s];
	}

	void addEdge(int x, int y){
		adj[x].push_back(y);
	}

	
};

int main(int argc, char const *argv[])
{
	Graph g;
	g.v.resize(5);
	g.v[1].push_back(2);
	g.v[1].push_back(3);
	g.v[2].push_back(4);
	g.v[2].push_back(5);
	g.v[3].push_back(1);
	g.v[3].push_back(4);
	g.v[3].push_back(5);
	g.v[4].push_back(5);

	int s, d;
	cout<<"Enter s and d\n";
	cin>>s>>d;

	printsd(g, s, d, 4);
	return 0;
}
