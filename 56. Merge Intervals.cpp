/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int i=1,j=intervals.size();
        if(!j) return intervals;
        sort(intervals.begin(), intervals.end(), myCompare);
        vector<Interval> ret;
        Interval current=intervals[0];
        for(;i<j;++i){
            if(current.end>=intervals[i].start){
                // [[1,4],[2,3]] -> [[1,3]]
                // current.end=intervals[i].end
                current.end=max(intervals[i].end, current.end);
            }else{
                ret.push_back(current);
                current=intervals[i];
            }
        }
        ret.push_back(current);
        return ret;
    }
    
    static bool myCompare(const Interval &a, const Interval &b){
        // compare method should follow Strict Weak Ordering
        // https://www.cnblogs.com/walkerlala/p/5561339.html
        return a.start<b.start;
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        if(intervals.empty()) return res;
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();++i){
            if(intervals[i][0]<=res.back()[1])
                res.back()[1]=max(res.back()[1], intervals[i][1]);
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};