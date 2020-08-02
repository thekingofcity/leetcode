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

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int minBefore=prices[0],maxRet=0;
        for(int i=1;i<prices.size();++i){
            maxRet=max(maxRet, prices[i]-minBefore);
            minBefore=min(minBefore, prices[i]);
        }
        return maxRet;
    }
};