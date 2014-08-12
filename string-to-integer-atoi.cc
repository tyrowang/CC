class Solution {
public:
    int atoi(const char *str1) {
        std::locale loc;
    //white space, charactor
    string str=str1;
    if(str.size()==0) return 0;
    int i=0;
    while(str[i]==' ') i++;
    long long ret=0;
    long long negtive=1;
    if(str.size()==1&&!isdigit(str[i],loc)) return 0;
    if(str[i]!='-'&&str[i]!='+'&&!isdigit(str[i],loc)) return 0;
    if(str[i]=='-') negtive=-1;
    if(isdigit(str[i],loc)) ret=(int)(str[i]-'0');
    for(i=i+1;i<str.size();i++){
        if (isdigit(str[i],loc)){
            long long tmp=ret*10+(int)(str[i]-'0');
            if(tmp*negtive>=INT_MAX)
                return INT_MAX;
            if(tmp*negtive<=INT_MIN)
                return INT_MIN;
            ret=tmp;            
        }
        else return ret*negtive; 
    }
    return ret*negtive; 
    }
};