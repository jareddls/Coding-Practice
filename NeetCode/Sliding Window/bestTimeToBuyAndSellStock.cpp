class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //left and right pointers, respectively
        //lets us look at where to buy and where to sell
        //sell starts 1 more than buy because wouldn't make
        //sense to really sell at the same point that you buy
        int buy = 0;
        int sell = 1;

        int max_profit = 0;
        while (sell < prices.size()) {
            
            //if the price at when we buy is less than the price at 
            //where we could sell
            //check the profit you can make and compare it to the max_profit
            //save whichever is higher

            
            if (prices[buy] < prices[sell]) {
                int profit = prices[sell] - prices[buy];
                max_profit = max(max_profit, profit);
            }
            //not always the case, if we end up finding an even lower value
            //we'll move the buy to where sell was and check the profits even further
            //we don't have to worry about a case where we move buy and it doesn't find
            //a higher profit, because it will still choose from the max_profit
            else {
                buy = sell;
            }
            //the way to eventually close the while loop
            sell += 1;
        }

        return max_profit;
    }
};