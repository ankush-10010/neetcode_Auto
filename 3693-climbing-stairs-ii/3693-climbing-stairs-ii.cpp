class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1,INT_MAX/2);
        dp[0] = 0;
        if(n==0) return 0;
        dp[1] = min(dp[1],dp[0]+ costs[0] + 1*1);
        if(n==1) return dp[1];
        dp[2] = min({dp[2],dp[0] +costs[1] + 2*2,dp[1] + costs[1] + 1*1});
        if(n==2){
            return dp[2];
        }
        dp[3] = min({dp[3],dp[0] + costs[2] + 9,dp[1] + costs[2] + 4 , dp[2] + costs[2] + 1});
        if(n == 3){
            return dp[3];
        }
        
        // dp[2] = min({dp[2],dp[0] +costs[1] + 2*2,dp[1] + costs[1] + 1*1});
        
        
         
        for(int i=4;i<dp.size();i++){
            dp[i] = min({dp[i], dp[i-1] + costs[i-1] + 1, 
                                dp[i-2] + costs[i-1] + 4,
                                dp[i-3] + costs[i-1] + 9});
        }

        // for(int i=0;i<dp.size();i++){
        //     cout << format("dp[{}] --> {}",i,dp[i]) << endl;
        // }

        return dp[n];
    }
};