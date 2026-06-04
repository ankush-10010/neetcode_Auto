class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        vector<vector<int>> augmentedTasks;
        for(int i=0;i<tasks.size();i++){
            augmentedTasks.push_back({tasks[i][0],tasks[i][1],i});
            // {enqueueTime,processingTime,index}
        }

        sort(augmentedTasks.begin(),augmentedTasks.end()); 
        //sorting this by enqueue time
        auto cmp = [](pair<int,int> a,pair<int,int> b){
            if(a.first != b.first){
                return a.first > b.first;
            }
            return a.second>b.second;
            // means if a > b then return true --> a has lower priority
        };
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);

        vector<int> result;
        long long currentTime = 0;
        long taskIndex = 0;
        while(taskIndex < n || !pq.empty()){

            if(pq.empty() && currentTime < augmentedTasks[taskIndex][0]){
                currentTime = augmentedTasks[taskIndex][0];
            }

            while(taskIndex < n && augmentedTasks[taskIndex][0] <= currentTime){
                pq.push({augmentedTasks[taskIndex][1],augmentedTasks[taskIndex][2]});
                taskIndex++;
            }

            auto [procTime,originalIndex] = pq.top();
            pq.pop();

            result.push_back(originalIndex);
            currentTime += procTime;
        }

        return result;
    }
};