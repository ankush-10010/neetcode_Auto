class Solution {
public:
    int time = 0;
    void dfs(int current,int parent,vector<vector<int>>& adj,vector<int>& arrival,vector<int>& oldest_time,vector<vector<int>>& result){
        time++;
        arrival[current]= time;
        oldest_time[current]= time;

        for(int neigh : adj[current]){
            if(neigh == parent) continue;
            if(arrival[neigh] == 0){
                dfs(neigh,current,adj,arrival,oldest_time,result);
                oldest_time[current] = min(oldest_time[current],oldest_time[neigh]);
                if(oldest_time[neigh] > arrival[current]){
                    result.push_back({current,neigh});
                }   
            }else{
                oldest_time[current] = min(oldest_time[current], arrival[neigh]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto& conn : connections){
            int u = conn[0];
            int v = conn[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> arrival(n,0);
        vector<int> oldest_time(n,0);
        vector<vector<int>> result;

        dfs(0,-1,adj,arrival,oldest_time,result);
        return result;
    }
};