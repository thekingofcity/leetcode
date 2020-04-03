class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> mymap;
        set<char>::iterator it;
	    int i = 0, j = 0, l = s.length(), Maxlength = 0;
        while (i < l && j < l) {
            it = mymap.find(s.at(j));
            if (it != mymap.end()) {
                mymap.erase(s.at(i++));
                //Maxlength_ = j - i;
            }
            else {
                mymap.insert(s.at(j++));
                Maxlength = max(Maxlength, j - i);
            }
        }
        return Maxlength;
    }
};
//Runtime: 73 ms
int lengthOfLongestSubstring(string s) {
        vector<int> map(128,0);
        int counter=0, begin=0, end=0, d=0; 
        while(end<s.size()){
            if(map[s[end++]]++>0) counter++; 
            while(counter>0) if(map[s[begin++]]-->1) counter--;
            d=max(d, end-begin); //while valid, update d
        }
        return d;
    }