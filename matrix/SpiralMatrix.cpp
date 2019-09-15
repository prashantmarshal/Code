// https://leetcode.com/problems/spiral-matrix/
#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int R = matrix.size();
    int C = matrix[0].size();

    int r=0, c=0;
    vector<int>v;

    while(r<R && c<C) {
        for (int i = c; i <= C-1; i++)  
        {
            v.push_back(matrix[r][i]);
        }
        r++;

        for (int i = r; i <= R-1; i++)  
        {
            v.push_back(matrix[i][C-1]);
        }
        C--;

        if (R > r){
            for (int i = C-1; i >= c; i--)
            {
                v.push_back(matrix[R-1][i]);
            }  
            R--;
        } 
        
        if(C > c)
        {
            for (int i = R-1; i >= r; i--) 
            {
                v.push_back(matrix[i][c]);
            }
            c++;
        }
    }
    return v;
}