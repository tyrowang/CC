class Solution {
public:
    vector<vector<string> >helper(string s, unordered_set<string> &dict){
        vector<vector<string> > ret;
        vector<vector<string> > tmp;
        if(s=="") return ret;
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            string word=s.substr(i);
            if(dict.count(word)>0){
                tmp=helper(s.substr(0,i),dict);
                if(tmp.size()!=0){
                    for(int i=0;i<tmp.size();i++){
                        tmp[i].push_back(word);
                        ret.push_back(tmp[i]);
                    }
                    tmp.clear();
                }else if(i==0) {vector<string> t;t.push_back(word);ret.push_back(t);}
                
            }
        }
        return ret;
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        // case "a", ["a"]
        vector<string> ret;
        if(s.size()==0)
            return ret;
        vector<vector<string> > tmp;
        tmp=helper(s,dict);
        for(int i=tmp.size()-1;i>=0;i--){
            int j=0;
            string t=tmp[i][j];
            for(j=1;j<tmp[i].size();j++){
                t+=(" "+tmp[i][j]);
            }
            tmp[i].pop_back();
            ret.push_back(t);
        }
        return ret;
    }
};