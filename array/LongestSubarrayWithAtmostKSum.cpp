#include <bits/stdc++.h>
#include <vector>
using namespace std;

int longestSumArray(vector<int> v, int target){

    int n=v.size();
    int s=0;
    int ans=0;
    vector<int> T(n);

    for(int i=0;i<n;i++){
        s+=v[i];
        if(s<=target) {
            ans=i+1;
        }
        else {
            // need s-T[k]<=target
            // T[k]>=s-target
            while(ans < i && T[i-ans-1] >= s-target)  
                ans++;
        }

        if(i==0)
            T[i]=s;
        else    
            T[i]=max(T[i-1],s);
    }
    return ans;
}

int main(void){

    vector<int> v {1, 1, 1000, 1, 1, 1, 5, -3, 6};
    cout<<longestSumArray(v, 7)<<endl;
    return 0;
}
