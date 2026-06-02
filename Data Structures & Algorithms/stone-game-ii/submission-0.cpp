class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        vector<int> suffixSum(n+1,0);
        for(int i=n-1;i>=0;i--){
            suffixSum[i] = suffixSum[i+1] + piles[i];
        }
        
        for(int i=n-1;i>=0;i--){
            for(int m=1;m<=n;m++){
                if(i+2*m >= n){
                    dp[i][m] = suffixSum[i];
                }else{
                    int maxStones = 0;
                    for(int x=1;x<=2*m;x++){
                        int nextM = max(x,m);
                        int bobsbestFuture = dp[i+x][nextM];
                        int aliceScore = suffixSum[i] - bobsbestFuture;
                        maxStones = max(maxStones,aliceScore);
                    }
                    dp[i][m] = maxStones;
                }

            }
        }
        return dp[0][1];
    }
};