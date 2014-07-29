class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<string> s;
        int tmp=0;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                int num2=atoi(s.top().c_str()); 
                s.pop();
                int num1=atoi(s.top().c_str()); 
                s.pop();
                switch(tokens[i][0]){
                    case '+': tmp=num1+num2;s.push(to_string(tmp));break;
                    case '-': tmp=num1-num2;s.push(to_string(tmp));break;
                    case '*': tmp=num1*num2;s.push(to_string(tmp));break;
                    case '/': tmp=num1/num2;s.push(to_string(tmp));break;
                }
            }else{
                s.push(tokens[i]);
            }    
        }
        int ret=atoi(s.top().c_str());
        return ret;
        
    }
};