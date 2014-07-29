class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0")
            return "0";
        vector<int> ret(num1.size()+num2.size(),0);
        string ret_s;
        for(int i=0;i<num1.size();i++)
            for(int j=0;j<num2.size();j++){
                int tmp=(num1[i]-'0')*(num2[j]-'0');
                if(tmp<10) ret[i+j+1]+=tmp;
                else{
                    ret[i+j+1]+=tmp%10;
                    ret[i+j]+=tmp/10;
                }
            }
        for(int i=num1.size()+num2.size()-1;i>0;i--){
            if(ret[i]>=10){
                ret[i-1]+=ret[i]/10;
                ret[i]%=10;
            }
            ret_s=to_string(ret[i])+ret_s;
        }
        if(ret[0]!=0) ret_s=to_string(ret[0])+ret_s;
        return ret_s;
    }
};