#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int maxArea = 0;
        heights.push_back(0);
        
        for (int i = 0; i < heights.size(); i++) {
            while(!s.empty() && heights[s.top()] > heights[i]) {
                int h = heights[s.top()];
                s.pop();
                maxArea = max(maxArea, h * (i-1 - (s.empty()?-1:s.top())));
            }
            s.push(i);
        }

        return maxArea;
    }

};