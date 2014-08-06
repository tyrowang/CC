class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        //think about case [1] [1,1] [1,4,4]
        vector<vector<int> > ret;
        vector<int> per=num;
        sort(per.begin(),per.end());
        ret.push_back(per);
        while(1){
            int j=per.size()-1;
            while(j>=1&&per[j]<=per[j-1]) {j--;}
            if(j==0) break;
            for(int k=per.size()-1;k>=j;k--)
                if(per[k]>per[j-1]){
                    int tmp=per[j-1];
                    per[j-1]=per[k];
                    per[k]=tmp;
                    break;
                }
            int left=j,right=per.size()-1;
            while(left<right){
                int tmp=per[left];
                per[left]=per[right];
                per[right]=tmp;
                left++;right--;
            }
            ret.push_back(per);
        }
        return ret;
    }
};