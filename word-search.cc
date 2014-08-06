class Solution {
public:
        bool helper(int i,int j,vector<vector<bool> >&visit,vector<vector<char> > &board,string s){
        if(s.size()==0) return true;
        if(i<0||j<0||i>=board.size()||j>=board[0].size())
            return false;
        if(board[i][j]==s[0]&&visit[i][j]==false){
            visit[i][j]=true;
            if(helper(i-1,j,visit,board,s.substr(1))) return true;
            if(helper(i+1,j,visit,board,s.substr(1))) return true;
            if(helper(i,j+1,visit,board,s.substr(1))) return true;
            if(helper(i,j-1,visit,board,s.substr(1))) return true;
            visit[i][j]=false;
            return false;
        }
        return false;
    }
    bool exist(vector<vector<char> > &board, string word) {
        vector<vector<int> >start;
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                if(board[i][j]==word[0]){
                    vector<int> t;
                    t.push_back(i);
                    t.push_back(j);
                    start.push_back(t);
                }
        vector<vector<bool> > visit;
        for(int i=0;i<board.size();i++){
            vector<bool> t(board[0].size());
            visit.push_back(t);
        }
        for(int i=0;i<start.size();i++)
            if(helper(start[i][0],start[i][1],visit,board,word)) return true;
        return false;
        
    }
};