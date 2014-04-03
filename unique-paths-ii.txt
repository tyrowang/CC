class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        for(int i=0;i<obstacleGrid.size();i++)
            for(int j=0;j<obstacleGrid[0].size();j++)
                if(obstacleGrid[i][j]==1)
                    obstacleGrid[i][j]=-1;
        int i,j;
         for(i=0;i<obstacleGrid.size();i++)
            for(j=0;j<obstacleGrid[0].size();j++){
                if(obstacleGrid[i][j]==-1)
                    continue;
                if(i==0&&j==0){           //be careful of the else if , the large brace is necessary! 
                    if(obstacleGrid[i][j]==0)
                        obstacleGrid[i][j]=1;
                }
                else if(i==0&&j>0){
                    if(obstacleGrid[i][j-1]!=-1)
                        obstacleGrid[i][j]=obstacleGrid[i][j-1];
                }
                else if(j==0&&i>0){
                    if(obstacleGrid[i-1][j]!=-1)
                        obstacleGrid[i][j]=obstacleGrid[i-1][j];
                }
                else{
                    if(obstacleGrid[i-1][j]!=-1)
                        obstacleGrid[i][j]+=obstacleGrid[i-1][j];
                     if(obstacleGrid[i][j-1]!=-1)
                        obstacleGrid[i][j]+=obstacleGrid[i][j-1];
                }
            }
        if(obstacleGrid[i-1][j-1]==-1)
            return 0;
        return obstacleGrid[i-1][j-1];
    }
};