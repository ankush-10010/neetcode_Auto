class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        if(s3.size() != n+m){
            return false;
        }
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[0][0] = true;
        for(int i=1;i<n+1;i++){
            if(s1[i-1] == s3[i-1]){
                dp[i][0] = dp[i-1][0];
            }else{
                dp[i][0] = false;
            }
        }
        for(int j=1;j<m+1;j++){
            if(s2[j-1] == s3[j-1]){
                dp[0][j] = dp[0][j-1];
            }else{
                dp[0][j] = false;
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                // string checking logic is missing
                if(s1[i-1] == s3[i+j-1]){
                    dp[i][j] = dp[i-1][j];
                }
                else if(s2[j-1] == s3[i+j-1]){
                    dp[i][j] = dp[i][j-1];
                }else{
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};
