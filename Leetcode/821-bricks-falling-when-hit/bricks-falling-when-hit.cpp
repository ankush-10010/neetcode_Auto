class Solution {
public:
    vector<int> parent;
    vector<int> size;
    int find(int i){
        if(parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    void union_set(int i,int j){
        int leader1 = find(i);
        int leader2 = find(j);
        if(leader1 != leader2){
            if(size[leader1] < size[leader2]){
                parent[leader1] = leader2;
                size[leader2] += size[leader1];
            }else{
                parent[leader2] = leader1;
                size[leader1] += size[leader2];
            }
        }
    }
    int getSize(int i){
        return size[find(i)];
    } 
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size();
        int n = grid[0].size();
        int ROOF = m*n;

        parent.resize(m*n+1);
        size.resize(m*n+1,1);
        for(int i=0;i<=ROOF;i++){
            parent[i] = i;
        }
        
        vector<vector<int>> final_grid = grid;
        for(auto& hit : hits){
            int r = hit[0];
            int c = hit[1];
            final_grid[r][c] = 0;
        }
        auto isValid = [&](int r, int c){
            return r>=0 && c>=0 && r<m && c<n && final_grid[r][c] == 1;
        };
        vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(final_grid[i][j] == 1){
                    int current_node = i*n+j;

                    if(i==0) union_set(current_node,ROOF);

                    if(isValid(i-1,j)) union_set(current_node,(i-1)*n+j);
                    if(isValid(i,j-1)) union_set(current_node,i*n+(j-1));
                }
            }
        }

        vector<int> result(hits.size(),0);
        for(int i=hits.size()-1;i>=0;i--){
            int r = hits[i][0];
            int c = hits[i][1];

            if(grid[r][c] == 0) continue;
            int pre_roof_size = getSize(ROOF);

            final_grid[r][c] = 1;
            int curr_node = r*n+c;
            if(r==0) union_set(curr_node,ROOF);

            for(const auto& dir : dirs){
                int nr = r + dir.first;
                int nc = c + dir.second;

                if(isValid(nr,nc)){
                    union_set(curr_node,nr*n+nc);
                }
            }

            int post_roof_size = getSize(ROOF);
            result[i] = max(0,post_roof_size-pre_roof_size-1);
        }
        return result;
    }
};