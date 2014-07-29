class Solution {
public:
    string minWindow(string S, string T) {
        map<char,int> needFind;
        map<char,int> hasFound;
        int begin=0,end,count=0,win=INT_MAX,min_start=0;
        for(int i=0;i<T.size();i++)
            needFind[T[i]]+=1;
        for(end=0;end<S.size();end++){
            if(needFind.count(S[end])>0){
                hasFound[S[end]]+=1;
                if(hasFound[S[end]]<=needFind[S[end]])
                    count++;
            }
            if(count==T.size()){
                while(!(needFind.count(S[begin])>0) ||
                             hasFound[S[begin]] > needFind[S[begin]]) {
                         if(needFind.count(S[begin])>0
                                 && hasFound[S[begin]] > needFind[S[begin]]){
                             hasFound[S[begin]]-=1;
                         }
                         begin++;
                }
                if(end-begin+1<win){
                    min_start=begin;
                    win=end-begin+1;
                }
            }
        }
        return (win==INT_MAX?"":S.substr(min_start,win));
    }
};