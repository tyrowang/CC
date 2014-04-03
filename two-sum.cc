class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ret;
        map<int,int> m;
        for(int i=0;i<numbers.size();i++){
            if(target%2==0&&numbers[i]==target/2)
                ret.push_back(i+1);
            if(ret.size()==2)
                return ret;
        }
        ret.clear();
        for(int i=0;i<numbers.size();i++)
            m[numbers[i]]=i+1;
        map<int,int>::const_iterator it=m.begin();
        map<int,int>::iterator it2;
        
        while(it!=m.end()){
            it2=m.find(target-it->first);
            if(it2!=m.end()){
                ret.push_back(min(it2->second,it->second));
                ret.push_back(max(it2->second,it->second));
                break;
            }
            it++;
        }
        return ret;
        
    }
};