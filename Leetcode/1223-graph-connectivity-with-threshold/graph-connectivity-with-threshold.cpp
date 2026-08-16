class Solution {
    void dfs(int node, int compId, vector<vector<int>>& adj, vector<int>& component) {
        component[node] = compId;
        for (int neighbor : adj[node]) {
            if (component[neighbor] == 0) {
                dfs(neighbor, compId, adj, component);
            }
        }
    }

public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n + 1);
        for (int z = threshold + 1; z <= n; z++) {
            for (int m = z * 2; m <= n; m += z) {
                adj[z].push_back(m);
                adj[m].push_back(z);
            }
        }
        vector<int> component(n + 1, 0);
        int currentComponentId = 1;
        
        for (int i = 1; i <= n; i++) {
            if (component[i] == 0) {
                dfs(i, currentComponentId, adj, component);
                currentComponentId++;
            }   
        }

        vector<bool> result(queries.size());
        
        for (int i = 0; i < queries.size(); i++) {
            int cityA = queries[i][0];
            int cityB = queries[i][1];
            
            if (component[cityA] == component[cityB]) {
                result[i] = true;
            } else {
                result[i] = false;
            }
        }
        
        return result;
    }
};