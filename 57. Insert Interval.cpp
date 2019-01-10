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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int i=0,j=intervals.size(),flagStart=0;
        int flag=0; // 0 1 2
        vector<Interval> ret;
        if(j==0){
            ret.push_back(newInterval);
            return ret;
        }
        for(;i<j;++i){
            if(flag==1){
                // ---+++--?????    current intervals
                // ----++++?????    newInterval
                if(intervals[i].end<newInterval.end){
                    // ---+++----+++-??    current intervals
                    // ----++++++++++??    newInterval
                    // do nothing
                }else if(intervals[i].start<=newInterval.end){
                    // ---+++----+++---    current intervals
                    // ----++++++++----    newInterval
                    // merge intervals at flagStart and current
                    Interval temp=Interval(intervals[flagStart].start, intervals[i].end);
                    ret.push_back(temp);
                    // we are done, just add everything behind to return
                    flag=2;
                }else if(intervals[i].start>newInterval.end){
                    // ---+++----+++---    current intervals
                    // ----++++--------    newInterval
                    // merge intervals at flagStart
                    Interval temp=Interval(intervals[flagStart].start, newInterval.end);
                    ret.push_back(temp);
                    // since intervals[i] do nothing with merge, add it
                    ret.push_back(intervals[i]);
                    // we are done, just add everything behind to return
                    flag=2;
                }
            }else if(flag==3){
                // ---+++--?????    current intervals
                // --++++++?????    newInterval
                if(intervals[i].end<newInterval.end){
                    // ---+++----+++-??    current intervals
                    // --++++++++++++??    newInterval
                    // do nothing
                }else if(intervals[i].start<=newInterval.end){
                    // ---+++----+++-??    current intervals
                    // --++++++++++--??    newInterval
                    // merge intervals at flagStart and current
                    Interval temp=Interval(newInterval.start, intervals[i].end);
                    ret.push_back(temp);
                    // we are done, just add everything behind to return
                    flag=2;
                }else if(intervals[i].start>newInterval.end){
                    // ---+++----+++---    current intervals
                    // --++++++--------    newInterval
                    // merge intervals at flagStart
                    Interval temp=Interval(newInterval.start, newInterval.end);
                    ret.push_back(temp);
                    // since intervals[i] do nothing with merge, add it
                    ret.push_back(intervals[i]);
                    // we are done, just add everything behind to return
                    flag=2;
                }
            }else if(flag==0){
                if(intervals[i].start>newInterval.end){
                    // no overlap
                    // newInterval ahead of current intervals
                    
                    // if flag==0 and newInterval ahead of current intervals
                    // then we can determine that no overlap in the whole intervals
                    ret.push_back(newInterval);
                    flag=2;
                    
                    ret.push_back(intervals[i]);
                }else if(intervals[i].end<newInterval.start){
                    // no overlap
                    // newInterval behind of current intervals
                    ret.push_back(intervals[i]);
                }else if(intervals[i].start<=newInterval.start&&intervals[i].end>=newInterval.end){
                    // full overlap
                    // newInterval in current intervals
                    ret.push_back(intervals[i]);
                    // since we are done
                    flag=2;
                }else if(intervals[i].start>newInterval.start&&intervals[i].end<newInterval.end){
                    // full overlap
                    // current intervals in newInterval
                    
                    // intervals after newInterval might be in this overlap
                    flag=3;
                }else if(intervals[i].start>newInterval.start&&intervals[i].end>=newInterval.end){
                    // part overlap
                    // ---+++---    current intervals
                    // --+++----    newInterval
                    Interval temp=Interval(newInterval.start, intervals[i].end);
                    ret.push_back(temp);
                    // since flag=0 means it is the first time we meet overlap
                    // we could set flag to 2
                    flag=2;
                }else{
                    // part overlap
                    // ---+++---    current intervals
                    // ----++++-    newInterval
                    
                    // intervals after newInterval might be in this overlap
                    flag=1;
                    flagStart=i;
                }
            }else if(flag==2){
                // we are done, just add everything behind to ret
                ret.push_back(intervals[i]);
            }
        }
        if(flag==1){
            // here to finish if last condition is do nothing at Line 27
            // ---+++----+++---    last intervals
            // ----++++++++++--    newInterval
            Interval temp=Interval(intervals[flagStart].start, newInterval.end);
            ret.push_back(temp);
        }else if(flag==3){
            // here to finish if last condition is do nothing at Line 53
            // ---+++----+++---    last intervals
            // --++++++++++++--    newInterval
            Interval temp=Interval(newInterval.start, newInterval.end);
            ret.push_back(temp);
        }else if(flag==0){
            // -+++-----    last intervals
            // -----+++-    newInterval
            ret.push_back(newInterval);
        }
        return ret;
    }
};

/*
Test cases I use and I debug it like 2-3 hours
[[1,3],[6,9]]
[2,5]
[[1,3],[9,15]]
[5,7]
[[1,3],[5,7]]
[9,15]
[[1,2],[3,5],[6,7],[8,10],[12,16]]
[4,8]
[]
[1,2]
[[1,5]]
[2,7]
[[1,5]]
[2,3]
[[1,5]]
[0,3]
[[1,5]]
[0,5]
[[1,5]]
[0,6]
[[1,5]]
[5,6]
[[1,5],[6,8]]
[0,9]
[[1,5],[6,8]]
[8,9]
[[1,5],[6,8]]
[0,8]
[[1,5]]
[0,6]
[[1,4],[9,12],[19,22]]
[7,13]
*/