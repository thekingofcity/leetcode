class Solution {
private:
    unordered_map<char, int> hash;
    unordered_map<char, int>::const_iterator it;
public:
    string minWindow(string s, string t) {
        int i=0,lt=t.size(),ls=s.size();
        if(lt==0||ls==0) return "";
        char ch=0;
        for(;i<lt;++i){
            ch=t.at(i);
            it=hash.find(ch);
            if(it==hash.end()){
                hash.insert({ch,1});
            }else{
                ++hash[ch];
            }
        }
        int left=0,right=0,min=-1,leftMin=0;
        while(right<ls){
            // cout<<left<<" "<<right<<" "<<needMore();
            ch=s.at(right);
            it=hash.find(ch);
            if(it!=hash.end()) --hash[ch];
            ++right;
            while(!needMore()){
                if(min<0||right-left<min){
                    min=right-left;
                    leftMin=left;
                }
                // cout<<" -> "<<leftMin<<" "<<min;
                ch=s.at(left);
                it=hash.find(ch);
                if(it!=hash.end()) ++hash[ch];
                ++left;
            }
            // cout<<endl;
        }
        if(min<0) return "";
        string ret=s.substr(leftMin, min);
        return ret;
    }
    
    bool needMore(){
        for(it=hash.begin();it!=hash.end();++it){
            if(it->second>0) return true;
        }
        return false;
    }
};
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128, 0);
        for(int i=0;i<t.size();i++)
            map[t.at(i)]++;
        
        int left=0,right=0,counter=t.size(),min=INT_MAX,start=-1;
        while(right<s.size()){
            if(map[s[right++]]-->0) counter--;
            while(counter==0){
                if(min>right-left){
                    min=right-left;
                    start=left;
                }
                if(map[s[left++]]++==0) counter++;
            }
        }
        
        return start==-1?"":s.substr(start, min);
    }
};