class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows= grid.size();
        int cols=grid[0].size();

        queue<pair<int,int>> q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }

        vector<int> dx={1,-1,0,0};
        vector<int> dy={0,0,1,-1};

        while(!q.empty()){
            auto [x,y]= q.front();
            q.pop();
            for(int d=0;d<4;d++){
                int nx= x+dx[d];
                int ny= y+dy[d];

                if(nx<0 || ny<0 || nx>= rows || ny>= cols){
                    continue;
                }
                if((grid[nx][ny]) != INT_MAX){
                    continue;
                }
                grid[nx][ny]=grid[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
};
