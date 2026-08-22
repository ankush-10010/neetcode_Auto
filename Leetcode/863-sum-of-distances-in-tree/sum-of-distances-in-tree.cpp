class Solution {
public:
    vector<vector<int>> graph;
    vector<int> ans;
    vector<int> count;
    int total_nodes;
    void dfs1(int node,int parent){
        for(int child : graph[node]){
            if(child == parent) continue;
            dfs1(child,node);
            count[node] += count[child];
            ans[node] += (count[child] + ans[child]);
        }
        
    }
    void dfs2(int node,int parent){
        for(int child:graph[node]){
            if(child == parent) continue;
            ans[child] = ans[node] - 2*count[child] + total_nodes;
            dfs2(child,node);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        graph.assign(n,vector<int>());
        ans.assign(n,0);
        count.assign(n,1);
        total_nodes = n;
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs1(0,-1);
        dfs2(0,-1);
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> graph(n);
        
//         for(auto& edge :edges){
//             int u = edge[0];
//             int v = edge[1];

//             graph[u].push_back(v);
//             graph[v].push_back(u);
//         }
//         vector<tuple<int,int,int>> dist; // i , j , dist
//         vector<vector<int>> dp(n,vector<int>(n,-1));
//         // dp --> acts as visited array dp[][] != -1 
//         queue<tuple<int,int,int>> q; // node , dist
//         for(int i=0;i<n;i++){
//             q.push({i,i,0});
//             dp[i][i] = 0;
//         }
//         while(!q.empty()){
//             auto [src,currNode,dist] = q.front();
//             q.pop();

//             for(int neigh : graph[currNode]){
//                 if(dp[src][neigh] == -1){ // unvisited 
//                     dp[src][neigh] = dist+1;
//                     q.push({src,neigh,dist+1});
//                 }
//             }
//         }

//         vector<int> answer(n,-1);
//         for(int i=0;i<n;i++){
//             int ans = 0;
//             for(int a : dp[i]){
//                 ans += a;
//             }
//             answer[i] = ans;
//         }

//         for(int ans : answer){
//             cout << ans << "\t";
//         }
//         cout << endl;
//         return answer;
//     }
// };