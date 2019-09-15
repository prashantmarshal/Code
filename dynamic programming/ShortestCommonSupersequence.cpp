// https://leetcode.com/problems/shortest-common-supersequence/

#include <bits/stdc++.h>
using namespace std;

int d[1001][1001];

string shortestCommonSupersequence(string text1, string text2) {

    int n1 = text1.size(), n2 = text2.size();        

    // we make d[n1+1][n2+1] to consider lengths as indexes
    for (int i = 0; i <= n1; i++)
        d[i][0] = i;

    for (int i = 0; i <= n2; i++)
        d[0][i] = i;

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if(text1[i-1] == text2[j-1]){
                d[i][j] = d[i-1][j-1] + 1;
            } else {
                d[i][j] = 1+min(d[i-1][j], d[i][j-1]);
            }
        }
    }

    int len = d[n1][n2];

    int i=n1, j=n2;
    string str(len, '\0');

    while (i>=1 && j>=1)
    {
        if(d[i][j] == d[i-1][j] + 1){
            str[len-1] = text1[i-1];
            i--;
        }else if(d[i][j] == d[i][j-1] + 1) {
            str[len-1] = text2[j-1];
            j--;
        }else if(d[i][j] == d[i-1][j-1] + 1){
            str[len-1] = text1[i-1];
            i--;j--;
        } 
        len--;
    }

    while (i>=1)        
    {
        str[len-1] = text1[i-1];
        len--;
        i--;
    }

    while (j>=1)        
    {
        str[len-1] = text2[j-1];
        len--;
        j--;
    }

    return str;        
}
