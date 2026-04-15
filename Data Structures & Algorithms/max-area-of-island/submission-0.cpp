class Solution {
public:
    int dfs(int i, int j ,vector<vector<int>>& grid,int &count){
        int rows = grid.size();
        int cols = grid[0].size();

        if(i<0 || j<0 || i>=rows || j>=cols || grid[i][j]==0){
            return count;
        }
        count ++ ;
        grid[i][j]=0;
        dfs(i+1,j,grid,count);
        dfs(i-1,j,grid,count);
        dfs(i,j+1,grid,count);
        dfs(i,j-1,grid,count);
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    int count=0;
                    maxArea=max(maxArea,dfs(i,j,grid,count));
                }
            }
        }
        return maxArea;
    }
};
