#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int A[100007];

int findthreesum(int gsum, int n){

    for (size_t i = 0; i < n; i++)
    {
        // one of three inserted
        unordered_set<int> t;
        int sum = gsum - A[i];

        for (size_t j = i+1; j < n; j++)
        {
            if(t.find(sum - A[j]) != t.end()) {
                return 1;
            }    
            t.insert(A[j]);
        }
    }

    return 0;  
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int sum, n;
        cin>>n>>sum;

        for (size_t i = 0; i < n; i++)
        {
            cin>>A[i];
        }
        cout<<findthreesum(sum, n)<<endl;                

    }
}