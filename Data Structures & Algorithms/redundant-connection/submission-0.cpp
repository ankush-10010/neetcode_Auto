class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(parent[x] == x){
            return x;
        }
        return find(parent[x]); //this finds the leader of the group
    }
    bool unionFunction(int u,int v){
        int pu = find(u);
        int pv = find(v);

        if(pu == pv){
            return false; // cycle detected
        } 
        parent[pv] = pu; // parent formation
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        /* we detect a cycle
        if there are no cycles then we return the edges.lastelt
        if there are cycles then we have to remove the edges responsible for the cycle
        now there are multiple edges that can be removed to get a non cyclic graph
        the one edge that appears last in the edges list will be the answer */

        int n = edges.size();
        parent.resize(n+1);

        for(int i=1;i<n+1;i++){
            parent[i] =i;
        }

        for(auto& e: edges){
            if(!unionFunction(e[0],e[1])){
                return e;
            }
        }
        return {};
    }
};
