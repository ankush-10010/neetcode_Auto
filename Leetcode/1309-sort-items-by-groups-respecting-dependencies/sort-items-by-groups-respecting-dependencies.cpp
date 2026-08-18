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
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // sortring between groups and sorting inside groups
        // give groups[i]-->-1 their own groups
        // item graph U --> V
        // group graph group[U] --> group[V]
        int new_m = m;
        for(int i=0;i<n;i++){
            if(group[i] == -1){
                group[i] = new_m;
                new_m++;
            }
        }
        vector<vector<int>> itemGraph(n);
        vector<int> itemIndegree(n,0);

        vector<vector<int>> groupGraph(new_m);
        vector<int> groupIndegree(new_m,0);

        for(int curr=0;curr<n;curr++){
            for(int prev : beforeItems[curr]){
                // prev is the pre reqs for the ith element
                itemGraph[prev].push_back(curr);
                itemIndegree[curr]++;
                if(group[prev] != group[curr]){
                    int currGroup = group[curr];
                    int prevGroup = group[prev];
                    groupGraph[prevGroup].push_back(currGroup);
                    groupIndegree[currGroup]++;
                }
            }
        }

        vector<int> itemOrder = topoSort(itemGraph,itemIndegree);
        vector<int> groupOrder = topoSort(groupGraph,groupIndegree);

        vector<vector<int>> ordered_group(new_m);
        if(itemOrder.empty() || groupOrder.empty()){
            return {};
        }
        for(int item : itemOrder){
            ordered_group[group[item]].push_back(item);
        }

        vector<int> result;
        for(int groupIdx : groupOrder){
            for(int item : ordered_group[groupIdx]){
                result.push_back(item);
            }
        }

        return result;
    }
};