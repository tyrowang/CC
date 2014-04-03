class Solution {
public
     void one(vectorint &candidates, vectorint& tmp, vectorvectorint  &ret, int tail,int target){
         for(int i=tail;i=0;i--){
            if(target-candidates[i]==0){
                vectorint tmp2(tmp);
                tmp2.insert(tmp2.begin(),candidates[i]);  
                ret.push_back(tmp2);
            }
            if(target-candidates[i]0){
                vectorint tmp2(tmp);
                tmp2.insert(tmp2.begin(),candidates[i]);
                one(candidates,tmp2,ret,i,target-candidates[i]);
                
            }
         }
    }
    vectorvectorint  combinationSum(vectorint &candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vectorvectorint  ret;
        vectorint tmp;
        one(candidates, tmp, ret,candidates.size()-1,target);
        return ret;
    }
};