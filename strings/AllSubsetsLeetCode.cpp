// https://leetcode.com/problems/subsets/

#include <bits/stdc++.h>
using namespace std;

// We take an extra array data[] of size same as input array
// We create prefixes and recur starting from each index upto the last index
// 0, 0..1, 0..2, 0..3, ..
// 1, 1..2, 1..3, ..

void util(int arr[], int data[], int start, int startdata, int end){

    cout<<"[";
    for (int i = 0; i < startdata; i++)
        cout<<data[i];  cout<<"]\n"; 

    if(startdata > end)
        return;
        
    for (int i = start; i <= end; i++)
    {
        data[startdata] = arr[i];
        util(arr, data, i+1, startdata+1, end);
        
        while(i < end && arr[i+1] == arr[i])
			i++;
    }
}

void subsets(int arr[], int n){
    int data[n];
    util(arr, data, 0, 0, n-1);
}

int main(){
    int arr[] = {12, 13};
    subsets(arr, sizeof(arr)/sizeof(arr[0]));
}