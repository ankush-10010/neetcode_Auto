class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(dp[i][j] != 0){
                return dp[i][j];
        }
        vector<pair<int,int>> paths;
        int neighbour_path =0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        paths.push_back({i+1,j});
        paths.push_back({i-1,j});
        paths.push_back({i,j+1});
        paths.push_back({i,j-1});

        for(auto path: paths){
                int nx = path.first;
                int ny = path.second;
                if(nx<0 || ny<0 || nx>=rows || ny>= cols){
                        continue;
                }
                if(matrix[nx][ny] > matrix[i][j]){
                  neighbour_path = max(dfs(nx,ny,matrix,dp),neighbour_path);
                }else{
                        continue;
                }
        }
        return dp[i][j]=1+neighbour_path;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
       int rows = matrix.size();
       int cols = matrix[0].size();
       int maxCount = INT_MIN;
       vector<vector<int>> dp(rows,vector<int>(cols,0));
       for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
                dp[i][j]=dfs(i,j,matrix,dp);
                maxCount = max(maxCount,dp[i][j]);
        }
       }
       return maxCount;
    }
};
