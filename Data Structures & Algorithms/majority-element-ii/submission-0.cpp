class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int k = n/3;
        unordered_map<int,int>mp;
        vector<int> r;
        for(int num : nums){
            mp[num]++;
        }
        sort(nums.begin(),nums.end());
        int fe = nums[0];
        if(mp[fe] > k){
            r.push_back(fe);
        }
        
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1]){
                continue;
            }
            int n = nums[i];
            if(mp[n] > k){
                r.push_back(n);
            }
        }
        return r;
    }
};