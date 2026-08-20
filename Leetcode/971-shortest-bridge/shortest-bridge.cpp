class Solution {
public:
    int minDist;
    struct Node{
        int row;
        int col;
        int currDist;
    };
    void bfs(int i,int j,vector<vector<int>>& grid){
        int rows = grid.size();
        int cols = grid[0].size();
        queue<Node> q;
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,1,-1};
        q.push({i,j,0});
        // int currDist = 0;
        visited[i][j] = true;
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int curr_x = top.row;
            int curr_y = top.col;
            int currDist = top.currDist;
            for(int k=0;k<4;k++){
                int nx = curr_x + dx[k];
                int ny = curr_y + dy[k];
                if(nx < 0 || ny < 0 || nx >= rows || ny >= cols || visited[nx][ny]){
                    continue;
                }
                if(grid[nx][ny] == 1) continue;

                if(grid[nx][ny] == 2){
                    minDist = min(minDist,currDist);
                    return;
                }

                if(!visited[nx][ny] &&  grid[nx][ny] == 0){
                    visited[nx][ny] = true;
                    q.push({nx,ny,currDist+1});
                }

                
            }
        }
    }
    void populatePatches(int i,int j,int currPatch,vector<vector<int>>& grid,vector<vector<bool>>& visitPatches,vector<vector<int>>& patches){
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>> p;
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,1,-1};
        visitPatches[i][j] = true;
        patches[i][j] = currPatch;
        p.push({i,j});
        while(!p.empty()){
            auto top = p.front();
            int curr_x = top.first;
            int curr_y = top.second;
            p.pop();
            for(int k=0;k<4;k++){
                int nx = curr_x + dx[k];
                int ny = curr_y + dy[k];
                if(nx < 0 || ny < 0 || nx >= rows || ny >= cols || grid[nx][ny] == 0){
                    continue;
                }
                if(grid[nx][ny] == 1 && !visitPatches[nx][ny]){
                    visitPatches[nx][ny] = true;
                    patches[nx][ny] = currPatch;
                    p.push({nx,ny});
                }
            }
        }

    }
    void printPatchGrid(const vector<vector<int>>& patches) {
        int rows = patches.size();
        int cols = patches[0].size();

        cout << "\n--- Labeled Island Patches ---\n";
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                cout << setw(3) << patches[r][c] << " ";
            }
            cout << "\n";
        }
        cout << "------------------------------\n";
    }
    int shortestBridge(vector<vector<int>>& grid) {
        vector<vector<int>> patches(grid.size(),vector<int>(grid[0].size(),0));
        vector<vector<bool>> visitPatches(grid.size(),vector<bool>(grid[0].size(),false));
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        minDist = INT_MAX;
        int rows = grid.size();
        int cols = grid[0].size();

        int currPatch = 1;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 1 && !visitPatches[i][j]){
                    populatePatches(i,j,currPatch,grid,visitPatches,patches);
                    currPatch++;
                }
            }
        }
        printPatchGrid(patches);
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(patches[i][j] == 1){
                    bfs(i,j,patches);
                }
            }
        }

        return minDist;
    }
};