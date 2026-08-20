class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    int union1(int x,int y){
        int leaderX = find(x);
        int leaderY = find(y);
        if(leaderX != leaderY){
            if(leaderX < leaderY){
                parent[leaderY] = leaderX;
                return leaderX;
            }else{
                parent[leaderX] = leaderY;
                return leaderY;
            }
        }else{
            return leaderX;
        }

    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        for(int i=0;i<parent.size();i++){
            parent[i] = i;
        }
        for(auto& edge:edges){
            int u = edge[0];
            int v = edge[1];
            
            int leaderU = find(u);
            int leaderV = find(v);

            if(leaderU == leaderV){
                return edge;
            }else{
                union1(u,v);
            }
        }
        return {};
    }
};