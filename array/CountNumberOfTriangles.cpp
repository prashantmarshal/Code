#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long int n;
    cin>>n;
    int *v = new int[n];
    long long int k;
    for (long long int i = 0; i < n; i++)
    {
        cin>>k;
        v[i] = k;
    }
    
    sort(v, v+n);

    long long int count = 0;
    long long int i=0,j=n-1;

    while(j >=2){
        i=0,k=j-1;

        while(i<k){
            if(v[i]+v[k]>v[j]){
               count+=k-i;
               k--; 
            } else if(v[i]+v[k] <= v[j]){
                i++;
            }
        }
        j--;
    }

    cout<<count<<endl;    
}

int main(int argc, char const *argv[])
{
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
