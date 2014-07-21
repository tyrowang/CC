class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()<2)
            return 0;
        vector<int> fprofit(prices.size(),0);
        vector<int> bprofit(prices.size(),0);
        int ret=0;
        int Min=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]<Min){
               Min=prices[i]; 
            }
            fprofit[i]=max(prices[i]-Min,fprofit[i-1]);
        }
        int Max=prices[prices.size()-1];
        for(int i=prices.size()-2;i>=0;i--){
            if(prices[i]>Max){
               Max=prices[i]; 
            }
            bprofit[i]=max(Max-prices[i],bprofit[i+1]);
        }
        for(int i=0;i<prices.size();i++){
            if(bprofit[i]+fprofit[i]>ret)
                ret=bprofit[i]+fprofit[i];
        }
        return ret;
    }
};