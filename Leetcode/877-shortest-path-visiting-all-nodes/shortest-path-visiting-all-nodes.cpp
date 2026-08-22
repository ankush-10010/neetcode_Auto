class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n == 1) return 0;
        queue<pair<int,pair<int,int>>> q;
        vector<vector<bool>> visited(n,vector<bool>(1<<n,false));

        for(int i=0;i<n;i++){
            int currMask = (1<<i);
            q.push({i,{currMask,0}});
            visited[i][currMask] = true;
        }

        int completedMask = (1<<n) - 1;
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int Currnode = top.first;
            int CurrMask = top.second.first;
            int CurrDist = top.second.second;

            if(CurrMask == completedMask){
                return CurrDist;
            }

            for(int neigh : graph[Currnode]){
                if(!visited[neigh][CurrMask]){
                    visited[neigh][CurrMask] = true;
                    int neighMask = CurrMask | (1<<neigh);
                    q.push({neigh,{neighMask,CurrDist+1}});
                }
            }
        }

        return 0;
    }
};