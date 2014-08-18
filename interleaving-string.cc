class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        //unordered_map<char> m;
        int n1=s1.size();int n2=s2.size();int n3=s3.size();
        if((n1+n2)!=n3) return false;
        if(n2==0) return (s1==s3);
        if(n1==0)  return (s2==s3);
        vector<vector<bool>> dp(n1+1,vector<bool>(n2+1,false));
        dp[0][0]=1;
        for(int i=1;i<=n1;i++)
            dp[i][0]=(s1[i-1]==s3[i-1]); 
        for(int j=1;j<=n2;j++)
            dp[0][j]=(s2[j-1]==s3[j-1]); 
        for(int i=1;i<=n1;i++)
            for(int j=1;j<=n2;j++){
                bool t1=false,t2=false;
                if(s1[i-1]==s3[i+j-1]) t1=dp[i-1][j];
                if(s2[j-1]==s3[i+j-1]) t2=dp[i][j-1];
                dp[i][j]=(t1|t2);
            }
        return dp[n1][n2];
        //for(int i=0;i<n1;i++)
          //  m[s1[i]]+=1;
        //for(int i=0;i<n2;i++)
          //  m[s2[i]]+=1;
        //for(int i=0;i<n3;i++){
          //  if(m.count(s3[i])>0) m[s3[i]]-=1;
        //    else return false;
        //}
        
    }
};