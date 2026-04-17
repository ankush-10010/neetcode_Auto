class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        // here dp[i][j] is availaible (the leftmost index-->i , rightmost index-->j)
        // then what is the sum 
        dp[0][0] = 0;
        dp[0][1] = max(piles[0],piles[1]);
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n;j++){
                // if alice choose i --> then bob turn i+1,j otherwise i,j-1
                dp[i][j] = max(piles[i] - dp[i+1][j],piles[j] - dp[i][j-1]);
            }
        }
        return dp[0][n-1];

    }
};