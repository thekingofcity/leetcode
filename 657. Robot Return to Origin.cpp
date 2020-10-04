class Solution {
public:
    bool judgeCircle(string moves) {
        int x=0,y=0;
        for(const auto &c:moves){
            if(c=='U') ++y;
            else if(c=='D') --y;
            else if(c=='L') --x;
            else if(c=='R') ++x;
        }
        if(x||y) return false;
        return true;
    }
};