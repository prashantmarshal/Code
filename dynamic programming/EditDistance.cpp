// https://leetcode.com/problems/edit-distance/

#include <bits/stdc++.h>
using namespace std;

int d[10001][10001];

int minDistance(string word1, string word2) {
    int x=word1.size(), y=word2.size();

    // d[i][j] represents lengths of word1 and word2
    for (int i = 0; i <= x; i++)
        d[i][0] = i;

    for (int i = 0; i <= y; i++)
        d[0][i] = i;

    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            if(word1[i-1] == word2[j-1])
                d[i][j] = d[i-1][j-1];
            else {
                d[i][j] = 1+min(d[i-1][j], min(d[i][j-1], d[i-1][j-1]));
                            // words at length i and j
                            // replace i and j index made same => 1 +(i-1,j-1)
                            // delete i is deleted and j is same => 1 + (i-1, j)
                            // add one more character is added => 1 + (i, j-1) 
                            // (more i characters to process of first and j-1 of second)
            }
        }
    }

    return d[x][y];    
    
}