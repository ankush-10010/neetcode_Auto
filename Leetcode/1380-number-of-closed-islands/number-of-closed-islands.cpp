class Solution {
public:
    bool dfs(vector<vector<int>>& grid,vector<vector<bool>>& visited,queue<pair<int,int>>& q){
        int row = grid.size();
        int col = grid[0].size();
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,1,-1};
        bool isClosed = true;
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int curr_x = top.first;
            int curr_y = top.second;
            if(curr_x == 0 || curr_y == 0 || curr_x == row-1 || curr_y == col-1){
                isClosed = false;
            }
            for(int i=0;i<4;i++){
                int nx = curr_x + dx[i];
                int ny = curr_y + dy[i];
                if(nx < 0 || ny < 0 || nx >= row || ny >= col || grid[nx][ny] == 1){
                    continue;
                }
                // if(grid[nx][ny] == 0 && (nx == 0 || ny == 0 || nx == row-1 || ny == col-1)){
                //     break;
                // }
                if(!visited[nx][ny]){
                    if(grid[nx][ny] == 0){
                        visited[nx][ny] = true;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return isClosed;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        int count = 0;
        queue<pair<int,int>> q;
        for(int i=1;i<row-1;i++){
            for(int j=1;j<col-1;j++){
                if(grid[i][j] == 0 && !visited[i][j]){
                    q.push({i,j});
                    if(dfs(grid,visited,q)){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};