#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

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

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(!matrix.size()) return 0;

        int Rows = matrix.size();
        int Cols = matrix[0].size();

        vector<int>histogram;
        histogram.resize(Cols);
        for(int i = 0; i < Cols; i++) histogram.push_back(0);

        int maxval = 0;
        for (int i = 0; i < Rows; i++) {
            for (int j = 0; j < Cols; j++) {
                if (matrix[i][j] == '1') histogram[j]++; else histogram[j] = 0;
            }
            maxval = max(maxval, largestHistogram(histogram));
        }
        
        return maxval;
    }
};