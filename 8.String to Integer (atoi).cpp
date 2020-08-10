class Solution {
public:
    
    int charToInt(char c) {
        switch (c) {
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        }
    }
    int myAtoi(string str) {
        int i = 0, l = str.length();
        bool flag = 0;
        int64_t num = 0;
        if (l == 0) return 0;
        while (i < l  && str.at(i) == ' ') {
            i++;
        }
        if (l == 0 || i == l) return 0;
        if (str.at(i) == '+') {
            i++;
        }else if(str.at(i) == '-') {
            flag = 1;
            i++;
        }
        if (i == l) return 0;
        while (str.at(i) >= '0' && str.at(i) <= '9') {
            num = num * 10 + charToInt(str.at(i));
            if (!flag && num > INT_MAX) {
                return INT_MAX;
            }
            if (flag && num > INT_MAX) {
                return INT_MIN;
            }
            if (++i >= l) break;
        }
        if (flag) num = -num;
        int ans = num;
        return ans;
    }
};
//Runtime: 33 ms

class Solution {
public:
    int myAtoi(string str) {
        int i=0; long ans=0; bool minus=false;
        while(i<str.size()&&str[i]==' ')
            ++i;
        if(!(isdigit(str[i])||str[i]=='+'||str[i]=='-'))
            return 0;
        if(str[i]=='+'||str[i]=='-')
            minus=str[i++]=='-'?true:false;
        while(i<str.size()&&isdigit(str[i])){
            ans=ans*10+(str[i++]-'0');
            if(ans>INT_MAX)
                return minus?INT_MIN:INT_MAX;
        }
        if(minus) ans=-ans;
        return (int)ans;
    }
    
    bool isdigit(char c){
        if(c>='0'&&c<='9') return true;
        return false;
    }
};