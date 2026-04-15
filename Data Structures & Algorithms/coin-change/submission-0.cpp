class Solution{
public:
    int coinChange(vector<int>& coins,int amount){
        int INF = amount + 1;
        vector<int>dp(amount+1 , INF);

        dp[0] = 0;
        for(int i=1;i<amount+1;i++){
            for(int coin : coins){
                if(i - coin >= 0){
                    dp[i] = min(dp[i] , dp[i-coin]+1);
                }
            }
        }
        return dp[amount] == INF ? -1 : dp[amount];
    }
};