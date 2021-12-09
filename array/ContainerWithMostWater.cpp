// https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int i = 0, j = height.size() - 1;

        while (i < j) { // calculate till we are calculating between two adjacent lines
            water = max(water, min(height[i], height[j]) * (j-i));
            if (height[i] > height[j]) j--;
            else i++;
        }
        return water;
    }
};