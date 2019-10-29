// https://leetcode.com/problems/task-scheduler/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;

        // For each character
        int task[26];
        memset(task, 0, sizeof(task));

        int size = tasks.size();
        for (int i = 0; i < size; i++)
        {
            task[tasks[i]-'A']++;
        }

        sort(task, task+26, greater<int>());

        for (int i = 0; i < 26; i++)
        {
            if(task[i] == 0) // no more tasks
                break;
            pq.push(task[i]);
        }
        
        int time = 0;
        int curr_operations, top;

        while(true){
    
            vector<int> tmp;
            curr_operations = 0;

            // Going for cooling period + 1 iterations
            for (int i = 0; i < n+1; i++)
            {
                if(pq.empty()) break;
                
                curr_operations++;
                top = pq.top();
                pq.pop();
                
                // Push remaining instances of current task
                if(top > 1) tmp.push_back(top-1);
            }
            
            // If no tasks remaining in pq and none added to tmp to executed in next cycle
            if(tmp.empty() && pq.empty()){
                time += curr_operations;
                break;
            }
            
            time += n+1;

            for (int i = 0; i < tmp.size(); i++){
                pq.push(tmp[i]);
            }
        }

        return time;
    }
};