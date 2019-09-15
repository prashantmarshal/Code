// https://www.hackerrank.com/challenges/linkedin-practice-dynamic-programming-lcs/problem
// https://www.geeksforgeeks.org/printing-longest-common-subsequence-set-2-printing/

#include <bits/stdc++.h>
using namespace std;

int d[1001][1001];
vector<int> v;

int printAllSubsequences(vector<int> &A, vector<int> &B, int n1, int n2) {
    // first find LCS
    
    // we make d[n1+1][n2+1] to consider lengths as indexes
    
    for (int i = 0; i <= n1; i++)
        d[i][0] = 0;

    for (int i = 0; i <= n2; i++)
        d[0][i] = 0;

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if(A[i-1] == B[j-1]){
                d[i][j] = d[i-1][j-1] + 1;
            } else {
                d[i][j] = max(d[i-1][j], d[i][j-1]);
            }
        }
    }

    int i = n1, j = n2;

    /* for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            cout<<d[i][j]<<" ";
        }
        
        cout<<endl;
    } */
    
    
    while(i > 0 && j > 0) {
        if(A[i-1] == B[j-1]){
            v.push_back(A[i-1]);
            i--;j--;
        } else if (d[i-1][j] > d[i][j-1]) {
            i--;
        } else{
            j--;
        }
    }

    return d[n1][n2];
}

// 5 6
// 1 2 3 4 1
// 3 4 1 2 1 3
int main(int argc, char const *argv[])
{
    int n, m;
    cin>>n>>m;
    vector<int>A, B;
    A.resize(1000);
    B.resize(1000);  

    for (int i = 0; i < n; i++)
        cin>>A[i];
    for (int i = 0; i < m; i++)
        cin>>B[i];
    
    int size = printAllSubsequences(A, B, n, m);
    
    for (int i = size-1; i >= 0; i--)
    {
        cout<<v[i]<<" ";
    }
    
    return 0;
}

