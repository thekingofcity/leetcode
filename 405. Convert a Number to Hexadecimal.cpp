class Solution {
public:
    string toHex(int num) {
        string ret="";
        vector<char> map{'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        
        long n=num;
        if(n>0){
        }else if(n==0)
            return "0";
        else{
            n=n+INT_MAX+INT_MAX+2;
            // n=pow(2,32)+num;
        }
        
        while(n){
            int bit = n % 16;
            ret.push_back(map[bit]);
            n = n/16;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

class Solution {
public:
    string toHex(int num) {
        if(num==0) return "0";
        string ret="";
        vector<char> map{'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        
        int count=0;
        while(num&&count++<8){
            ret.push_back(map[num&15]);
            num=(num>>4);
        }
        
        reverse(ret.begin(), ret.end());
        return ret;
    }
};