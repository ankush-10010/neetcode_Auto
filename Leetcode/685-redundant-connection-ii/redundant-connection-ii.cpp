class Solution {
public:
    vector<int> dsu_parent;
    int find(int x){
        if(dsu_parent[x] == x) return x;
        return dsu_parent[x] = find(dsu_parent[x]);
    }
    int union1(int x, int y){
        int leaderX = find(x);
        int leaderY = find(y);

        if(leaderX != leaderY){
            if(leaderX < leaderY){
                dsu_parent[leaderY] = leaderX;
                return leaderX;
            } else {
                dsu_parent[leaderX] = leaderY;
                return leaderY;
            }
        }
        return leaderX;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> edge1, edge2, cycleEdge; 
        vector<int> directParent(n + 1, 0);
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            if(directParent[v] != 0){ 
                edge1 = {directParent[v], v}; 
                edge2 = edge;                 
            } else {
                directParent[v] = u;
            }
        }

        dsu_parent.resize(n + 1);
        for(int i = 1; i <= n; i++){
            dsu_parent[i] = i; 
        }
        
        for(auto& edge : edges){
            if(edge == edge2) continue; 
            
            int u = edge[0];
            int v = edge[1];
            
            int leaderU = find(u);
            int leaderV = find(v);
            
            if(leaderU == leaderV){
                cycleEdge = edge;
            } else {
                union1(u, v);
            }
        }

        if(edge1.empty()){
            return cycleEdge; 
        }

        if(!cycleEdge.empty()){
            return edge1; 
        }

        return edge2; 
    }
};