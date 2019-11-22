#include <bits/stdc++.h>
using namespace std;


void minThrows(){
    int n; cin>>n;
    map<int, int> game;
    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin>>a>>b;
        game[a] = b;
    }
     
    vector<vector<int> > graph;
    graph.push_back(vector<int>());

    for (int i = 1; i <= 30; i++)
    {
        graph.push_back(vector<int>());
        
        for (int j = 1; j <= 6; j++)
        {
            if(i+j > 30) continue;
            if(game.count(i)) continue;

            if(game.count(i+j)){
                graph[i].push_back(game[i+j]);
            } else {
                graph[i].push_back(i+j);
            }
        }
    }

    queue<int>q;
    q.push(1);
    bool visited[30];
    memset(visited, 0, sizeof(bool)*30);

    int minval = 0;

    while(!q.empty()){
        int size = q.size();

        for(int j = 0; j < size; ++j){
            int top = q.front();
            visited[top-1] = true;
            q.pop();
            if(top == 30) break;
            
            for(int i = 0; i < graph[top].size(); ++i){
                if(!visited[graph[top][i]-1])
                    q.push(graph[top][i]);
            }
        }
        minval++;
    }
    
    cout<<minval<<endl;

}

int main(int argc, char const *argv[])
{
    int T; cin>>T;
    while(T--) minThrows();
    return 0;
}
