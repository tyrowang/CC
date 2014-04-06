class Solution {
public:
    vector<string> split(const string& src, string separate_character)  
    {  
        vector<string> strs; 
        int separate_characterLen = separate_character.size(); 
    	if(separate_characterLen==0||src==""){
    		strs.push_back(src);
    		return strs;
    	}
        int lastPosition = 0,index = -1;  
        while (-1 != (index = src.find(separate_character,lastPosition)))  
        {  
            if(src.substr(lastPosition,index - lastPosition)!="")
            strs.push_back(src.substr(lastPosition,index - lastPosition));  
            lastPosition = index + separate_characterLen;  
        }  
        string lastString = src.substr(lastPosition);  
        if (!lastString.empty())  
            strs.push_back(lastString); 
        return strs;  
    }  
    void reverseWords(string &s) {
        vector<string> v=split(s," ");
        if(v.size()>=1){
            for(int i=0;i<v.size()/2;i++){
                if(v[i]!=v[v.size()-1-i]){
                    string t=v[i];
                    v[i]=v[v.size()-1-i];
                    v[v.size()-1-i]=t;
                }
            }
            string ret="";
            for(int i=0;i<v.size()-1;i++){
                ret+=v[0]+" ";
            }
            ret+=v[v.size()-1];
            s=ret;
        }else{
            s="";}
    }
};