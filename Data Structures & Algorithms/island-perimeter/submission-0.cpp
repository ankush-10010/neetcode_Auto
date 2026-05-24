class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid,int& perimeter){
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<pair<int,int>> paths;

        paths.push_back({i-1,j});
        paths.push_back({i,j-1});
        paths.push_back({i,j+1});
        paths.push_back({i+1,j});

        if(grid[i][j] == 1){
            if(i == 0){
                perimeter++;
            }
            if(j == 0){
                perimeter++;
            }
            if(i == rows-1){
                perimeter++;
            }
            if(j == cols-1){
                perimeter++;
            }
            for(auto p:paths){
                int nx = p.first;
                int ny = p.second;

                if(nx < 0 || ny < 0 || nx >= rows || ny >= cols){
                    continue;
                }

                if(grid[nx][ny] == 0){
                    perimeter++;
                }
            }
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int perimeter = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                dfs(i,j,grid,perimeter);
            }
        }

        return perimeter;
    }
};