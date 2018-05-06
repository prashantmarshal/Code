#include <bits/stdc++.h>

using namespace std;


void DFS(vector< vector<long> > &graph, long src, bool visited[], long *cnt){
	visited[src] = true;
	(*cnt)++;

	vector<long>::iterator it;
	
	for(it = graph[src].begin(); it != graph[src].end(); ++it){
		if(!visited[*it]){
			DFS(graph, *it, visited, cnt);
		}
	}
}

long cost(vector< vector<long> > &graph, long n, long m, long cl, long cr){
	bool visited[n+1];
	memset(visited, 0, n+1);

	long cnt, total_cnt = 0;

	for(long i = 1; i <= n; ++i){
		cnt = 0;
		if(!visited[i]){
			DFS(graph, i, visited, &cnt);
		}else
			continue;
		if(cl < cr){
			total_cnt += cl*cnt;
		}else{
			total_cnt += cl + (cnt-1)*cr;
		}
	}

	return total_cnt;
}

int main(int argc, char const *argv[])
{
	long t;
	cin>>t;


	while(t--){
		long n,m,cl,cr,x,y;

		cin>>n>>m>>cl>>cr;
		vector<vector<long> > graph(n+1);
		for (long i = 0; i < m; ++i){
			cin>>x>>y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		cout<<cost(graph, n, m, cl, cr)<<endl;
	}
	return 0;
}