class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i=0,l=s.size(),t=l/2;i<t;i++)
            swap(s[i],s[l-i-1]);
    }
};