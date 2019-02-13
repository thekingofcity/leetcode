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
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int i3=0,l3=s3.size(),i1=0,i2=0,l1=s1.size(),l2=s2.size();
        if(l1+l2!=l3) return false;
        vector<vector<bool>> res(l1+1, vector<bool>(l2+1, false));
        
        res[0][0]=true;
        // for the first row
        for(i2=1;i2<=l2;++i2){
            res[0][i2]=res[0][i2-1]&&s3.at(i2-1)==s2.at(i2-1);
        }
        
        for(i1=1;i1<=l1;++i1){
            // for the first column
            res[i1][0]=res[i1-1][0]&&s3.at(i1-1)==s1.at(i1-1);
            
            // main dp
            for(i2=1;i2<=l2;++i2){
                res[i1][i2]=res[i1-1][i2]&&s1[i1-1]==s3[i1+i2-1]||
                            res[i1][i2-1]&&s2[i2-1]==s3[i1+i2-1];
            }
        }
        return res[l1][l2];
    }
};