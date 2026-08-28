class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,1);
        dp[0] = 0;
        for(int i=2;i<=n;i++){
            cout << "debug for i --> " << i << endl;
            int maxTillnow = 1;
            for(int j=0;j<i;j++){
                // cout << "debug for i --> "<< i << "debug for j--> " << j<< endl;
                // cout << format("i-j-->{}  dp[j]-->{}",i-j,dp[j])<<endl;
                // cout << format("dp[i-j]-->{}  dp[j]-->{}",i-j,j)<<endl;
                // cout << format("i-j -->{}  j-->{}",i-j,j)<<endl;
                maxTillnow = max({maxTillnow,(i-j)*dp[j],dp[i-j]*dp[j],(i-j)*j});
                // cout << format("maxTillnow --> {}",maxTillnow);
            }
            dp[i] = max(dp[i],maxTillnow);
            // cout << format("dp[i] --> {}" , dp[i]);
        }
        return dp[n];
    }
};