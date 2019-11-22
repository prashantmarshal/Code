/*works only for graphs having no cycles*/

#include <bits/stdc++.h>
using namespace std;

void DFS(std::vector< pair<int, int> >graph[], int src, std::vector<bool> &visited, 
	int curr_len, int *length){

	visited[src] = 1;

	/* how many vertices are connected to this vertex */
	int len = graph[src].size();

	pair<int, int> set;

	for (int i = 0; i < len; ++i)
	{
		set = graph[src][i];

		if(!visited[set.first]){

			curr_len += set.second;
			DFS(graph, set.first, visited, curr_len, length);

			if(curr_len > *length){
				*length = curr_len;
			}

			curr_len -= set.second;
			// this statement makes it work for cyclic graphs also
			// as it explores all DFS paths
			visited[set.first] = false; 

		}

	}

}

int longestCable(std::vector< pair<int, int> >graph[], int size){
	
	int length = INT_MIN;

	for (int i = 1; i <= size; ++i){
		std::vector<bool> v(size+1, false);
		DFS(graph, i, v, 0, &length);
	}

	return length;
}

int main(int argc, char const *argv[])
{
	int n = 7;

	vector< pair<int,int> > graph[n+1];

	graph[1].push_back(make_pair(2, 5));
	graph[2].push_back(make_pair(3, 2));
	graph[2].push_back(make_pair(1, 5));

	// second edge

	graph[3].push_back(make_pair(2, 2));

	// third edge
	graph[3].push_back(make_pair(4, 5));
	graph[4].push_back(make_pair(3, 5));

	// fourth edge
	graph[3].push_back(make_pair(1, 20));
	graph[1].push_back(make_pair(3, 20));

	/*// fifth edge
	graph[5].push_back(make_pair(6, 54));
	graph[6].push_back(make_pair(5, 54));

	graph[1].push_back(make_pair(2, 3));
	graph[2].push_back(make_pair(1, 3));
	
	graph[2].push_back(make_pair(3, 4));
	graph[3].push_back(make_pair(2, 4));
	
	graph[2].push_back(make_pair(6, 2));
	graph[6].push_back(make_pair(2, 2));*/
	
	/*graph[4].push_back(make_pair(6, 6));
	graph[6].push_back(make_pair(4, 6));
	
	graph[5].push_back(make_pair(6, 5));
	graph[6].push_back(make_pair(5, 5));

	graph[1].push_back(make_pair(2, 1));
	graph[2].push_back(make_pair(1, 1));

	graph[2].push_back(make_pair(3, 1));
	graph[3].push_back(make_pair(2, 1));
	
	graph[3].push_back(make_pair(4, 1));
	graph[4].push_back(make_pair(3, 1));

	graph[4].push_back(make_pair(5, 1));
	graph[5].push_back(make_pair(4, 1));

	graph[2].push_back(make_pair(7, 1));
	graph[7].push_back(make_pair(2, 1));

	graph[6].push_back(make_pair(7, 1));
	graph[7].push_back(make_pair(6, 1));

	graph[1].push_back(make_pair(6, 1));
	graph[6].push_back(make_pair(1, 1));*/

	cout << "Maximum length of cable = \n"
	<< longestCable(graph, n)<<endl;

	return 0;
}


