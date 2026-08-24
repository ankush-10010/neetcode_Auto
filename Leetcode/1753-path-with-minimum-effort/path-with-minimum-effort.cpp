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
            }
            else if(rank[leaderY] > rank[leaderX]){
                parent[leaderX] = leaderY;
            }else{
                parent[leaderY] = leaderX;
                rank[leaderX]++;
            }
        }
    }

    bool connected(int x, int y){
        return find(x) == find(y);
    }
};
int getID(int r,int c,int cols){
    return r*cols+c;
}
struct Edge{
    int row;
    int col;
    int weight;
};
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        int n = rows*cols;
        
        if(rows == 1 && cols == 1) return 0;
        vector<Edge> edges;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(j+1 < cols){
                    int weight = abs(heights[i][j] - heights[i][j+1]);
                    edges.push_back({getID(i,j,cols),getID(i,j+1,cols),weight});
                }
                if(i+1 < rows){
                    int weight = abs(heights[i][j] - heights[i+1][j]);
                    edges.push_back({getID(i,j,cols),getID(i+1,j,cols),weight});
                }
            }
        }

        auto cmp = [](const Edge& a,const Edge& b){
            return a.weight < b.weight;
        };

        sort(edges.begin(),edges.end(),cmp);

        int startNode = 0;
        int endNode = rows*cols - 1;
        DSU dsu(n+1);
        for(const Edge& edge : edges){
            dsu.unite(edge.row,edge.col);

            if(dsu.find(startNode) == dsu.find(endNode)){
                return edge.weight;
            }
        }
        return 0;
    }
};
// class Solution {
// public:
//     int minimumEffortPath(vector<vector<int>>& heights) {
//         int rows = heights.size();
//         int cols = heights[0].size();
//         vector<vector<int>> efforts(rows,vector<int>(cols,INT_MAX));

//         auto cmp = [](const pair<int,pair<int,int>>& a,const pair<int,pair<int,int>>& b){
//             return a.first > b.first;
//         };

//         priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,decltype(cmp)> pq(cmp);

//         int dx[] = {-1,1,0,0};
//         int dy[] = {0,0,-1,1};

//         efforts[0][0] = 0;
//         pq.push({0,{0,0}});

//         while(!pq.empty()){
//             auto it = pq.top();
//             pq.pop();
//             int current_effort = it.first;
//             int current_x = it.second.first;
//             int current_y = it.second.second;

//             if(current_x == rows-1 && current_y == cols-1){
//                 return current_effort;
//             }
//             if(current_effort > efforts[current_x][current_y]){
//                 continue;
//             }

//             for(int i=0;i<4;i++){
//                 int new_x = current_x + dx[i];
//                 int new_y = current_y + dy[i];

//                 if(new_x >= 0 && new_x < rows && new_y >= 0 && new_y < cols){
//                     int new_cost = abs(heights[new_x][new_y]-heights[current_x][current_y]);
//                     int new_effort = max(new_cost,current_effort);

//                     if(new_effort < efforts[new_x][new_y]){
//                         efforts[new_x][new_y] = new_effort;
//                         pq.push({new_effort,{new_x,new_y}});
//                     }
//                 }
//             }
//         }
//         return 0;
//     }
// };