// n^2
class Solution {
public:
    int jump(int A[], int n) {
        if(n==1)
            return 1;
        int* min=new int[n-1];
        for(int i=0;i<n-1;i++)
            min[i]=INT_MAX;
        for(int i=n-2;i>=0;i--){
            if(i+A[i]>=n)
                min[i]=1;
            else{
                for(int j=1;j<=A[i];j++){
                    if(min[i+j]<min[i])
                        min[i]=min[i+j];
                }
                min[i]+=1;
            }
        }
        int ret=min[0];
        delete[] min;
        return ret;
    }
};
//n
class Solution {
public:
    int jump(int A[], int n) {
        int last=0;
        int ret=0;
        int cur=0;
        for(int i=0;i<n;i++){
            if(i>last){
                if (cur == last && last < n-1)
                    return -1;
                last=cur;
                ret++;
            }
            cur=max(cur,i+A[i]);
        }
        return ret;
    }
};