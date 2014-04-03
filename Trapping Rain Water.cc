 //I tried to find the peak,it fails in this case [5,2,1,2,1,5] small peak in middle
class Solution {
public:
    int trap(int A[], int n) {
        if(n<3)
            return 0;
        vector<int> lmax(n);
        vector<int> rmax(n);
        lmax[0]=A[0];
        rmax[n-1]=A[n-1];
        int ret=0;
        for(int i=1;i<=n-1;i++){  //the n-1 constraint
            lmax[i]=max(A[i],lmax[i-1]); //A[i] not lmax[i]
            rmax[n-1-i]=max(A[n-1-i],rmax[n-i]);
        }
        for(int i=0;i<=n-1;i++){
            int tmp=min(lmax[i],rmax[i]);
            if(A[i]<tmp)
                ret+=(tmp-A[i]);
        }    
       return ret;
    }
};