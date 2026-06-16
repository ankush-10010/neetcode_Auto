class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //sorted integer array , two integers 
        // k closest to x
        auto cmp=[](const pair<int,int>& a,const pair<int,int>& b){
            if (a.second == b.second) {
                return a.first < b.first; 
            }
            return a.second < b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)>pq(cmp);
        for(int i=0;i<arr.size();i++){
            int as = abs(arr[i] - x);
            pq.push({arr[i],as});
            if(pq.size() > k){
                pq.pop();
            }    
        }
        vector<int> r;
        
        while(!pq.empty()){
            r.push_back(pq.top().first);
            pq.pop();
        }
        sort(r.begin(),r.end());
        return r;
    }
};