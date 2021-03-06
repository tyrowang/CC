class Solution {
public:
    int search(int A[], int n, int target) {
        int left=0;
        int right=n-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(A[mid]==target)
                return mid;
            if(A[mid]>A[right]){
              if(target<A[mid]&&target>=A[left])
                right=mid-1;
              else
                left=mid+1;
            }
            else if(A[mid]<A[right])
            {
              if(target>A[mid]&&target<=A[right])
                left=mid+1;
              else
                right=mid-1;
            }
            else
                right--; // important when the previous cases doesn't hit
        }
        return -1;    
    }
};