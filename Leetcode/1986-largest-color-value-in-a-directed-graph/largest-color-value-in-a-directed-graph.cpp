class Solution {
public:
    vector<int> topoSort(vector<vector<int>>& adj,vector<int>& indegree){
        vector<int> result;
        queue<int> q;

        for(int i=0;i<indegree.size();i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int top = q.front();
            result.push_back(top);
            q.pop();

            for(int neigh : adj[top]){
                indegree[neigh]--;
                if(indegree[neigh] == 0){
                    q.push(neigh);
                }
            }
        }

        return (result.size() == adj.size()) ? result : vector<int>();
    }
    int maxColorValue = 0;
    void dfsBrute(int curr,vector<int> pathfreq,vector<vector<int>>& adj,string& colors){
        pathfreq[colors[curr] - 'a']++;
        maxColorValue = max(maxColorValue,pathfreq[colors[curr] - 'a']);
        for(int neigh : adj[curr]){
            dfsBrute(neigh,pathfreq,adj,colors);
        }
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);

        for(const auto& edge:edges){
            int from = edge[0];
            int to = edge[1];
            adj[from].push_back(to);
            indegree[to]++;
        }
        vector<int> graphOrder = topoSort(adj,indegree);
        if(graphOrder.empty()) return -1;
        
        for(int go : graphOrder){
            cout << go << "\t";
        }
        // for(int i=0;i<n;i++){
        //     if(indegree[i] == 0){
        //         dfsBrute(i,vector<int>(26,0),adj,colors);
        //     }
        // }
        vector<vector<int>>dp(n,vector<int>(26,0));
        for(int i=0;i<graphOrder.size();i++){
            int currNode = graphOrder[i];
            int currColor = colors[currNode] - 'a';
            dp[currNode][currColor]++;
            maxColorValue = max(maxColorValue,dp[currNode][currColor]);
            for(int neigh : adj[currNode]){
                for(int i=0;i<26;i++){
                    dp[neigh][i] = max(dp[neigh][i],dp[currNode][i]);
                }
            }
        }
        return maxColorValue;
    }
};