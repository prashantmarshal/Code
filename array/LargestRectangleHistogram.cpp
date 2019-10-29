#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n == 0) return 0;

        stack<int>s;
        int maxh = 0;

        for (int i = 0; i < n; i++)
        {
            while(!s.empty() && (heights[s.top()] >= heights[i])) {
                int e = s.top();
                s.pop();

                int ep = s.empty()?-1:s.top();
                maxh = max(maxh, heights[e]*(i-ep-1));
            }
            s.push(i);        
        }

        int right_max;
        if (!s.empty())
            right_max = s.top();

        while(!s.empty()) {
            int e = s.top();
            s.pop();

            int ep = s.empty()?-1:s.top();

            maxh = max(maxh, heights[e]*(right_max-ep));
        }

        return maxh;
    }
};