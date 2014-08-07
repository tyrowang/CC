class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        map<int,int> m;
        int ret=0;
        for(int i=0;i<num.size();i++){
            m[num[i]]=1;
        }
        for(int i=0;i<num.size();i++){
            int left=0,right=0,cur=num[i];
            if(m[cur]==0)
                continue;
            while(m.count(--cur)>0){
                left++;
                m[cur]=0;
            }
            cur=num[i];
            while(m.count(++cur)>0){
                right++;
                m[cur]=0;
            }
            if(right+left+1>ret)
                ret=right+left+1;
        }
        return ret;
    }
};