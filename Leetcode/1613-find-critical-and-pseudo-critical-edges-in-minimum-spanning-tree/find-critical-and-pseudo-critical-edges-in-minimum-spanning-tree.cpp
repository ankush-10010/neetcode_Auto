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

    bool unite(int x,int y){
        int leaderX = find(x);
        int leaderY = find(y);

        if(leaderX == leaderY) return false;
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
        return true;
    }

    bool connected(int x,int y){
        return find(x) == find(y);
    }
};
struct Edge{
    int weight;
    int u;
    int v;
    int original_index;
};
class Solution {
public:
    int runKruskal(int skipIndex,int forceIndex,int n,vector<Edge>& newEdges){
        DSU dsu(n);
        int cost = 0;
        int edgesUsed = 0;
        int m = newEdges.size();
        if(forceIndex != -1){
            dsu.unite(newEdges[forceIndex].u,newEdges[forceIndex].v);
            cost += newEdges[forceIndex].weight;
            edgesUsed++;
        }

        for(int i=0;i<m;i++){
            if(i == skipIndex) continue;

            int u = newEdges[i].u;
            int v = newEdges[i].v;
            int weight = newEdges[i].weight;

            if(dsu.unite(u,v)){
                cost += weight;
                edgesUsed++;
            }

        }
        if(edgesUsed != n-1) return 1e9;
        return cost;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<Edge> newEdges(m);
        for(int i=0;i<m;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            int original_index = i;

            newEdges[i] = {weight,u,v,original_index};
        }

        auto cmp = [](const Edge& a,const Edge& b){
            return a.weight < b.weight;
        };
        sort(newEdges.begin(),newEdges.end(),cmp);

        int baseCost = runKruskal(-1,-1,n,newEdges);

        vector<int> critical;
        vector<int> p_critical;

        for(int i=0;i<m;i++){
            int originalIndex = newEdges[i].original_index;
            if(runKruskal(i,-1,n,newEdges) > baseCost){
                critical.push_back(originalIndex);
            }else if(runKruskal(-1,i,n,newEdges) == baseCost){
                p_critical.push_back(originalIndex);
            }
        }

        return {critical,p_critical};
    }
};