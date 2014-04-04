class Solution {
public:
    vector<string> digtol(char dig){
        vector<string> ret;
        int num=dig-'0';
        int start=0;
        int end=3;
        switch (num){
            case 7: end=4;break;
            case 8: start=1;end=4;break;
            case 9: start=1;end=5;break;
            default: break;
        }
        for(int i=start;i<end;i++){
            char letter=char((num-2)*3+97+i);
            //int to string: std::string
            ret.push_back(string(1,letter));
        }
        return ret;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if (digits.size()==0)
            ret.push_back("");
        if(digits.size()==1)
            ret=digtol(digits[0]);
        else if(digits.size()>1){
            vector<string> cur=digtol(digits[0]);
            vector<string> sub=letterCombinations(digits.substr(1));
            for(int i=0;i<cur.size();i++){
                for(int j=0;j<sub.size();j++)
                    ret.push_back(cur[i]+sub[j]);
            }
        }
        return ret;
    }
};