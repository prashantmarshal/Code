// https://leetcode.com/problems/minimum-cost-for-tickets/

#include <bits/stdc++.h>
using namespace std;


int d[366][366];
int util(vector<int> &days, vector<int>& costs, int index, int validity){
    if(index == days.size()){
        return 0;
    }

    if (d[index][validity] != -1)
        return d[index][validity];

    if(days[index] <= validity){
        d[index][validity] = util(days, costs, index+1, validity);
    } else {
        d[index][validity] = min(costs[0] + util(days, costs, index+1, days[index]),
        min(costs[1] + util(days, costs, 1, days[index]+6),
            costs[2] + util(days, costs, 1, days[index]+29))
        );
    }
}
int mincostTickets(vector<int>& days, vector<int>& costs) {
    for (int i = 0; i <= 366; i++)
        for (int j = 0; j <= 366; j++)
            d[i][j] = -1;
    
    return min(costs[0] + util(days, costs, 1, days[0]),
        min(costs[1] + util(days, costs, 1, days[0]+6),
            costs[2] + util(days, costs, 1, days[0]+29))
        );
}