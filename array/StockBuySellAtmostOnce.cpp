class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, maxRight = 0, size = prices.size();
        
        for(int i = size-1; i >= 0; --i) {
            profit = profit > maxRight-prices[i] ? profit : maxRight-prices[i];
            maxRight = maxRight > prices[i] ? maxRight : prices[i];
        }
        
        return profit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0], sell = 0;
        
        for(int i = 1; i < prices.size(); i++) {
            buy = min(buy, prices[i]);
            sell = max(sell, prices[i]-buy);
        }
        
        return sell;
    }
};