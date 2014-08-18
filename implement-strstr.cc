class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        //string s=haystack;
        //string t=needle;
        if(strlen(needle)==0)
            return haystack;
        if(strlen(haystack)==0) return NULL;
        int* next=new int[strlen(needle)];
        int j,k;
        next[0]=-1;
        j=0;
        k=-1;
        while(j<strlen(needle)-1)
        {
            if(k==-1||needle[j]==needle[k])    //p[j]==p[k]
            {
                j++;
                k++;
                next[j]=k;
            }
            else                   //p[j]!=p[k]
                k=next[k];
        }
        int i=0;j=0;
        //when unsigned compare int eg. 4 -1,int is converted into unsigned which is very large number
        //but when add int to unsigned int, it will automatically be changed into int
        while(i<strlen(haystack)){
            if(j==-1||haystack[i]==needle[j]){i++;j++;}
            else j=next[j];
                    if(j==strlen(needle)) {
                delete[] next;
                return &haystack[i-j];
            }
            
        }

        return NULL;
        
    }
};