// https://leetcode.com/problems/stone-game/discuss/261718/Step-by-Step-Recursive-TopDown-BottomUp-and-BottomUp-using-O(n)-space-in-Java
// https://leetcode.com/problems/stone-game/discuss/154660/Java-This-is-minimax-%2B-dp-(fully-detailed-explanation-%2B-generalization-%2B-easy-understand-code)
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        auto len=piles.size(); bool turn=false;
        vector<vector<int>> dp(len, vector<int>(len, 0));
        for(size_t slide=0;slide<len;++slide){
            for(size_t l=0;l<len-slide;++l){
                auto r=l+slide;
                if(l==r){
                    dp[l][r]=-piles[l];
                    continue;
                }
                
                if(turn){
                    dp[l][r]=max(dp[l+1][r]+piles[l], dp[l][r-1]+piles[r]);
                }else{
                    dp[l][r]=min(dp[l+1][r]-piles[l], dp[l][r-1]-piles[r]);
                }
            }
            turn=!turn;
        }
        return dp[0][len-1];
    }
};

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
}
