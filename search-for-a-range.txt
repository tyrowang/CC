class Solution {
public:
    int find_left(int A[], int n, int target){
        int left=0;
        int right=n-1;
        while(left<right){
            int mid=(left+right)/2;
            if(A[mid]<target)
                left=mid+1;
            else
                right=mid;
        }
        if(A[left]==target)
            return left;
        else
            return -1;
    }
    int find_right(int A[], int n, int target){
        int left=0;
        int right=n-1;
        while ( left < right ) {
            int mid = (left + right+1) / 2;
            if ( A[mid] > target )  right= mid - 1;
            else left = mid;
        }
         if(A[left]==target)
            return left;
        else
            return -1;
    }
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ret;
        ret.push_back(find_left(A,n,target));
        ret.push_back(find_right(A,n,target));
        return ret;
        
    }
};