#include <bits/stdc++.h>
using namespace std;

bool compareInterval(vector<int> i1, vector<int> i2) 
{ 
    return (i1[1] < i2[1]); 
} 


// Sort by end time
// This is Greedy as it leaves maximum time for other intervals

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int len = intervals.size();
        
        if(len <= 1)
            return 0;
        
        sort(intervals.begin(), intervals.end(), compareInterval);

        int currs = intervals[0][0], curre = intervals[0][1];
        int cnt=0;

        for (int i = 1; i < len; i++)
        {
            if(curre > intervals[i][0]){
                cnt++;
            }else{
                currs = intervals[i][0];
                curre = intervals[i][1];
            }
        }

        return cnt;
    }
};