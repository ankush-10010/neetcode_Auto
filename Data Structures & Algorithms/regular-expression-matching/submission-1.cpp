class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[0][0] = true;
        for(int i=1;i<n+1;i++){
            dp[i][0]=false;
        }
        if(p[0] == '*'){
            dp[0][1] = true;
        }
        for(int j=2;j<m+1;j++){
            if(p[j-1] == '*'){
                dp[0][j] = dp[0][j-2];
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                char s_char = s[i-1];
                char p_char = p[j-1];
                if(s_char == p_char){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    if(p_char == '*'){
                        if(s[i-1] == p[j-2] || p[j-2] == '.'){
                            dp[i][j] = dp[i][j-2] || dp[i-1][j];
                        }else{
                            dp[i][j] = dp[i][j-2];
                        }
                    }else if(p_char == '.'){
                        dp[i][j] = dp[i-1][j-1];
                    }else{
                        dp[i][j] = false;
                    }
                }
            }
        }
        return dp[n][m];
    }
};
