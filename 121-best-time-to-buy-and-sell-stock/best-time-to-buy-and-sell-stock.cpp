class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int bestBuy = INT_MAX;
        for(int i : prices){
            if(i > bestBuy){
                profit = max(profit,i-bestBuy);

            }
            bestBuy = min(bestBuy, i);
        }   
    return profit;
    }
};