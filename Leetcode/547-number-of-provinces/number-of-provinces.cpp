class Solution {
public:
    void dfs(int city,vector<vector<int>>& isConnected,vector<bool>& visited){
        visited[city] = true;
        int size = isConnected[city].size();
        for(int neigh=0;neigh<size;neigh++){
            if(isConnected[city][neigh] == 1 && !visited[neigh]){
                dfs(neigh,isConnected,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int rows = isConnected.size();
        int cols = isConnected[0].size();
        // we made a graph 
        vector<bool> visited(rows,false);

        int provinces = 0;
        for(int i=0;i<rows;i++){
            if(!visited[i]){
                provinces++;
                dfs(i,isConnected,visited);
            }
        }

        return provinces;
    }
};