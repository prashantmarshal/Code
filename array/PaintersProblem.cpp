// https://www.interviewbit.com/problems/painters-partition-problem/

#include <bits/stdc++.h>
using namespace std;

#define ll long long 
bool isPossible(vector<int> &C, int A, ll mid){
    ll currsum = 0;
    int total = 0; // total painters
    for (int i = 0; i < C.size(); i++)
    {
        if(C[i] > mid) {
            return false;
        }
        
        currsum+=C[i];
        if(currsum <= mid){
            continue;
        } else {
            total++;
            if(total == A) {
                return false;
            }
            currsum = C[i];
        }
        
        if(i == C.size()-1) {
            if(currsum <= mid && total != A) {
                return true;
            } else return false;
        }
    }

    return true;    
}

int paint(int A, int B, vector<int> &C) {
    // calculate whole sum
    ll total = 0;
    for (int i = 0; i < C.size(); i++)
        total+=C[i];

    ll low = 0, high = total;
    ll best = INT_MAX;

    while (low <= high)
    {
        ll mid = (low+high)/2;
        // is it possible to do in mid cost
        if(isPossible(C, A, mid)) {
            high = mid-1;
            best = min(best, mid);
        } else {
            low = mid+1;
        }
    }

    return (best*B)%10000003;
}

int main(int argc, char const *argv[])
{
    vector<int>arr;
    arr.push_back(762);
    arr.push_back(798);
    arr.push_back(592);
    arr.push_back(899);
    arr.push_back(329);
    cout<<paint(6, 10, arr);
    return 0;
}

