//re_cursive
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        for(int i=1;i<=s.size();i++){
            std::unordered_set<std::string>::const_iterator got = dict.find (s.substr(0,i));
            if(got!=dict.end()&&i<s.size()){
                if(wordBreak(s.substr(i), dict))
                    return true;
            }else if(got!=dict.end()&&i==s.size())
                return true;
        }
        return false;
    }
};
//dp
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (s == "")
            return true;
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for (int i = 0; i < s.length(); i++) {
            if (dp[i] == false)
                continue;
            for (int j = 1; i + j <= s.length(); j++)
                if (dict.find(s.substr(i, j)) != dict.end())
                    dp[i + j] = true;
        }
        return dp[s.length()];
    }
};