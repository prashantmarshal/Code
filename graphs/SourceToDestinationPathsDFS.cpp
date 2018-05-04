#include <bits/stdc++.h>
using namespace std;

class Graph{

	public:
		int V; // graph size
		list <int> *adj; // pointer to an array of lists

		Graph(int s){
			V = s;
			adj = new list<int>[s];
		}

		void addEdge(int x, int y){
			adj[x].push_back(y);
		}


		void DFSUtil(int v, bool visited[]){
			visited[v] = true;
			cout<<v<<" ";

			list<int>::iterator it;

			for(it = adj[v].begin(); it != adj[v].end(); ++it){
				if(!visited[*it]){

					DFSUtil(*it, visited);
				}
			}
		}

		void DFS(){
			bool visited[V+1];
			memset(visited, 0, V+1);

			DFSUtil(1, visited);
		}

		void BFS(){
			queue<int> q;

			q.push(1);

			int node, size;
			bool visited[V+1];
			memset(visited, 0, V+1);

			visited[1] = true;

			while(!q.empty()){

				size = q.size();

				for (int i = 0; i < size; ++i){
					node = q.front();
					cout<<q.front()<<" ";

					list<int>::iterator it;

					for(it = adj[node].begin(); it != adj[node].end(); ++it){
						if(!visited[*it]){
							q.push(*it);
							visited[*it] = true;
						}
					}
					q.pop();
				}

				cout<<endl; 

			}
		}

		void topologicalSort(){

		}

		void printPath(vector<int> v){
			int size = v.size();

			for (int i = 0; i < size; ++i)
				cout<<v[i]<<" ";

			cout<<endl;
		}

		void printAllPathsUtil(int s, int d, bool visited[], vector<int> &path){

			visited[s] = true;
			path.push_back(s);

			if(s == d){
				printPath(path);
			}else {
				list<int>::iterator it;	

				for (it = adj[s].begin(); it != adj[s].end(); ++it){
					if(!visited[*it])
						printAllPathsUtil(*it, d, visited, path);
				}
			}

			path.pop_back();
			visited[s] = false;
		}

		void printAllPaths(int s, int d){
			bool visited[V+1];
			memset(visited, 0, V+1);
			vector<int> path;

			printAllPathsUtil(s, d, visited, path);

		}

};



int main(int argc, char const *argv[])
{
	Graph g(6);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(2, 5);
	g.addEdge(3, 1);
	g.addEdge(3, 4);
	g.addEdge(3, 5);
	g.addEdge(4, 5);

	int s, d;
	cout<<"Enter source and destination\n";
	cin>>s>>d;

	g.printAllPaths(s, d);

	cout<<"DFS: ";
	g.DFS();
	cout<<endl;


	cout<<"BFS: ";
	g.BFS();
	cout<<endl;

	return 0;
}
