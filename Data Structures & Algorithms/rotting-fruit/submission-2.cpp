class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        if(fresh ==0){
            return 0;
        }
        int minutes =0;
        while(!q.empty()){
            int size= q.size();
            bool rotted = false;
            for(int i=0;i<size;i++){
                auto [x,y]=q.front();
                q.pop();

                vector<pair<int,int>> paths;
                paths.push_back({x+1,y}); 
                paths.push_back({x-1,y}); 
                paths.push_back({x,y+1}); 
                paths.push_back({x,y-1}); 
                for(auto path : paths){
                    int nx = path.first;
                    int ny = path.second;
                    if(nx<0 || ny<0 || nx>= rows || ny>= cols){
                    continue;
                    }
                    if((grid[nx][ny]) != 1){
                        continue;
                    }
                    grid[nx][ny]=2;
                    fresh --;
                    rotted = true;
                    q.push({nx,ny});
                }
            }
            if(rotted){
                minutes++;
            }
        }
        return fresh ==0 ? minutes : -1;
    }
};
