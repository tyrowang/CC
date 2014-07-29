bool compare (const Interval &i,const Interval &j) { return (i.start<j.start); } // it must be outside of the object
class Solution {
    public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ret=intervals;
        sort(ret.begin(),ret.end(),compare);
        for(int i=ret.size()-2;i>=0;i--){
            if(ret[i].end>=ret[i+1].start){
                ret[i].end=max(ret[i+1].end,ret[i].end);
                ret[i].start=min(ret[i+1].start,ret[i].start);//[[1,10],[4,5],[6,7],[8,9]]
                ret.erase (ret.begin()+i+1);
                if(i<ret.size()-1){ i+=1;}
            }
        }
        return ret;
    }
};