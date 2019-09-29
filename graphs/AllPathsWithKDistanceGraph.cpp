#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int> > Graph;

int dp[100][100];

void printPath(vector<int> v){
	int size = v.size();

	for (int i = 0; i < size; ++i)
		cout<<v[i]<<" ";
	
	cout<<endl;
}

bool DFS(Graph g, int curr, int s, int d, int &count, int k, int currlevel){
    if(dp[curr][currlevel]) {
        count++;
        return true;
    }

	if(curr == d && currlevel == k) {
        count++;
        return true;
    }

    if(currlevel >= k)
        return false;

	int size = g[curr].size();

	for (int i = 0; i < size; i++)
	{
		int adj = g[curr][i];
        if(DFS(g, adj, s, d, count, k, currlevel+1))
            dp[adj][currlevel+1] = true;
	}

    return false;
}

void sourceToDestination(Graph g, int s, int d, int k){
	int path_count = 0;

	DFS(g, s, s, d, path_count, k, 0);
	
	cout<<path_count<<endl;

}

void solve(){
	Graph g;
	int V;
	cin>>V;

	g.resize(V);
    
    int edge;

	for (int i = 0; i < V; i++)
	{
        for (int j = 0; j < V; j++)
        {
            cin>>edge;
		    if (edge) g[i].push_back(j);
        }
	}

  
    
	int s, d, k;
	cin>>s>>d>>k;

    memset(dp, 0, 100*100);

	sourceToDestination(g, s, d, k);
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
