#include <bits/stdc++.h>
using namespace std;

int cnt[20001];

class Solution {
public:
    int atmax(vector<int>& A, int K){
        int size = A.size(), distinct = 0, total = 0;
        int i = 0;

        for (int j = 0; j < size; j++)
        {
            cnt[A[j]]++;

            if(cnt[A[j]] == 1){
                distinct++;
            }

            while (distinct > K)    
            {
                cnt[A[i]]--;
                if(cnt[A[i]] == 0) 
                    distinct--;
                i++;
            }

            // i points to index where distinc <= K

            total += j-i+1;
        }

        return total;
        
    }

    int subarraysWithKDistinct(vector<int>& A, int K) {
        return atmax(A, K) - atmax(A, K-1);      
    }
};





int subarraysWithKDistinct(vector<int>& A, int K) {
    int size = A.size(), distinct = 0, total = 0;
    int i = 0;

    memset(cnt, 0, sizeof(int)*20001);

    for (int j = 0; j < size; j++)
    {
        cnt[A[j]]++;

        if(cnt[A[j]] == 1){
            distinct++;
        }

        if (distinct == K)
            total++;

        while (distinct > K)    
        {
            cnt[A[i]]--;
            if(cnt[A[i]] == 0) 
                distinct--;
            i++;

            if(distinct == K)
                total++;
        }
    }

    return total;
             
}








































