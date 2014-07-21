class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> vec,anavec;
        map<string,vector<string>> mp;
        for(string s:strs){                    //sort every string and store groups of strings that are anagrams in a map
            string tmp=s;
            sort(tmp.begin(),tmp.end());
            mp[tmp].push_back(s);
        }
        for(auto map:mp){                      // find all anagrams
            if(map.second.size()>1)
            vec.insert(vec.end(),map.second.begin(),map.second.end());
        }
        return vec;
    }
};