class Solution {
public:
    int candy(vector<int> &ratings) {
        int* inc=new int[ratings.size()]();
        int ret=0;
        for(int i=1;i<ratings.size();i++){
            if(ratings[i]>ratings[i-1]){
                inc[i]=inc[i-1]+1;
            }
        }
        for(int i=ratings.size()-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                int tmp=inc[i+1]+1;
                inc[i]=max(tmp,inc[i]);
            }
        }
        for(int i=0;i<ratings.size();i++)
            ret+=inc[i];
        return ret+ratings.size();
    }
};