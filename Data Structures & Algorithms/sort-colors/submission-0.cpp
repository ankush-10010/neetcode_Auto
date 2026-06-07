class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int,int> mp; // num , freq
        for(int num : nums){
            mp[num]++;
        }
        auto cmp = [](const pair<int,int> &a, const pair<int,int> &b){
            return a.second > b.second; //when its true it has lower prity
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp); // freq and the integer
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
        // return nums;
    }
};