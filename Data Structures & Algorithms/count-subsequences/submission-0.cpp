class Solution {
public:
    int numDistinct(string s, string t) {
      if(t.size() > s.size()){
        return 0;
      }  
      int n = s.size();
      int m = t.size(); 

      vector<vector<unsigned long long>> dp (n+1,vector<unsigned long long>(m+1,0));
      for(int i=0;i<n+1;i++){
        dp[i][0] = 1;
      }
      for(int j=1;j<m+1;j++){
        dp[0][j] = 0;
      }
      for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(s[i-1]==t[j-1]){
                // int ans1 = dfs(i,j,s,t) + dfs(i,j-1,s,t);
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }else{
                // int ans2 = dfs(i,j-1,s,t);
                dp[i][j] = dp[i-1][j];
            }
        }
      }
      return dp[n][m];
    }
};
