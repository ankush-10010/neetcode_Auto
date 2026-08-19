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
            q.pop();
            result.push_back(top);
            for(int neigh : adj[top]){
                indegree[neigh]--;
                if(indegree[neigh] == 0){
                    q.push(neigh);
                }
            }
        }

        return (result.size() == adj.size()) ? result : vector<int>();
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto prereq : prerequisites){
            int from = prereq[0];
            int to = prereq[1];
            adj[from].push_back(to);
            indegree[to]++;
        }
        vector<int> orderGraph = topoSort(adj,indegree);
        for(int og : orderGraph){
            cout << og << "\t";
        }
        vector<vector<bool>> isPrereq(numCourses,vector<bool>(numCourses,false));
        for(int curr : orderGraph){
            for(int neigh : adj[curr]){
                isPrereq[curr][neigh] = true;
                for(int i=0;i<numCourses;i++){
                    if(isPrereq[i][curr]){
                        isPrereq[i][neigh] = true;
                    }
                }
            }
        }

        cout << endl;
        vector<bool> result1(queries.size(),false);
        for(int i=0;i<queries.size();i++){
            int u = queries[i][0];
            int v = queries[i][1];
            result1[i] = isPrereq[u][v];
        }
        return result1;
    }
};