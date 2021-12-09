class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int i = 0, j = 0;

        while(i < firstList.size() && j < secondList.size()) {
            if (firstList[i][0] <= secondList[j][1] && firstList[i][1] >= secondList[j][0]) {
                res.push_back(
                    {max(firstList[i][0], secondList[j][0]),
                    min(firstList[i][1], secondList[j][1])}
                );
            }

            // Whichever interval ends first should be discarded
            if(firstList[i][1] < secondList[j][1]) i++;
            else j++;
        }
        
        return res;
    }
};