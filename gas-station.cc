class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int index=0;
        int total=0;
        int max=0;
        for(int i=0;i<gas.size();i++){
            gas[i]-=cost[i];
            total+=gas[i];
            if(max+gas[i]<0)
                index=i+1;
            else max+=gas[i];
        }
        if(total<0)
            return -1;
        else return index;
    }
};