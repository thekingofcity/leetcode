class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0 || s[0] == '0') return 0;
        vector<int> dp(s.size()+1, 0);
        dp[0]=1;
        dp[1]=1;
        int l=s.size();
        for(int i=1;i<l;++i){
            int tmp = (int)atoi(s.substr(i - 1, 2).c_str());
            if (tmp <= 26 && tmp >= 10)
                dp[i + 1] += dp[i - 1];
            if (tmp%10 != 0)  // s[i]!=0
                dp[i + 1] += dp[i];
        }
        return dp[l];
    }
};

class Solution {
public:
    int numDecodings(string s) {
        if(s.size()==0||s[0]=='0') return 0;
        vector<int> dp(s.size()+1, 0);
        dp[0]=1;
        dp[1]=1;
        for(int i=1;i<s.size();++i){
            if(s[i-1]=='1'||(s[i-1]=='2'&&s[i]<='6'))
                dp[i+1]+=dp[i-1];
            if(s[i]!='0')
                dp[i+1]+=dp[i];
        }
        return dp[s.size()];
    }
};

class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) return 0;
        vector<int> dp(s.size()+1, 0);
        dp[0]=1;
        for(int i=1;i<dp.size();++i){
            dp[i]=s[i-1]=='0'?0:dp[i-1];
            if(i>=2&&(s[i-2]=='1'||(s[i-2]=='2'&&s[i-1]<='6')))
                dp[i]+=dp[i-2];
        }
        return dp.back();
    }
};