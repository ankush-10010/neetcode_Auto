class Solution{
public:
    bool isCycle(int src, vector<bool> &vis, vector<bool>& rec, vector<vector<int>>& graph){
        vis[src]=true;
        rec[src]=true;
        for(int i=0;i<graph.size();i++){
            int u= graph[i][1];
            int v= graph[i][0];

            if(u==src){ 
                if(!vis[v]){
                    if(isCycle(v,vis,rec,graph)){
                        return true;
                    }
                }else{
                    if(rec[v]){
                        return true;
                    }
                }
            }
        }
        rec[src]=false;
        return false;
    }
    bool canFinish(int numCourses , vector<vector<int>>& prerequisites){
        int V=numCourses;
        /* basically the question is about if there is a valid sequence
        such that this graph can have to satisfy all the sequence 
        and that is what we do in the topological order problems */
        // topological sorting can only be for directed graph
        vector<bool> vis(V,false);
        vector<bool> rec(V,false);
        for(int i=0;i<V;i++){
            if(!vis[V]){
                if(isCycle(i, vis , rec,prerequisites)){
                    return false;
                }
            }
        }
        return true;
    }
};