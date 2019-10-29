#include <bits/stdc++.h>
using namespace std;

void findMax(string s, int index, int k, string &maxnum){
    if(k == 0) return;
    int n = s.length();
    if(index == n-1) return;

    // For every index, we have two steps:
    // a. swap that index with a righter element
    // b. don't swap that element 
    for(int j = index; j < n; ++j){
        // why in drunk mind will we swap with a lower element?
        if(s[index] < s[j]) {
            swap(s[index], s[j]);
            if(maxnum < s) maxnum = s;
            findMax(s, index+1, k-1, maxnum);
            swap(s[index], s[j]);
        }
    }
    findMax(s, index+1, k, maxnum);
}

void solve(){
    int k; cin>>k;
    string s; cin>>s;

    int index = 0;
    string maxnum = s;
    findMax(s, index, k, maxnum);
    cout<<maxnum<<endl;
}

int main(int argc, char const *argv[])
{
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
