class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n == 1) return 0;
        queue<tuple<int,int,int>> q;
        vector<vector<bool>> visited(n,vector<bool>(1<<n,false));

        for(int i=0;i<n;i++){
            int currMask = (1<<i);
            q.push({i,currMask,0});
            visited[i][currMask] = true;
        }

        int lastState = (1<<n) - 1;
        while(!q.empty()){
            auto [currNode,currMask,currDist] = q.front();
            q.pop();

            if(currMask == lastState) return currDist;

            for(int neigh : graph[currNode]){
                if(!visited[neigh][currMask]){
                    visited[neigh][currMask] = true;
                    int neighMask = currMask | (1<<neigh);
                    q.push({neigh,neighMask,currDist+1});
                }
            }
        }
        return 0;
    }
};