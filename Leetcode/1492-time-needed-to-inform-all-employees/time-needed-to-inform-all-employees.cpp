class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            // manager[headID] --> -1
            if(i == headID){
                continue;
            }
            int u = manager[i];
            int v = i;
            adj[u].push_back(v);
        }
        vector<bool> visited(n,false);
        int headTime = informTime[headID];
        queue<pair<int,int>> q;
        q.push({headID,0});
        visited[headID] = true;
        int maxTime = 0;
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int currId = top.first;
            int currTime = top.second;
            maxTime = max(maxTime,currTime);
            for(int neigh : adj[currId]){
                int neighTime = currTime + informTime[currId];
                if(!visited[neigh]){
                    visited[neigh] = true;
                    maxTime = max(maxTime,neighTime);
                    q.push({neigh,neighTime});
                }
            }
        }
        return maxTime;
    }
};