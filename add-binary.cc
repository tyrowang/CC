class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        int i=a.length()-1;
        int j=b.length()-1;
        int k=0;
        while(i>=0&&j>=0){
            int t=a[i]-'0'+b[j]-'0'+k;
            if(t>1){
                ret=to_string(t-2)+ret;
                k=1;
            }
            else{
                ret=to_string(t)+ret;
                k=0;
            }
            i--;
            j--;
        }
        if(i==j&&k==1){
            ret="1"+ret;
        }else if(i>j&&k==0){
            ret=a.substr(0,i+1)+ret;
        }else if(i<j&&k==0){
             ret=b.substr(0,j+1)+ret;
        }else if(i>j&&k==1){
            ret=addBinary(a.substr(0,i+1),"1")+ret;
        }else if(i<j&&k==1){
            ret=addBinary(b.substr(0,j+1),"1")+ret;
        }
     return ret;   
    }
};