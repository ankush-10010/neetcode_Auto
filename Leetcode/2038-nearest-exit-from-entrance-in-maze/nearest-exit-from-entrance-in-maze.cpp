class Solution {
private:
    bool isExit(int i,int j,vector<vector<char>>& maze,vector<int>& entrance){
        int row = maze.size();
        int col = maze[0].size();
        if(i == entrance[0] && j==entrance[1]) return false;
        if((i==0 || j==0 || i==row-1 || j==col-1) && maze[i][j] == '.') return true;
        return false;
    }
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<pair<int,int>,int>> q;
        vector<vector<bool>> visited(maze.size(),vector<bool>(maze[0].size(),false));
        q.push({{entrance[0],entrance[1]},0});
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        string drxn[] = {"R","D","L","U"};
        // int size = size_of(dx)/size_of(int);
        int min_dist = 1e7;
        while(!q.empty()){
            auto it = q.front();
            int x = it.first.first;
            int y = it.first.second;
            int dist = it.second;
            q.pop();
            for(int i=0;i<4;i++){
                int row = maze.size();
                int col = maze[0].size();
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if(new_x < 0 || new_y < 0 || new_x >= row || new_y >= col) continue;
                if(!visited[new_x][new_y] && maze[new_x][new_y] == '.'){
                    visited[new_x][new_y] = true;
                    if(isExit(new_x,new_y,maze,entrance)){
                        min_dist = min(min_dist , dist+1);
                        q.push({{new_x,new_y},dist + 1});
                    }else{
                        q.push({{new_x,new_y},dist+1});
                    }
                }
            }
        }
        return (min_dist == 1e7) ? -1 : min_dist;
    }
};