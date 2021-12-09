#include <bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int>& A, int K) {

    // int f[30001] = {0};

    int subarraysDivByK(vector<int>& A, int K) {
    
        unordered_map<int,int>f;

        int curr_sum = 0, cnt = 0;
        f[curr_sum%K] = 1;

        for (int i = 0; i < A.size(); i++)
        {
            curr_sum = ((curr_sum + A[i])%K + K) % K;
            int freq = f[curr_sum];
            if(freq > 0){
                cnt += freq;
            }
            f[curr_sum]++;
        }

        return cnt;   
    }

}