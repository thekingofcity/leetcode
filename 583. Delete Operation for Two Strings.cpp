class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1));
        for(int i=word1.size()-1;i>=0;--i)
            for(int j=word2.size()-1;j>=0;--j)
                if(word1.at(i)==word2.at(j))
                    dp[i][j]=1+dp[i+1][j+1];
                else
                    dp[i][j]=max(dp[i+1][j], dp[i][j+1]);
        
        return word1.size()+word2.size()-(dp[0][0]<<1);
    }
};