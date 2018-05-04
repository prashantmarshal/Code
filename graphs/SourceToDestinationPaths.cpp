#include <bits/stdc++.h>
using namespace std;

class Graph{

public:
	vector<vector <int> > v;
};

void printpath(std::vector<int> v){
	int size = v.size();

	for (int i = 0; i < size; ++i)
		cout<<v[i]<<" ";
	
	cout<<endl;
}


bool temp_node_in_cycle(std::vector<int> v, int node){
	int size = v.size();

	for (int i = 0; i < size; ++i)
		if(v[i] == node)
			return true;

	return false;
}

void printsd(Graph g, int s, int d, int size){
	queue<vector<int> > q;

	vector<int> path;
	path.push_back(s);

	q.push(path);

	while(!q.empty()){
		vector<int> temp_path = q.front();
		q.pop();

		if(temp_path[temp_path.size()-1] == d)
			printpath(temp_path);

		int last_node = temp_path[temp_path.size()-1];

		int ls = g.v[last_node].size();
		for (int i = 0; i < ls; ++i){
			int temp_node = g.v[last_node][i];
			if(!temp_node_in_cycle(temp_path, temp_node)){
				vector<int> v(temp_path);
				v.push_back(temp_node);
				q.push(v);
			}
		}
	}
}

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