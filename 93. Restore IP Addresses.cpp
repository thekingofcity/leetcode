class Solution {
public:
    vector<string> ret;
    string s;
    vector<string> restoreIpAddresses(string s_) {
        s=s_;
        vector<int> dot;
        for(int i=1;i<4;++i){
            if(isValid(s.substr(0, i))){
                dot.push_back(i);
                restoreIpAddresses(2, dot);
                dot.pop_back();
            }
        }
        return ret;
    }
    
    void restoreIpAddresses(int k, vector<int> dot) {
        int size=dot.size();
        if(size==3){
            // for(auto it=dot.begin();it!=dot.end();++it) cout<<*it<<" ";
            // cout<<endl;
            if(s.size()-1-dot[2]<=3&&isValid(s.substr(dot[2]))){
                string out="";
                for(int i=0,j=0;i<s.size();++i){
                    if(dot[j]==i){
                        out.push_back('.');
                        ++j;
                    }
                    out.push_back(s.at(i));
                }
                ret.push_back(out);
            }
            return;
        }
        for(int i=1;i<4;++i){
            if(dot[size-1]+i>=s.size()) continue;
            string temp=s.substr(dot[size-1], i);
            if(isValid(temp)){
                dot.push_back(dot[size-1]+i);
                restoreIpAddresses(k-1, dot);
                dot.pop_back();
            }
        }
    }
    
    bool isValid(string s){
        int temp=atoi(s.c_str());
        if(temp>255) return false;
        if(s.size()!=to_string(temp).size()) return false;
        return true;
    }
};
/*
"1111"
"25525511135"
"19216811"
*/