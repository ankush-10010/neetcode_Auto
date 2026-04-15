class Solution {
public:
    void dfs(int i,int j,vector<vector<char>> &board,vector<vector<bool>>& vis){
        int rows=board.size();
        int cols=board[0].size();
        
        vis[i][j]=true;
        board[i][j] = '#';
        vector<pair<int,int>> paths;
        paths.push_back({i+1,j});
        paths.push_back({i-1,j});
        paths.push_back({i,j+1});
        paths.push_back({i,j-1});

        for(auto path : paths){ 
            int nx = path.first;
            int ny = path.second;

            if(nx<0 || ny<0 || nx>=rows || ny>=cols){
                continue;
            }
            if (board[nx][ny] != 'O' || vis[nx][ny]){
                continue;
            }

            dfs(nx,ny,board,vis);
        }
    }
    void solve(vector<vector<char>>& board) {
        int rows=board.size();
        int cols=board[0].size();
        vector<vector<bool>> vis (rows,vector<bool>(cols,false));
        
        for(int i=0;i<rows;i++){
            if(board[i][0] == 'O' && !vis[i][0]){
                dfs(i,0,board,vis);
            }
            if (board[i][cols-1] == 'O' && !vis[i][cols-1]){
                dfs(i, cols-1, board, vis);
            }
        }

        for(int j=0;j<cols;j++){
            if(board[0][j] == 'O' && !vis[0][j]){
                dfs(0,j,board,vis);
            }
            if (board[rows-1][j] == 'O' && !vis[rows-1][j]){
                dfs(rows-1, j, board, vis);
            }
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X' ; 
                }else if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }

    }
};
