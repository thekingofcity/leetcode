class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        int min=prices[0], l=prices.size(), ret=0;
        for(int i=1;i<l;i++){
            if(prices[i]<min) min=prices[i];
            if(prices[i]-min>ret) ret=prices[i]-min;
        }
        return ret;
    }
};