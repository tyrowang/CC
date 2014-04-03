class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i=0;
        while(i<s.size()){
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
                st.push(s[i]);
            else if(s[i]==')'&&!st.empty()&&st.top()=='(')//case "]", we have to check the st.empty befor call st.top
                st.pop();
            else if(s[i]==']'&&!st.empty()&&st.top()=='[')
                st.pop();
            else if(s[i]=='}'&&!st.empty()&&st.top()=='{')
                st.pop();
            else
                return false;
            i++;
        }
        if(st.empty()) //case "[" we have to check the stack
            return true;
        else
            return false;
    }
};