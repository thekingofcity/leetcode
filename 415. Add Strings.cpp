class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1=="0") return num2;
        if(num2=="0") return num1;
        num1=lstrip(num1);
        num2=lstrip(num2);
        
        // vector<int> sum(max(num1.size(), num2.size()), 0);
        vector<int> sum;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int l=max(num1.size(), num2.size())+1,carry=0;
        for(int i=0;i<l;++i){
            int x=(i<num1.size()?(num1[i]-'0'):0)
                +(i<num2.size()?(num2[i]-'0'):0)
                +carry;
            if(x>9){
                carry=1;
                x-=10;
            }else{
                carry=0;
            }
            
            // sum[i]=x;
            sum.push_back(x);
        }
        
        string ret;
        for(auto x:sum)
            ret.push_back(x+'0');
        reverse(ret.begin(), ret.end());
        ret=lstrip(ret);
        
        return ret;
    }
    
    string lstrip(string &s){
        int i=0;
        for(;i<s.size();++i)
            if(s[i]!='0') break;
        return s.substr(i);
    }
};
