class Solution {
public:
    vector<string> split(const string& src, string separate_character)  
{  
    vector<string> strs;  
      
    int separate_characterLen = separate_character.size(); 
	if(separate_characterLen==0){
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
//case: "/." output:"/." expected: "/"
    string simplifyPath(string path) {
        string ret;
        vector<string> strings=split(path, "/");
        stack<string> stk;
        for(int i=0;i<strings.size();i++){
            if(strings[i]!=""&&strings[i]!="."){   //="" not =NULL notice:strings[i]!="."
                if(strings[i]==".."&&!stk.empty())
                    stk.pop();
                else if (strings[i]!="..")
                    stk.push(strings[i]);
            }
        }
        if(stk.empty())
            return "/";
        while(!stk.empty()){
            ret="/"+stk.top()+ret;
            stk.pop();
        }
        return ret;
    }
};