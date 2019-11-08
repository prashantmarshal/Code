#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;
        
		vector<int>profit(prices.size());

		//Profit if we buy this stock
		profit[prices.size()-1] = 0;
		int right_max = prices[prices.size()-1];
		for (int i = prices.size()-2; i >= 0; i--)
		{
			right_max = max(right_max, prices[i]);
			profit[i] = max(profit[i+1], right_max - prices[i]);
		}

		//Max profit is calculated for one transaction. Let's see if breaking into two transations helps or not
		int left_min = prices[0];
		for (int i = 1; i < prices.size()-1; ++i)
		{
			left_min = min(left_min, prices[i]);
			profit[i] = max(prices[i] - left_min + profit[i+1], profit[i]);
		}
		return *max_element(profit.begin(), profit.end());
    }
};