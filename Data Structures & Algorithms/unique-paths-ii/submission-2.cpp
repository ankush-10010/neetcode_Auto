class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1] == 1 || obstacleGrid[0][0] == 1){
            return 0;
        }
        // if(obs)
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        dp[0][0] = 0;
        dp[1][1] = 1;
        for(int i=0;i<n;i++){
            dp[i][0] = 0;
        }
        for(int i=0;i<m;i++){
            dp[0][i] = 0;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(i==1 && j==1){
                    continue;
                }
                if(obstacleGrid[i-1][j-1] == 1){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[n][m];
    }
};