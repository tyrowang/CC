class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string ret="";
        if(strs.size()==0)
            return ret;
        if(strs.size()==1)
            return strs[0];
        for(int j=0;j<strs[0].size();j++){
            for(int i=1;i<strs.size();i++){
                if(strs[0][j]==NULL || strs[i][j]==NULL || strs[i][j]!=strs[0][j])
                    return ret;
            }
            ret.append(1,strs[0][j]);
        }
        return ret;
    }
};