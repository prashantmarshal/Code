#include <bits/stdc++.h>
using namespace std;

int d[10001][10001];

int d[10001][10001];

class Solution {
public:
    int superEggDrop(int k, int n) {

        for (int i = 0; i <= n; ++i)
            d[i][1] = i; // if eggs are 1, then chances = number of floors
		
        int c = 0;
        
        for (int e = 2; e <= k; e++){
            for (int f = 1; f <= n; ++f){
                d[f][e] = INT_MAX-1;
                for (int i = 1; i <= f; i++){
                    c = 1 + max(d[i-1][e-1], d[f-i][e]);
                    d[f][e] = min(d[f][e], c);
                }                
            }
        }
        
        return d[n][k];
    }
};


/*
For puzzle question of 100 floors and 2 eggs 
take x + x-1 + x-2 + ... + 1 = 100
*/
