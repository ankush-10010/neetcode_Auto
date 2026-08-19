class Solution {
public:
    vector<int> topoSort(vector<vector<int>>& adj,vector<int>& indegree,vector<int>& maxTime,vector<int>& time){
        vector<int> result;
        queue<int>  q;
        for(int i=1;i<indegree.size();i++){
            if(indegree[i] == 0){
                maxTime[i] = time[i-1];
                q.push(i);
            }
        }

        while(!q.empty()){
            int top = q.front();
            q.pop();
            // maxTime[top] = max(maxTime[top],)
            result.push_back(top);
            for(int neigh : adj[top]){
                maxTime[neigh] = max(maxTime[neigh],time[neigh-1] + maxTime[top]);
                indegree[neigh]--;
                if(indegree[neigh] == 0){
                    q.push(neigh);
                }
            }
        }
        return (result.size() == adj.size()-1) ? result : vector<int>();
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n+1);
        vector<int> indegree(n+1,0);
        vector<int> maxTime(n+1,0);
        cout << format("time.size()-->{}",time.size())<<endl;
        // for(int i =0;i<time.size();i++){
        //     maxTime[i] = time[i-1];
        // }
        for(auto &relation: relations){
            int from = relation[0];
            int to = relation[1];
            adj[from].push_back(to);
            indegree[to]++;
        }
        vector<int> graphOrder = topoSort(adj,indegree,maxTime,time);
        int ans =0;

        for(int mT: maxTime){
            ans = max(ans,mT);
            cout << mT << "\t";
        }
        cout << endl;

        return ans;
    }
};