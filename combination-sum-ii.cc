class Solution {
public:
    vector<vector<int> > helper(vector<int> &num, int end,int target) {
        // considered [1,1,1] 3
        //considered[1,1,2,2] 3
        //considered [1,1] 3
        // neglect [1,1] 2 typo
        //neglect [1,2], 3 reverse order
        vector<vector<int> > ret;
        vector<vector<int> > tret;
        if(target<=0||end<0)
            return ret;
        vector<int> tmp;
        for(int i=end;i>=0;i--){
            if(i!=end&&num[i]==num[i+1]) continue;
            if(num[i]==target){tmp.push_back(num[i]);ret.push_back(tmp);tmp.clear();}
            else if(num[i]<target){
                tret=helper(num, i-1,target-num[i]);
                if(tret.size()!=0)
                    for(int j=tret.size()-1;j>=0;j--){
                        tret[j].push_back(num[i]);
                        ret.push_back(tret[j]);
                        tret.pop_back();
                    }
            }
        }
        return ret;
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(),num.end());
        vector<vector<int> > ret;
        ret=helper(num,num.size()-1,target);
        return ret;
        
    }
};