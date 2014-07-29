class Solution {
public:
    bool checkMap(map<char,int> &m){
        for(auto val : m ){
            int v = val.second;
            if(v>=2)
                return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char> > &board) {
        map<char,int> m;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    m[board[i][j]]+=1;
                }
            }
            if(!checkMap(m)) return false;
            else m.clear();
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[j][i]!='.'){
                    m[board[j][i]]+=1;
                }
            }
            if(!checkMap(m)) return false;
            else m.clear();
        } 
        for(int i=0;i<=6;i+=3)
            for(int j=0;j<=6;j+=3){
                for(int k=i;k<i+3;k++)
                    for(int l=j;l<j+3;l++)
                        if(board[k][l]!='.'){
                            m[board[k][l]]+=1;
                        }
                if(!checkMap(m)) return false;
                else m.clear();
        }
        return true;
    }
};