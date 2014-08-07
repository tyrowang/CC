class Solution {
public:
        //it's different with the array with the same length, that is divide method
        //neglect [], [1,2,3,4]  [1,2], [1,2,3] 
        //neglect the case that some array is empty in the process [], [2,3] return 2 instead of 2.5 
        //case [1,1], [1,2] case [1,2], [1,2,3] case [1,2],[1,1] case [2,3][1] case [2],[1,3,4] case [1,4],[2,3]
        //case [1,2][3,4,5,6]
int findKth(int A[],int m,int B[],int n,int k){
    if(m>n) return findKth(B,n,A,m,k);
    if(m==0) return B[k-1];
    if(k==1) return min(A[0],B[0]);
    int pa=min(m,k/2), pb=k-pa;
    if(A[pa-1]<B[pb-1]) return findKth(A+pa,m-pa,B,n,k-pa);
    if(A[pa-1]>B[pb-1]) return findKth(A,m,B+pb,n-pb,k-pb);
    if(A[pa-1]==B[pb-1]) return A[pa-1];
}
double findMedianSortedArrays(int A[], int m, int B[], int n) {
    int total=m+n;
    if(total & 0x1) return findKth(A,m,B,n,total/2+1);
    else return (double)(findKth(A,m,B,n,total/2)+findKth(A,m,B,n,total/2+1))/2; 
}
};