class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            indegree[v]++;
        }
        
        vector<int> result;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                result.push_back(i);
            }
        }
        return result;

    }
};