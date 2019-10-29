#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

int largestHistogram(int *heights, int n) {
    
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

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows, columns;
        rows = matrix.size();
        if(rows==0) return 0;
        columns = matrix[0].size();

        int **grid = new int*[rows];
        for (int i = 0; i < rows; i++)
        {
            grid[i] = new int[columns];
        }
        
        for (int i = 0; i < columns; i++)
        {
            int cnt = 0;
            for (int j = 0; j < rows; j++)
            {
                if(matrix[j][i] == '1') cnt++;
                else cnt = 0;

                grid[j][i] = cnt;
            }
        }

        int maxval = 0;
        for(int i = 0; i < rows; ++i){
            maxval = max(maxval, largestHistogram(grid[i], columns));
        }
        
        return maxval;
    }
};