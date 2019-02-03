// https://www.cnblogs.com/grandyang/p/4358678.html
// https://blog.csdn.net/jeasn168/article/details/39047685
class Solution {
public:
    string getPermutation(int n, int k) {
        --k;
        string ret(n, ' ');
        string res="0123456789";
        vector f(10, 1);
        int i=0,fac=0,x=0;
        for(i=2;i<=9;++i) f[i]=f[i-1]*i;
        i=n-1;
        for(;i>=1;--i){
            fac=f[i];
            x=k/fac;
            k=k%fac;
            ret[n-i-1]=res[x+1];
            res.erase(x+1, 1);
        }
        ret[n-1]=res[1];ret[n]='\0';
        return ret;
    }
};