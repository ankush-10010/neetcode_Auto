class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // we have to know if we can divide nums such that we have two subsets
        // such that sum of all elements in sub1 == sum of all elements in sub2

        // if that is possible then return true otherwise false
        vector<bool> dp (nums.size()+1,false);
        dp[0] = true;

        // dp[2] = if nums[0] = nums[1] then true , how do i turn this into code
        // for each number in nums we decide to take it or not take it
        int totalSum = 0;
        for(int x:nums){
            totalSum += x;
        }

        if(totalSum % 2 != 0){
            return false;
        }

        int target = totalSum/2;

        for(int num : nums){
            for(int s = target; s>=num;s--){
                dp[s] = dp[s] || dp[s-num];
            }
        }
        return dp[target];
    }
};
