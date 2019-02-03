class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        int power=pow(2, n),i=0;
        for(;i<power;++i) ret.push_back((i>>1)^i);
        return ret;
    }
};