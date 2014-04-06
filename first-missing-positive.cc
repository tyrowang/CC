class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int np=0;
        for(int i=0;i<n;i++)
            if(A[i]<=0||A[i]>n)
                A[i]=n+1;
        for(int i=0;i<n;i++)
            if(abs(A[i])<=n&&A[abs(A[i])-1]>0)
                A[abs(A[i])-1]=0- A[abs(A[i])-1];
        for(int i=0;i<n;i++)
            if(A[i]>0)
                return (i+1);
        //case:[]
        //case: [0]
        //case: [1]
        //case:[3,2]
        return n+1;
    }
};