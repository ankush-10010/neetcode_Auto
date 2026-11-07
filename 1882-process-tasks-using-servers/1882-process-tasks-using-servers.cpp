class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        vector<int> result(tasks.size());
        // queue<int> q;
        // q.push(tasks[0]);
        
        long long currTime = 0;
        // server ID , availaible or not , when will it availaible
        auto cmp_pq = [](const pair<int,int>& a,const pair<int,int>& b){
            if(a.first == b.first){
                return a.second > b.second;
            }
            return a.first > b.first;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp_pq)> freeServers; // weight , index
        for(int i=0;i<servers.size();i++){
            freeServers.push({servers[i],i});
        }
        priority_queue<tuple<long long,int,int>,vector<tuple<long long,int,int>>,greater<tuple<long long,int,int>>> busyServers; // ct , weight , index
        for(int i=0;i<tasks.size();i++){
            currTime = max(currTime, (long long)i); 
            if (freeServers.empty()) {
                currTime = max(currTime, get<0>(busyServers.top()));
            }
            while (!busyServers.empty() && get<0>(busyServers.top()) <= currTime) {
                auto busy_top = busyServers.top();
                busyServers.pop();
                
                int busy_weight = get<1>(busy_top);
                int busy_index = get<2>(busy_top);
                
                freeServers.push({busy_weight, busy_index});
            }
            if(!freeServers.empty()){
                auto free_server = freeServers.top();
                int weight_free = free_server.first;
                int index_free = free_server.second;

                int currentTaskTime = tasks[i];
                long long currentCompletionTime = currTime + currentTaskTime;
                result[i] = index_free;
                freeServers.pop();
                busyServers.push({currentCompletionTime,weight_free,index_free});
            }
            // currTime = max(currTime,(long long)i);
        }
        return result;
    }
};