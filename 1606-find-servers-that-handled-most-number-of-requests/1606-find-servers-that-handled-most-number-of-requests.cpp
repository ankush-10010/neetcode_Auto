class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        // priority_queue<int,vector<int>,greater<int>> freeServers;
        set<int> freeServers;
        // if free servers is empty then drop the request
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> busyServers; // time , serverID
        // if ith is busy then assign to i+1th
        vector<int> numberOfHandles(k,0);
        for(int i=0;i<k;i++){
            freeServers.insert(i);
        }
        int currTime = 0;
        for(int i=0;i<arrival.size();i++){
            currTime = arrival[i];
            
            while(!busyServers.empty() && currTime >= busyServers.top().first){
                auto top = busyServers.top();
                int ServerIndex = top.second;
                busyServers.pop();
                freeServers.insert(ServerIndex);
            }
            if(freeServers.empty()){
                continue;
            }
            int arrivalTime = arrival[i];
            int loadTime = load[i];
            
            auto it = freeServers.lower_bound(i%k);
            int workingServer;
            if(it == freeServers.end()){
                workingServer = *freeServers.begin();
            }else{
                workingServer = *it;
            }
            numberOfHandles[workingServer]++;
            freeServers.erase(workingServer);
            busyServers.push({currTime + load[i], workingServer});
        }
        vector<int> result;
        vector<pair<int,int>> pairs(numberOfHandles.size());
        for(int i=0;i<numberOfHandles.size();i++){
            pairs[i] = {numberOfHandles[i],i};
        }
        sort(pairs.begin(),pairs.end(),greater<pair<int,int>>());
        int max_p = pairs[0].first;
        for(auto p : pairs){
            if(p.first == max_p){
                result.push_back(p.second);
            }else{
                continue;
            }
        }

        return result;
    }
};