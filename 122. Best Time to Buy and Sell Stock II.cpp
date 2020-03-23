// https://leetcode.com/articles/best-time-to-buy-and-sell-stock-ii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        int ret=0, l=prices.size();
        for(int i=1;i<l;i++){
            if(prices[i]>prices[i-1])
                ret += prices[i]-prices[i-1];
        }
        return ret;
    }
};