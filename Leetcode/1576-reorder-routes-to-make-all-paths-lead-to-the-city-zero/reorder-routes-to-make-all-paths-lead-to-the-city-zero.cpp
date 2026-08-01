class Solution {
public:
    vector<vector<bool>> Transitive(int n,vector<vector<int>>& connections){
        vector<vector<int>> adj(n);
        for(const auto& connection: connections){
            int from = connection[0];
            int to = connection[1];
            adj[from].push_back(to);
        }

        vector<vector<bool>> reachable(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            vector<int> stack = {i};
            reachable[i][i] = true;
            while(!stack.empty()){
                int currNode = stack.back();
                stack.pop_back();
                for(int neigh : adj[currNode]){
                    if(!reachable[i][neigh]){
                        reachable[i][neigh] = true;
                        stack.push_back(neigh);
                    }
                }
            }
        }

        return reachable;
    }
    int minReorder(int n, vector<vector<int>>& connections){
        vector<vector<pair<int,int>>> adj(n);
        for(const auto& conn: connections){
            int to = conn[1];
            int from = conn[0];

            adj[to].push_back({from,0});
            adj[from].push_back({to,1});
        }
        vector<bool> visited(n,false);
        int flips = 0;  
        vector<int> stack = {0};
        visited[0]= true;
        while(!stack.empty()){
            int curr = stack.back();
            stack.pop_back();
            for(auto& edge: adj[curr]){
                int neigh = edge.first;
                int cost = edge.second;
                if(!visited[neigh]){
                    visited[neigh]= !visited[neigh];
                    flips+=cost;
                    stack.push_back(neigh);
                }
            }
        }
        return flips;
    }
    
};