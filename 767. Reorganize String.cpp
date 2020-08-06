// https://leetcode.com/articles/reorganized-string/
// Greedy with Heap
class Solution {
public:
    string reorganizeString(string S) {
        if(S.empty()) return S;
        vector<int> m(128, 0);
        for(auto c:S) ++m[c];
        priority_queue<pair<int, char>> pq;
        for(char x='a';x<='z';++x)
            if(m[x]>0)
                pq.push({m[x], x});
        string ret="";
        while(pq.size()>=2){
            auto most1=pq.top(); pq.pop();
            auto most2=pq.top(); pq.pop();
            ret+=most1.second; --most1.first;
            if (most1.first>0) pq.push(most1);
            ret+=most2.second; --most2.first;
            if (most2.first>0) pq.push(most2);
        }
        if(pq.size()){
            auto most=pq.top(); pq.pop();
            if(most.first>1) return "";
            else ret+=most.second;
        }
        return ret;
    }
};