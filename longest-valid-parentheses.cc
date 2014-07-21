class Solution {
public:
    int longestValidParentheses(string s) {
        int ret=0;
        int tmp=0;
        stack<char> st1, st2;
        for(int i=0;i<s.size();i++){
            if('('==s[i]){
                st1.push(s[i]);
            }
            else if(')'==s[i]){
                if(!st1.empty()){
                    st1.pop();    //()
                    tmp+=2;      //()(()
                    if(st1.empty())
                         ret=max(ret,tmp);  //(()
                }else{
                    ret=max(ret,tmp);
                    tmp=0;
                }
            }
        }
        if(st1.empty()) ret=max(ret,tmp);
        tmp=0;
        for(int i=s.size()-1;i>=0;i--){
            if(')'==s[i]){
                st2.push(s[i]);
            }
            else if('('==s[i]){
                if(!st2.empty()){
                    st2.pop();    //()
                    tmp+=2;      //()(()
                    if(st2.empty())
                         ret=max(ret,tmp);  //(()
                }else{
                    ret=max(ret,tmp);
                    tmp=0;
                }
            }
        }
        if(st2.empty()) ret=max(ret,tmp);
        return ret;
        
    }
};
