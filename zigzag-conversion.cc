class Solution {
public:
    string convert(string s, int nRows) {
        //case"AB" 1
        if(s.size()<=nRows||nRows==1) return s;
        string ret;
        int span=(nRows-1)*2;
        for(int i=0;i<nRows;i++){
            int span1=(nRows-i-1)*2;
            int span2=span-span1;
            int j=i;
            ret.push_back(s[j]);
            while(j<s.size()){
                if(j+span1!=j){
                    if(j+span1<s.size())
                        {j+=span1;ret.push_back(s[j]);}
                    else break;
                }
                if(j+span2!=j){
                    if(j+span2<s.size())
                        {j+=span2;ret.push_back(s[j]);}
                    else break;
                }
            }
        }
        return ret;
    }
};