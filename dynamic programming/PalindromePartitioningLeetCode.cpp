
#include <bits/stdc++.h>
using namespace std;

bool P[1001][1001];

int partition(string str) {

    int n = str.length(); 
    
    memset(P, 0, 1001*1001) ;
    
    int i, j, k, L; 
    
    
    for (i = 0; i < n; i++) { 
        P[i][i] = true; 
    } 
    
    /* L is substring length. Build the solution in bottom up manner by 
       considering all substrings of length starting from 2 to n. */
    for (L = 2; L <= n; L++) { 
        
        for (i = 0; i < n - L + 1; i++) { 
            j = i + L - 1; 
            
            
            
            if (L == 2) 
                P[i][j] = (str[i] == str[j]); 
            else
                P[i][j] = (str[i] == str[j]) && P[i + 1][j - 1]; 
        } 
    }

    int C[1001];
    memset(C, INT_MAX, 1001);

    for (int i = 0; i < n; i++)
    {
        if(P[0, i]){
            C[i] = 0;
        } else {
            int tmp_min = INT_MAX;
            for (int j = i-1; j >= 0; j--)
            {
                tmp_min = min(P[0][j], P[j+1][i]);
            }
            C[i] = tmp_min;
        }
    }

    return C[n-1];   
    
}