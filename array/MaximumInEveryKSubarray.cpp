// https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0/?ref=self

#include <bits/stdc++.h>
using namespace std;

void maximumInEveryK(vector<int>v, int k) {
    int n = v.size();
    if(n == 0)
        return;
    deque<int>dq;

    // rear is max, front is min
    for (int i = 0; i < k; i++){
        if(dq.empty()){
            dq.push_back(i);
        } else{
            if(v[i] <= v[dq.front()]){
                dq.push_front(i);
            } else {
                while(!dq.empty() && v[dq.front()] < v[i]) {
                    dq.pop_front();
                }
                dq.push_front(i);
            }   
        }
    }
    
    cout<<v[dq.back()]<<" ";

    for (int i = k; i < n; i++)
    {
        if(v[i] <= v[dq.front()]){
            dq.push_front(i);
        } else {
            while(!dq.empty() && v[dq.front()] < v[i]) {
                dq.pop_front();
            }
            dq.push_front(i);
        }
        
        while((i - dq.back()) >= k)
            dq.pop_back();
        cout<<v[dq.back()]<<" ";
    }
    
}

int main(int argc, char const *argv[])
{
    int t; cin>>t;
    vector<int> v;
    int n, k, e;
    while(t--){
        cin>>n>>k;
        for (int i = 0; i < n; i++)
        {
            cin>>e;
            v.push_back(e);
        }
        maximumInEveryK(v, k);
    }
    return 0;
}

