#include <bits/stdc++.h>
using namespace std;

int dp[22][22];
void clear(){
    memset(dp,-1,sizeof dp);
}

int dfs(vector<int>* graph,int root,int v,int k){
    if(k==0 && root==v) return 1;
    if(k==0 && root!=v) return 0;
    if(dp[root][k]!=-1) return dp[root][k];
    int count=0;
    for(int i=0;i<graph[root].size();i++){
        count+=dfs(graph,graph[root][i],v,k-1);
    }
    dp[root][k]=count;
    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char c;
        vector<int> graph[n];
        int u,v,k;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>c;
                int val = c-'0';
                if(val) graph[i].push_back(j);
            }
        }
        cin>>u>>v>>k;
        int dp[n][k];
        clear();
        cout<<dfs(graph,u,v,k)<<"\n";
        clear();
    }
    return 0; 
}