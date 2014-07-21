class Solution {
public:
    string cline(vector<string> &words,int left,int wordNum, int L){
        string line="";
        string space="";
        int charNum=0;
        for(int i=left;i<left+wordNum;i++){
            charNum+=words[i].size();
        }
        if(left+wordNum==words.size()){
            line=words[left];
            for(int i=left+1;i<left+wordNum;i++){
                line+=(" "+words[i]);
            }
            int spaceNum=L-line.size();
            while(spaceNum>0){space+=" ";spaceNum--;}
            line+=space;
            return line;
        }
        else if(wordNum==1){
            int spaceNum=L-charNum;
            while(spaceNum>0){space+=" ";spaceNum--;}
            return words[left]+space;
        }else{
            int remainder=(L-charNum)%(wordNum-1);
            int spaceNum=(L-charNum-remainder)/(wordNum-1);
            while(spaceNum>0){space+=" ";spaceNum--;}
            line=words[left];
            if(remainder==0){
                for(int i=left+1;i<left+wordNum;i++){
                    line+=(space+words[i]);
                }
            }else{
                for(int i=left+1;i<left+wordNum;i++){
                    if(remainder>0){
                        line+=(space+" "+words[i]);
                        remainder--;
                    }else line+=(space+words[i]);
                }
            }
            return line;
        }
        
    }
    vector<string> fullJustify(vector<string> &words, int L) {
        int left=0;
        int charNumWithinNextWord=words[0].size();
        int n=charNumWithinNextWord;
        vector<string> ret;
        int i;
        for(i=1;i<words.size();i++){
            n=charNumWithinNextWord;
            charNumWithinNextWord=n+words[i].size()+1;
            if(charNumWithinNextWord>L){
                string line=cline(words,left,i-left,L);
                ret.push_back(line);
                left=i;
                charNumWithinNextWord=words[i].size();
            }
        }
        string line=cline(words,left,i-left,L);
        ret.push_back(line);
        return ret;
    }
};