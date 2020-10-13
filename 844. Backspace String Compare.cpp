class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i=S.size()-1,j=T.size()-1;
        int sc=0,tc=0;
        while(true){
            while(i>=0&&(sc!=0||S.at(i)=='#')){
                if(S.at(i)=='#') ++sc;
                else --sc;
                --i;
                if(i<0) break;
            }
            while(j>=0&&(tc!=0||T.at(j)=='#')){
                if(T.at(j)=='#') ++tc;
                else --tc;
                --j;
                if(j<0) break;
            }
            if(i<0&&j<0) return true;
            else if(i<0&&j>=0) return false;
            else if(j<0&&i>=0) return false;
            else {
                if(S.at(i--)!=T.at(j--)) return false;
            }
        }
    }
};