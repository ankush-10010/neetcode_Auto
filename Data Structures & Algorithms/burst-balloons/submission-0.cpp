class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> newNum(nums.size()+2,1);
        for(int i=0;i<nums.size();i++){
            newNum[i+1]=nums[i];
        }
        int m = newNum.size();
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        // dp[0][0] = nums[0];
        for(int i=n;i>=0;i--){
            for(int j=1+1;j<n+2;j++){
                for(int k=i+1;k<j;k++){
                    int left_subproblem = dp[i][k];
                    int right_subproblem = dp[k][j];
                    int coins_for_k = newNum[i]*newNum[k]*newNum[j];

                    dp[i][j] = max(dp[i][j],left_subproblem+right_subproblem+coins_for_k);
                }
            }
        }
        return dp[0][n+1];
    }
};
// can make a dp matrix of size nums.size()+1*nums.size()+1 
// the dp[i][j] represents the current size of the matrix (j) , the starting size of matrix (i)
