class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& memo){
        int rows = matrix.size();
        int cols = matrix[0].size();
        if(i==rows-1) return matrix[i][j];
        if(memo[i][j] != -1e9) return memo[i][j];
        int dx[] = {1,1,1};
        int dy[] = {-1,0,1};
        int minS = INT_MAX;
        for(int k=0;k<3;k++){
            int nx = i + dx[k];
            int ny = j + dy[k];
            if(nx>= rows || ny>= cols || ny<0) continue;
            int currPath = matrix[i][j] + solve(nx,ny,matrix,memo);
            minS = min(minS,currPath);
        }

        return memo[i][j] = minS;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> memo(matrix.size(),vector<int>(matrix[0].size(),-1e9));
        int result = INT_MAX;
        for(int j=0;j<matrix[0].size();j++){
            int curr = solve(0,j,matrix,memo);
            result = min(result,curr);
        }

        return result;
    }
};