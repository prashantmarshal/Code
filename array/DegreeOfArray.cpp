class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
        int l=0;
        map<int, int> shortest;

        int degree = 0;
        for (int i=0; i<nums.size(); i++) {
            shortest[nums[i]]++;
            degree = max(degree, shortest[nums[i]]);
        }

        int shortestArray = 0;
        shortest.reset();
        for (int i=0; i<nums.size(); i++) {
            shortest[nums[i]]++;
            if(shortest[nums[i]] == degree) {
                shortestArray = min(shortestArray, i-l+1);
                while(l<=i) { // try to minimize it; increment l
                    shortest[nums[l]]--;
                    if(shortest[nums[i]] < degree) {
                        break;
                    }
                }
            }
        }

        return shortestArray;
    }
};