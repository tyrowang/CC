class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //case bacbefc
        //wrbbqbrzow
        //qopubjguxhxdipfzwswybgfylqvjzhar
        unordered_map<char,int> m;
        int ret=0;
        int t=0;
        int start=0;
        for(int i=0;i<s.size();i++){
            if(m.count(s[i])>0){
                t=i-start;
                for(int j=start;j<m[s[i]];j++) m.erase(s[j]);
                if(t>ret) ret=t;
                start=m[s[i]]+1;
            }
            m[s[i]]=i;
        }
        t=s.size()-start;
        if(t>ret) ret=t;
        return ret;
    }
};