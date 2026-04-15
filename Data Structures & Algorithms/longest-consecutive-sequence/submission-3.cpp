class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        if(nums.size() == 1){
            return 1;
        }
        sort(nums.begin(),nums.end());
        int ans = 1;
        int bestans = INT_MIN;
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1]){
                continue;
            }else if(nums[i] == nums[i-1] + 1){
                ans++;
            }else{
                bestans = max(ans, bestans);
                ans = 1;
            }
        }
        bestans = max(ans, bestans);
        return bestans;
    }
};
