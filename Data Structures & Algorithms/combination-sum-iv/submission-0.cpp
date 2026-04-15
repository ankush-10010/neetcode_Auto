class Solution {
public:

    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target+1,0);
        // dp[i] will represent number of ways to make the target till index i
        // dp[i] = dp[i-1] + trying to build the target using this current element
        dp[0] = 1;
        for(int i=1;i<target+1;i++){
            for(int num : nums){
                if(num <= i){
                    dp[i] += dp[i-num];
                }
            }
        }
        return dp[target];
    }
};