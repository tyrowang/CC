class Solution {
public:
    bool isPalindrome(string s) {
        if (s=="")
            return true;
        string ts=s;
        std::locale loc;
        for (string::size_type i=0; i<s.length(); ++i)
            ts[i]=tolower(s[i],loc);
        int i=0;
        int j=ts.size()-1;
        while(i<=j){
            if(!isalnum(ts[i])){
                i++;
                continue;
            }
            if(!isalnum(ts[j])){
                j--;
                continue;
            }
            if(ts[i]==ts[j]){
                i++;
                j--;
            }else return false;
        }
        return true;
    }
};