class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> ret=intervals;
        vector<Interval>::iterator it;
        //it=ret.begin();
        int erase_start=INT_MAX;
        int erase_end=-1;
        bool erase=false;
        //[], [5,7]
        //[[1,5],[6,8]], [5,6]
        if(intervals.empty()||newInterval.end<ret[0].start){
            ret.insert(ret.begin(),newInterval);
            return ret;
        }
        int i;
        for(i=0;i<ret.size();i++){
            if(newInterval.start<ret[i].start){
                if(newInterval.end<ret[i].start){
                    break;
                }
                else{
                    newInterval.start=min(ret[i].start,newInterval.start);
                    newInterval.end=max(ret[i].end,newInterval.end);
                    erase=true;
                    erase_start=min(i,erase_start);
                    erase_end=max(i,erase_end);
              }
            }else if(newInterval.start>=ret[i].start&&newInterval.start<=ret[i].end){
                newInterval.start=min(ret[i].start,newInterval.start);
                newInterval.end=max(ret[i].end,newInterval.end);
                erase=true;
                erase_start=min(i,erase_start);
                erase_end=max(i,erase_end);
            }
        }
        ret.insert(ret.begin()+i,newInterval);
        if(erase){ret.erase(ret.begin()+erase_start,ret.begin()+erase_end+1); }
        return ret;
    }
};