class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if(height.empty())
            return 0;
        int ret=0,i=0,area=0;
        stack<int>s;
        while(i<height.size()){
            if(s.empty()||height[s.top()]<=height[i])
                s.push(i++);
            else{
                int tp=s.top();
                s.pop();
                area=height[tp]*(s.empty()?i:i-s.top()-1);
            }
            if(area>ret)
                ret=area;
        }
        while(s.empty()==false){
            int tp=s.top();
            s.pop();
            area=height[tp]*(s.empty()? i:i-s.top()-1);
            if(area>ret)
                ret=area;
        }    
        //Memory Limit Exceeded 
        //short** dp=new short* [height.size()];
        //for(int j=0;j<height.size();j++)
          // dp[j]=new short[height.size()];
        //int dp=new int[height.size()];
        //for(int j=1;j<height.size();j++){
           // for(int i=0;i<j;i++){
               // dp[i][j]=min(dp[i][j-1],height[j]);
               // int tmp=dp[i][j]*(j-i+1);
               // ret=max(tmp,ret);
           // }
       // }
       //runtime limit exceeded
        //int* dp=new int[height.size()];
        //dp[0]=height[0];
        //for(int i=1;i<height.size();i++){
          //  dp[i]=height[i];
            //for(int j=i;j<height.size();j++){
              //  dp[j]=min(dp[j-1],height[j]);
                //int tmp=dp[j]*(j-i+1);
                //ret=max(tmp,ret);
            //}
        //}
        //for(int j=0;j<height.size();j++)
            //delete[] dp[j];
       // delete[] dp;
        return ret;
    }
};