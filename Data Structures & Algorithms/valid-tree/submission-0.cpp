class Solution {
public:
    void dfs(int u, vector<bool>& vis, list<int>* l) {
            vis[u] = true;
            for (int v : l[u]) {
                if (!vis[v]) {
                    dfs(v, vis, l);
                }
            }
        }
    bool isCycle(int src,int par,vector<bool> & vis,list<int>* l){
        vis[src]=true;
        list<int> neighbors = l[src];
        for(int v:neighbors){
            if(!vis[v]){
                if(isCycle(v,src,vis,l)){
                    return true;
                }
            }else{
                if(v!=par){
                    return true; 
                }
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        
        if(edges.size() != n-1){
            return false;
        }
        vector<bool> vis_cycle(n,false);
        vector<bool> vis_dfs(n,false);
        list<int>* l = new list<int>[n];
        
        for (auto &edge : edges) {
            l[edge[0]].push_back(edge[1]);
            l[edge[1]].push_back(edge[0]);
        }

        if(isCycle(0,-1,vis_cycle,l)){
            return false;
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!vis_dfs[i]) {
                dfs(i, vis_dfs, l);
                count++;
            }
        }

        if(count>1){
            return false;
        }
        return true;        
    }   
};
