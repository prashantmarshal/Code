class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int max_profit = 0;
        vector<int> profit(size, 0);
        
        int min_yet = INT_MAX;
        profit[0] = 0;
        for (int i = 1; i < size; i++) {
            min_yet = min(prices[i], min_yet);
            profit[i] = max(profit[i-1], prices[i] - min_yet);
        }
        
        int max_yet = INT_MIN;
        for (int i = size-1; i >= 0; i--) {
            max_yet = max(max_yet, prices[i]);
            max_profit = max(max_profit, max_yet - prices[i] + profit[i]);
        }
        
        return max_profit;
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b1 = prices[0], s1 = 0, b2 = prices[0], s2 = 0;

        for (int i = 0; i < prices.size(); ++i) {
            b1 = min(b1, prices[i]);
            s1 = max(s1, prices[i]-b1);
            b2 = min(b2, prices[i]-s1);
            s2 = max(s2, prices[i]-b2);
        }
        return s2;
    }
};