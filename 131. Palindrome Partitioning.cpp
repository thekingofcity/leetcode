class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        if(s.size()==0){
            vector<string> elem;
            ret.push_back(elem);
            return ret;
        }
        for(int i=0;i<s.size();++i){
            if(checkPalindrome(s, 0, i)){
                vector<string> elem;
                elem.push_back(s.substr(0, i+1));
                partition(s, ret, elem, i+1);
            }
        }
        return ret;
    }
    
    void partition(string const &s, vector<vector<string>> &ret,
                   vector<string> &elem, int index){
        if(index==s.size()){
            ret.push_back(elem);
            return;
        }
        for(int i=index;i<s.size();++i){
            if(checkPalindrome(s, index, i)){
                elem.push_back(s.substr(index, i-index+1));
                partition(s, ret, elem, i+1);
                elem.pop_back();
            }
        }
    }
    
    bool checkPalindrome(string const &s, int start, int end){
        if(start>end) return false;
        for(int i=start,j=end;i<=j;++i,--j){
            if(s.at(i)==s.at(j)){
                continue;
            }else{
                return false;
            }
        }
        return true;
    }
};
/*
"aab"
""
"vasdfdssavf"
*/