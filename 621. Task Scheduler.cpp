class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> m(26, 0);
        for(auto c:tasks) ++m[c-'A'];
        priority_queue<int> pq;
        for(auto i:m)
            if(i>0)
                pq.push(i);
        int alltime=0;
        while(pq.size()){
            int i=0;
            int time=0;
            vector<int> temp;
            while(i<=n){
                if(pq.empty()) break;
                if(pq.top()>1)
                    temp.push_back(pq.top()-1);
                pq.pop();
                ++time;
                // if(temp.empty()&&pq.empty()) break;
                ++i;
            }
            for(auto t:temp) pq.push(t);
            alltime += pq.size() ? n+1 : time;
        }
        return alltime;
    }
};