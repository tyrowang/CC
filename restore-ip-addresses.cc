class Solution {
public:
    bool subnet(string s){
        if(s[0]=='0'&&s.size()>1)
            return false;   //"10.00.11.11"
        int num=atoi(s.c_str());
        if(num>255)
            return false;
        else
            return true;
    }
    vector<string> vlid(string s,int n){
        vector<string> ret;
        if(n==1){
            if(s.size()>0&&s.size()<=3&&subnet(s)){
                ret.push_back(s);
                return ret;
            }
        }
        else if(n>1&&s.size()/float(n)<=3&&s.size()/float(n)>=1){
            for(int i=1;i<=3&&i<s.size();i++){
                if(subnet(s.substr(0,i))){
                    vector<string> sub=vlid(s.substr(i),n-1);
                    if(sub.size()!=0){
                        for(int j=0;j<sub.size();j++)
                            ret.push_back(s.substr(0,i)+"."+sub[j]);
                    }
                }
            }
            return ret;  //forget
        }else return ret;
    }
    vector<string> restoreIpAddresses(string s) {
        return vlid(s,4);
    }
};