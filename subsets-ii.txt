class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > ret;
            vector<int> tmp;
            ret.push_back(tmp);

        sort(S.begin(),S.end()); //sort() not S.sort()
        map<int,int> m; 
        for(int i=0;i<S.size();i++)
            m[S[i]]++;
        for(map<int,int>::iterator it=m.begin();it!=m.end();it++){ //traverse map you cannot use m[i] it's stored in tree not vector
            int pre_c=ret.size();
            for(int k=0;k<pre_c;k++){   //copy the previous set
                for(int j=1;j<=it->second;j++){ //traver value of map  //j=1 not 0
                    vector<int> tmp=ret[k];
                    int l=j;
                    while(l){             //push the m[i] key
                        tmp.push_back(it->first);
                        l--;
                    }
                    ret.push_back(tmp);
                }
            }
        }
        return ret;
    }
};