class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> visited(graph.size(),-1);
        // if(color-->parnt == color-->child retrn false)
        // (0-->c1, 1-->c2) 
        queue<pair<int,int>> q;
        // q.push({0,0});
        for(int i=0;i<graph.size();i++){
            if(visited[i] == -1){
                q.push({i,0});
            }
            while(!q.empty()){
                int levelSize = q.size();
                auto it = q.front();
                q.pop();
                int currColor = it.second;
                int currNode = it.first;
                int nextColor = (currColor == 1) ? 0 : 1; 
                for(int neigh : graph[currNode]){
                    if(visited[neigh] != -1){
                        if(visited[neigh] == currColor) return false;
                    }else{
                        // visited[neigh] == -1 --> non visited
                        visited[neigh] = nextColor;
                        q.push({neigh,nextColor});
                    }
                }
            }
        }
        

        return true;
    }
};