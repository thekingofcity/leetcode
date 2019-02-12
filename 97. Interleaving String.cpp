class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        return isInterleave(s1, s2, s3, 0, 0, 0);
    }
    
    bool isInterleave(string &s1, string &s2, string &s3, int i1, int i2, int i3) {
        if(i1==s1.size()&&i2==s2.size()&&i3==s3.size()) return true;
        if(i1<s1.size()&&i3<s3.size()&&s3.at(i3)==s1.at(i1)){
            if(isInterleave(s1, s2, s3, i1+1, i2, i3+1))
                return true;
        }
        if(i2<s2.size()&&i3<s3.size()&&s3.at(i3)==s2.at(i2)){
            if(isInterleave(s1, s2, s3, i1, i2+1, i3+1))
                return true;
        }
        return false;
    }
};