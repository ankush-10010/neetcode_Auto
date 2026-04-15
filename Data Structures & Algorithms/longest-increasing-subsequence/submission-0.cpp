class Solution {
public:
    int lengthOfLIS(vector<int> arr){
        unordered_set<int> s(arr.begin(),arr.end()); //unique

        vector<int> arr2(s.begin(),s.end());
        sort(arr2.begin(),arr2.end()); //ascending

        int n = arr.size();
        int m = arr2.size();   
        int ans =0; 
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(arr[i-1] == arr2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        return dp[n][m];

    }
};
