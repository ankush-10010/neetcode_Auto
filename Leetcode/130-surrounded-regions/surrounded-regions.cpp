class DSU{
private:
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n){
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
        rank.assign(n,0);
    }
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int x,int y){
        int leaderX = find(x);
        int leaderY = find(y);

        if(leaderX != leaderY){
            if(rank[leaderX] > rank[leaderY]){
                parent[leaderY] = leaderX;
            }else if(rank[leaderY] > rank[leaderX]){
                parent[leaderX] = leaderY;
            }else{
                parent[leaderY] = leaderX;
                rank[leaderX]++;
            }
        }
    }

    bool connected(int u,int v){
        return find(u) == find(v); 
    }
};
class Solution {
public:
    int getID(int r,int c,int C){
        return r*C + c;
    }
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0) return;
        int rows = board.size();
        int cols = board[0].size();

        DSU dsu(rows*cols+1);

        int virtualNode = rows*cols;
        
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(board[r][c] == 'O'){
                    if(r==0 || r==rows-1 || c==0 || c==cols-1){
                        dsu.unite(getID(r,c,cols),virtualNode);
                    }else{
                        if(board[r+1][c] == 'O'){
                            dsu.unite(getID(r+1,c,cols),getID(r,c,cols));
                        }
                        if(board[r-1][c] == 'O'){
                            dsu.unite(getID(r-1,c,cols),getID(r,c,cols));
                        }
                        if(board[r][c+1] == 'O'){
                            dsu.unite(getID(r,c+1,cols),getID(r,c,cols));
                        }
                        if(board[r][c-1] == 'O'){
                            dsu.unite(getID(r,c-1,cols),getID(r,c,cols));
                        }
                    }
                }
            }
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j] == 'O'){
                    if(!dsu.connected(getID(i,j,cols),virtualNode)){
                        board[i][j] = 'X';
                    }
                }
            }
        }
    }
};