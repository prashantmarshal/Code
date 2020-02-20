#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n; 
    cin>>n;
    vector<int> low(n, 0), high(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin>>low[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        cin>>high[i];
    }

    int l = 0, h = 0;
    int maxsum = 0;

    for (int i = 0; i < n; i++)
    {
        maxsum = max(max(high[i] + l, low[i] + h), maxsum); 
        l = h;
        h = maxsum;   
    }
    
    cout<<maxsum<<endl;
}

int main(int argc, char const *argv[])
{
    int T; cin>>T;

    while(T--){
        solve();
    }
    return 0;
}
