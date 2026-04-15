class Solution {
public:
    void dfs(int u, vector<bool>& vis ,list<int>* l){
        vis[u]=true;
        list<int> neighbors = l[u];
        for(int v:neighbors){
            if(!vis[v]){
                dfs(v,vis,l);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n,false); //which nodes are visited
        // This says "l is a pointer to the first list in an array of lists"
        list<int>* l = new list<int>[n];
        
        for(auto& edge: edges){
            l[edge[0]].push_back(edge[1]);
            l[edge[1]].push_back(edge[0]);
        }
        //now i have a list that i can perform dfs on
        int count =0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,l);
                count++;
            }
        }
        return count;
    }
};
