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

    void topoSort(int src , vector<bool> &vis, stack<int>& s, vector<vector<int>>& graph){
        vis[src]=true;

        for(int i=0;i<graph.size();i++){
            int u= graph[i][1];
            int v= graph[i][0];
            if(u==src){
                if(!vis[v]){
                    topoSort(v,vis,s,graph);
                }
            }
        }
        s.push(src);
    }
    vector<int> findOrder(int numCourses,vector<vector<int>>& graph){
        int V= numCourses;
        /* basically the question is about if there is a valid sequence
        such that this graph can have to satisfy all the sequence 
        and that is what we do in the topological order problems */
        // topological sorting can only be for directed graph
        vector<bool> vis(V,false);
        vector<bool> rec(V,false);
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(!vis[V]){
                if(isCycle(i, vis , rec,graph)){
                    return ans;
                }
            }
        }
        // calculated ans array . perform topoSorting
        vector<bool> vis2(V,false);
        stack<int> s;
        for(int i=0;i<V;i++){
            if(!vis2[i]){
                topoSort(i,vis2,s, graph);
            }
        }
        while(s.size()>0){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};