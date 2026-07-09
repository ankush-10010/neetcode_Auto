class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);
        for(int i=0;i<times.size();i++){
            int u = times[i][0];
            int v = times[i][1];
            int time = times[i][2];
            graph[u].push_back({v, time});
        }
        auto cmp = [](const pair<int,int>& a,const pair<int,int>& b){
            return a.second > b.second; //{node,time} , min heap
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
        vector<bool> visited(n+1,false);
        int wet_node_count = 0;
        pq.push({k,0});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int current_node = it.first;
            int current_time = it.second;
            if(visited[current_node]){
                continue;
            }
            visited[current_node] = true;
            wet_node_count++;
            if(wet_node_count == n){
                return current_time;
            }
            for(auto& neigh : graph[current_node]){
                int u = neigh.first;
                int weight = neigh.second;
                int new_time = current_time + weight;
                pq.push({u,new_time});
            }
        }

        return -1;
    }
};
