#include <bits/stdc++.h>
using namespace std;


// Always point to the left most negative and check if it belongs to current window
void util(vector<int> &v, int n, int k){
    int ptr = 0;

    while(ptr < n && v[ptr] >= 0){
        ptr++;
    }
    // ptr pointing to first negative number

    for (int i = 0; i < n-k+1; i++)
    {
        if(ptr <= i+k-1 && ptr >= i){
            cout<<v[ptr]<<" ";
            continue;
        }
        
        if(ptr <= i) {
            ptr++;
            while(ptr < n && v[ptr] >= 0){
                ptr++;
            }
            if(ptr <= i+k-1 && ptr >= i){
                cout<<v[ptr]<<" ";
                continue;
            }
        }

        cout<<0<<" ";
    }
    cout<<endl;
}

void solve(){
    int n, t;
    cin>>n;
    vector<int>v;
    for (int i = 0; i < n; i++)
    {
        cin>>t;
        v.push_back(t);
    }
    int k; cin>>k;
    util(v, n, k);    
}

int main(){
    int T;cin>>T;
    while(T--) solve();
}