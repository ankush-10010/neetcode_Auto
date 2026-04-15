class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for(int num : nums){
            totalSum+=num;
        }
        if(abs(target) > totalSum){
            return 0;
        }
        if(((target + totalSum) % 2)!=0){
            return 0;
        }

        int positiveSum = (totalSum + target)/2;
        
        vector<vector<int>> dp(nums.size()+1,vector<int>(positiveSum+1,0));
        dp[0][0] = 1;
        // for(int i=0;i<target;i++){
        //     dp[0][i] = 0;
        // }
        for(int i=1;i<nums.size()+1;i++){
            for(int j=0;j<positiveSum+1;j++){
                int curr_num = nums[i-1];
                dp[i][j] = dp[i-1][j];
                if(j>=curr_num){
                    dp[i][j] += dp[i-1][j-curr_num];
                }
            }
        }
        return dp[nums.size()][positiveSum];
    }
};
