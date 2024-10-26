#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buy = 0;
        int sell = 1;

        if(prices.size()==1)
        {
            return 0;
        }
        while(sell<prices.size()){
            
            if(prices[buy]>prices[sell]){
                buy++;
                continue;
            }else{
                profit=max(profit,prices[sell]-prices[buy]);
                sell++;
            }
        }

        return profit;
    }
};