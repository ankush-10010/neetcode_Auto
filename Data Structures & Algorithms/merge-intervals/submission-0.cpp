class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       if(intervals.empty()){
        return {};
       }
       int i=0;
       int n=intervals.size();
       sort(intervals.begin(),intervals.end());
        vector<vector<int>> results;
        results.push_back(intervals[0]);
        
        for(int i=1;i<intervals.size();i++){
            auto& last = results.back();
            auto& curr = intervals[i];
            if(last[1] >= curr[0]){
                //there is overlap
                last[0] = min(last[0],curr[0]);
                last[1] = max(last[1],curr[1]);
            }else{
                results.push_back(curr);
            }
        }
        // if intervals[i].end > intervals[i+1].start then 
        // there is overlapping
        return results;
    }
};
