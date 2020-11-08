// https://leetcode.com/problems/minimum-area-rectangle/solution/

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        map<int, set<int>> xs,ys;

        // build ys for each x
        for(auto const &p:points){
            int x=p[0],y=p[1];
            auto it=xs.find(x);
            if(it==xs.end()){
                set<int> _={y};
                xs[x]=_;
            }
            else it->second.insert(y);
            it=ys.find(y);
            if(it==ys.end()){
                set<int> _={x};
                ys[y]=_;
            }
            else it->second.insert(x);
        }
        
        int ans=INT_MAX;
        // for each x1 in xs
        for(map<int, set<int>>::iterator itx1=xs.begin();itx1!=xs.end();++itx1){
            // if less than 2 points in this column, continue
            if(itx1->second.size()<2) continue;
            auto itx2=itx1;
            // for each x2 great than x2
            for(++itx2;itx2!=xs.end();++itx2){
                vector<int> possible_ys;
                // see if each y2 in x2 column has a match in x1 column
                for(auto ity2=itx2->second.begin();ity2!=itx2->second.end();++ity2){
                    if(itx1->second.find(*ity2)!=itx1->second.end()){
                        // if there is corresponding y1 in x1 column
                        possible_ys.push_back(*ity2);
                    }
                }
                int min_ys=INT_MAX;
                // for each possible sorted y, calc the gap
                for(int i=1;i<possible_ys.size();++i){
                    min_ys=min(min_ys, abs(possible_ys[i]-possible_ys[i-1]));
                }
                if(min_ys==INT_MAX) continue;
                // calc the rect area from abs(x2-x1)*(min gap of y)
                ans=min(ans, abs(itx2->first-itx1->first)*min_ys);
            }
        }
        return ans==INT_MAX?0:ans;
    }
};

// [[1,1],[1,3],[3,1],[3,3],[2,2]]
// [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
// [[0,1],[1,3],[3,3],[4,4],[1,4],[2,3],[1,0],[3,4]]
// [[3,2],[3,1],[4,4],[1,1],[4,3],[0,3],[0,2],[4,0]]
