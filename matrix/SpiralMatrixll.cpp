// https://leetcode.com/problems/spiral-matrix-ii/submissions/
 
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n);
        
        if (n <= 0) {
            return matrix;            
        }
        
        for(int i=0; i<n; ++i)
            matrix[i].resize(n);
        
        int R = n, C = n;

        int r=0, c=0;
        int cnt = 1;

        while(r<R && c<C) {
            for (int i = c; i <= C-1; i++)  
            {
                matrix[r][i] = cnt++;
            }
            r++;

            for (int i = r; i <= R-1; i++)  
            {
                matrix[i][C-1] = cnt++;
            }
            C--;

            if (R > r){
                for (int i = C-1; i >= c; i--)
                {
                    matrix[R-1][i] = cnt++;
                }  
                R--;
            } 

            if(C > c)
            {
                for (int i = R-1; i >= r; i--) 
                {
                    matrix[i][c] = cnt++;
                }
                c++;
            }
        }
        return matrix;
    }