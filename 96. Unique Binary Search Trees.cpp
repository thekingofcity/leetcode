class Solution {
public:
    int numTrees(int n) {
        vector<int> g(n+1,0);
        g[0]=1;
        g[1]=1;

        // G(n)：长度为n的序列的唯一BST数。
        // F(i, n), 1 <= i <= n：唯一BST的数量，其中数字i是BST的根，序列范围从1到n
        // G(n) = F(1, n) + F(2, n) + ... + F(n, n).
        // F(i, n) = G(i-1) * G(n-i)	1 <= i <= n

        //综上 G(n)= G(0) * G(n-1) + G(1) * G(n-2) + … + G(n-1) * G(0)

        for(int i=2;i<=n;++i)
            for(int j=0;j<i;++j)
                g[i]+=g[j]*g[i-j-1];

        return g[n];  
    }
};
class Solution {
public:
    int numTrees(int n) {
        if(n<=1) return 1;
        int sum=0,i=1;
        for(;i<=n;++i)
            sum+=numTrees(i-1)*numTrees(n-i);
        return sum;
    }
};