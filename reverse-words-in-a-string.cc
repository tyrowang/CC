class Solution {
public:
    void reverseWords(string &s) {
        stack<string> st;
        for(int i=0;i<s.size();i++){
            while(s[i]==' '){i++;}
            if(i>=s.size())
                break;
            int left=i;
            while(s[i]!=' '){i++;}
            st.push(s.substr(left,i-left));
        }
        if(st.empty()){s="";return;}
        s=st.top();
        st.pop();
        while(!st.empty()){
            s+=" "+st.top();
            st.pop();
        }
    }
};