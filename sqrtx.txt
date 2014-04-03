class Solution {
public:
    int sqrt(int x) {
        if(x==1)
            return x;
        int l=0;
        int r=x;
        int m;
        while(l<r){
            m=(r+l)/2+1;   //notice +1 for instance x=2
            if(m==x/m)
                return m;
            else if(m<x/m)
                l=m;      //not m+1
            else
                r=m-1;
        }
        return r;
    }
};