class Solution {
public:
  bool isNumber(const char *s) 
{
    //Check front spaces and sign
    while(*s == ' ') s++;
    if(*s == '\0') return false;
    if(*s == '-'||*s=='+') s++;

    //Check base part: must contains at least one digit, before or after decimal point(if exits)
    bool flag = isdigit(*s);
    while(isdigit(*s)) s++;
    if(*s=='.')
    {
        s++;
        flag = isdigit(*s)|| flag;
        while(isdigit(*s)) s++;
    } 
    if(!flag) return false;

    //Check exponent part: must contains digit
    if(*s == 'e' || *s == 'E')
    {
        s++;
        if(*s=='+'||*s=='-') s++;
        if(!isdigit(*s)) return false;
        while(isdigit(*s)) s++;
    }

    //Check trailing part
    while(*s==' ') s++;

    return *s =='\0';
}


};