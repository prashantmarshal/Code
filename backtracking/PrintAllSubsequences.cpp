#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<int>& arr, vector<vector<int> >&res, vector<int> &v, int index){

    vector<int> tmp = v;
    if(tmp.size() >= 2)
        res.push_back(tmp);
    
    if(index == arr.size())
        return;
    
    bool visited[201] = {0};
    
    for (int i = index; i < arr.size(); i++)
    {
        if((v.empty() || (arr[i] >= v[v.size()-1])) && !visited[arr[i]+100]){
            v.push_back(arr[i]);
            backtrack(arr, res, v, i+1);
            v.pop_back();            
            visited[arr[i]+100] = true;
        }
    }
}

vector<vector<int>> findSubsequences(vector<int>& arr) {
    vector<vector<int> >res;
    if(arr.size() <= 1)
        return res;

    vector<int> v;
    
    backtrack(arr, res, v, 0);
    return res;
}