class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& edge : redEdges) {
            adj[edge[0]].push_back({edge[1], 0});
        }
        for (auto& edge : blueEdges) {
            adj[edge[0]].push_back({edge[1], 1});
        }

        vector<vector<int>> dist(n, vector<int>(2, -1));
        queue<pair<int, int>> q; 
        
        q.push({0, 0});
        q.push({0, 1});
        dist[0][0] = 0;
        dist[0][1] = 0;

        while (!q.empty()) {
            auto [currNode, currColor] = q.front();
            q.pop();
            
            for (auto& [neighbor, nextColor] : adj[currNode]) {
                if (currColor != nextColor && dist[neighbor][nextColor] == -1) {
                    dist[neighbor][nextColor] = dist[currNode][currColor] + 1;
                    q.push({neighbor, nextColor});
                }
            }
        }
        
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            if (dist[i][0] != -1 && dist[i][1] != -1) {
                ans[i] = min(dist[i][0], dist[i][1]); 
            } else if (dist[i][0] != -1) {
                ans[i] = dist[i][0]; 
            } else if (dist[i][1] != -1) {
                ans[i] = dist[i][1]; 
            }
        }
        
        return ans;
    }
};