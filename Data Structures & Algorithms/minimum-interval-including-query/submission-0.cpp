class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        int q = queries.size();
        auto cmp = [](const vector<int>&a , const vector<int>& b){
            return a[0] < b[0];
        };
        sort(intervals.begin(),intervals.end(),cmp);
        vector<pair<int,int>> sortedQueries(q);
        for(int i=0;i<q;i++){
            sortedQueries[i] = {queries[i],i};
        }
        sort(sortedQueries.begin(),sortedQueries.end());
        auto cmpq = [](const pair<int,int>& a,const pair<int,int>& b){
            return a.first > b.first;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmpq)> pq(cmpq);
        vector<int> result(q,-1);
        int interval_index = 0;
        for(int i=0;i<q;i++){
            int query_val = sortedQueries[i].first;
            int original_index = sortedQueries[i].second;
            while(interval_index < n && intervals[interval_index][0] <= query_val){
                int left = intervals[interval_index][0];
                int right = intervals[interval_index][1];
                int length = right - left + 1;
                pq.push({length,right});
                interval_index++;
            }
            while(!pq.empty() && pq.top().second < query_val){
                pq.pop();
            }
            if(!pq.empty()){
                result[original_index] = pq.top().first;
            }
        }
        return result;
    }
};
