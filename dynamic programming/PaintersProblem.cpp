// https://www.interviewbit.com/problems/painters-partition-problem/

#include <bits/stdc++.h>
using namespace std;

#define ll long long 

ll d[10007][10007];

int paint(int A, int B, vector<int> &C) {
    ll total = 0;
    vector<ll> prefix;
    
    prefix.push_back(0); // 0 walls
    for (int i = 0; i < C.size(); i++)
    {
        total+=C[i];
        prefix.push_back(total);
    }

    // painters and prefix sum index
    // ll d[A+1][C.size()+1];

    for (int i = 0; i < A+1; i++)
        d[i][0] = 0;

    for (int i = 0; i < C.size()+1; i++)
        d[1][i] = prefix[i];

    for (int i = 2; i < A+1; i++)
    {
        for (int j = 1; j < C.size()+1; j++)
        {
            d[i][j] = INT_MAX;
            for (int k = j-1; k >= 0; k--)
            {
                d[i][j] = min(d[i][j], (max(d[i-1][k], prefix[j] - prefix[k])));                

            }
        }
    }

    return (d[A][C.size()]*B%10000003);    

}

int main(int argc, char const *argv[])
{
    vector<int>arr;
    arr.push_back(1);
    arr.push_back(10);
    // arr.push_back(592);
    // arr.push_back(899);
    // arr.push_back(329);
    cout<<paint(2, 10, arr);
    return 0;
}

