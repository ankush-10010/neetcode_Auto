class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        unordered_map<int,int> mp;
        auto cmp = [](const pair<int,int>& a,const pair<int,int>& b){
            return a.second > b.second; //freq, num
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)>pq(cmp);

        for(int num : nums){
            mp[num]++; // this gives us the freq of each 
        }
        for(auto const& [val,freq] : mp){
            pq.push({freq,val});
        }

        for(int i=0;i<nums.size();i++){
            auto it = pq.top();
            pq.pop();
            nums[i] = it.second;
            it.first--;
            if(it.first > 0){
                pq.push({it.first,it.second});
            }
        }
        return nums;
    }
};