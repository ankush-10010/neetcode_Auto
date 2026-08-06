class Solution {
public:
    // int backtrack(int i,int j,bool buy,int profit,int bought,int fee,vector<int>& prices){
    //     if(buy){
    //         bought = backtrack(i+1,j,!buy,profit,prices[i],fee,prices);
    //     }
    // }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i=1;i<prices.size();i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i-1][1],dp[i-1][0] - prices[i]);
        }
        int n = prices.size();
        return dp[n-1][0];
        // return max(dp[n-1][0],dp[n-1][1]);
    }
};