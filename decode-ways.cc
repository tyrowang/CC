//recursive low efficient
class Solution {
public:
    int numDecodings(string s) {
        if(s.size()<=1)
            return 1;
        int ret=0;
        int t=atoi(s.substr(0,1).c_str());
        if(t>26)
            ret=numDecodings(s.substr(1));
        else if(t<=26&&s.substr(1,1)!="0")
            ret=numDecodings(s.substr(1))+numDecodings(s.substr(2));
        else if(s.substr(1,1)=="0"){
            ret=numDecodings(s.substr(2));
        }
    }
};


class Solution {
public:
    int numDecodings(string s) {
        if(s=="")
            return 0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='0'){
                if(i==0||(s[i-1]!='1'&&s[i-1]!='2'))
                    return 0;
            }
        }
            //case: "" 
            //case: 100
            //case:01
            //case:110
        vector<int> dp(s.size()+1,0);
        dp[s.size()]=1;  //the base case is important which is the last digit and last two digits
        if(s[s.size()-1]!='0')
            dp[s.size()-1]=1;
        
        for(int i=s.size()-2;i>=0;i--){
            string str=s.substr(i,2);
            int t=atoi(s.substr(i,2).c_str());
            if(t>26)
                dp[i]=dp[i+1];
            else if( t<=26 && s[i+1]!='0')
                dp[i]=dp[i+1]+dp[i+2];
            else if(s[i+1]=='0')
                dp[i]=dp[i+2];
        }
        return dp[0];
    }
};