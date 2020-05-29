https://leetcode.com/problems/remove-k-digits/discuss/88708/Straightforward-Java-Solution-Using-Stack
class Solution {
public:
    string removeKdigits(string num, int k) {
        int l=num.size();
        if (l==k) return "0";

        stack<char> s;
        for(int i=0;i<l;i++){
            // whenever meet a digit which is less than the previous digit, discard the previous one
            while(k>0&&s.size()&&s.top()>num[i]){
                s.pop();
                --k;
            }
            s.push(num[i]);
        }

        // corner case like "1111"
        for(;k>0;--k) s.pop();

        // construct the number from the stack
        string ret;
        while(s.size()){
            ret+=s.top();
            s.pop();
        }
        reverse(ret.begin(),ret.end());

        // remove all the 0 at the head
        int i=0;
        for(;i<ret.size();i++) if(ret[i]!='0') break;
        return ret.substr(i);
    }
};