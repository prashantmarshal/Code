#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int>s;
    int n = heights.size();
    int maxh = 0;

    for (int i = 0; i < n; i++)
    {
        if(s.empty() || heights[s.top()] < heights[i]) {  

        } else
        {
            while(!s.empty() && (heights[s.top()] >= heights[i])) {
                int e = s.top();
                s.pop();

                int ep;
                if(s.empty())
                {
                    ep = -1;
                }
                else
                {
                    ep = s.top();
                }
                
                maxh = max(maxh, heights[e]*(i-ep-1));
            }
        }
        s.push(i);        
    }

    int right_max;
    if (!s.empty())
        right_max = s.top();
    
    while(!s.empty()) {
        int e = s.top();
        s.pop();

        int ep;
        if(s.empty())
        {
            ep = -1;
        }
        else
        {
            ep = s.top();
        }

        maxh = max(maxh, heights[e]*(right_max-ep));
    }

    return maxh;
}