#include <bits/stdc++.h>
using namespace std;


// Can be done in two logics
// 1. Sort by start times
// 2. If interval next start time  less than interval current end time, then this means they are conflicting
// 3. Keep the one which has lesser finish time so that more space for future intervals

// Same logic if sorted by finish time

bool compareInterval(vector<int> i1, vector<int> i2) 
{ 
    return (i1[0] < i2[0]); 
} 

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
            if(intervals[i][0] < curre){
                cnt++;
                if(curre < intervals[i][1]) {
                    continue;
                }
            }
            currs = intervals[i][0];
            curre = intervals[i][1];
        }

        return cnt;
    }
};