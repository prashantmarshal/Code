#include <bits/stdc++.h>
using namespace std;

bool _Comparator(const int &x, const int &y){
    return (to_string(x).append(to_string(y)) < to_string(y).append(to_string(x)));
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), _Comparator);
        
        string res="";
        for(int i = 0; i < nums.size(); i++)
            res=res+to_string(nums[i]);

        return res;
    }
};