class Solution {
private:
    struct Node{
        int r;
        int c;
        int moves;
        int keys;
        Node(int r,int c,int moves,int keys) : r(r),c(c),moves(moves),keys(keys) {}
    };
    int countKeys(vector<string>& grid){
        int count = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == '.' || grid[i][j] == '#' || grid[i][j] == '@') continue;
                if(islower(grid[i][j])) count++;
            }
        }
        return count;
    }
    pair<int,int> startingPoint(vector<string>& grid){
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == '@') return {i,j};
            }
        }
        return {};
    }
public:
    int shortestPathAllKeys(vector<string>& grid) {
        // how to make sure that we have all the keys
        int numKeys = countKeys(grid);
        auto st = startingPoint(grid);
        int start_r = st.first;
        int start_c = st.second;
        queue<Node> q;
        // make bitmasking of all the keys that i am holding
        vector<vector<vector<bool>>> visited(grid.size(),vector<vector<bool>>(grid[0].size(),vector<bool>(1<<numKeys,false)));
        q.push(Node(start_r,start_c,0,0));
        visited[start_r][start_c][0] = true;
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        while(!q.empty()){
            int rows = grid.size();
            int cols = grid[0].size();
            Node currNode = q.front();
            q.pop();
            int curr_row = currNode.r;
            int curr_col = currNode.c;
            int curr_moves = currNode.moves;
            int curr_keys = currNode.keys;
            if (curr_keys == ((1 << numKeys) - 1)) return curr_moves;
            for(int i=0;i<4;i++){
                int new_r = curr_row + dx[i];
                int new_c = curr_col + dy[i];
                if(new_r < 0 || new_c < 0 || new_r >= rows || new_c >= cols) continue;
                if(grid[new_r][new_c] == '#') continue;
                if(grid[new_r][new_c] == '.' || grid[new_r][new_c] == '@'){
                    if(!visited[new_r][new_c][curr_keys]){
                        visited[new_r][new_c][curr_keys] = true;
                        q.push(Node(new_r,new_c,curr_moves+1,curr_keys));
                    }
                } 
                if(islower(grid[new_r][new_c])){
                    // keys
                    if(!visited[new_r][new_c][curr_keys]){
                        int shift = grid[new_r][new_c] - 'a';
                        int new_keys = curr_keys | (1<<shift);
                        visited[new_r][new_c][new_keys] = true;
                        q.push(Node(new_r,new_c,curr_moves+1,new_keys));
                    }
                }else if(isupper(grid[new_r][new_c])){
                    char lowerCased = tolower(grid[new_r][new_c]);
                    // check if there is availaible key for this 
                    int shift = lowerCased - 'a';
                    int unlock = curr_keys & (1<<shift);
                    if(unlock != 0){
                        // can be unlocked
                        if(!visited[new_r][new_c][curr_keys]){
                            visited[new_r][new_c][curr_keys] = true;
                            q.push(Node(new_r,new_c,curr_moves+1,curr_keys));
                        }
                    }
                }
            }
        }
        return -1;
    }
};