class Solution {
public:
    void nextPermutation(vector<int> &num) {
        //think about the case only one digit
        //all digits are same [1,1]
        //all is descending order
        if(num.size()==1)
            return;
        int change=-1;
        int next_large=0;
        for(int i=num.size()-1;i>0;i--){
            if(num[i-1]<num[i]){change=i-1;break;}
        }
        sort(num.begin()+change+1,num.end());
        if(change==-1)
            return;
        for(int i=change+1;i<num.size();i++){
            if(num[i]>num[change]){next_large=i;break;}
        }
        int tmp=num[change];
        num[change]=num[next_large];
        num[next_large]=tmp;
    }
};