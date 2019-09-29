// https://leetcode.com/problems/gas-station/


#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int petrol = 0, start = 0, sum = 0;
    
    for(int i = 0; i < gas.size(); i++){
        sum = sum + (gas[i] - cost[i]);
        petrol = petrol + (gas[i] - cost[i]);
        if(petrol < 0){
            petrol = 0;
            start = i+1;
        }
    }
    
    if(sum >= 0){
        return start%(gas.size());
    }
    
    return -1;
}