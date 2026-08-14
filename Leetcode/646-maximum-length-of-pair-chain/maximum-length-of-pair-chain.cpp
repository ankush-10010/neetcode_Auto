class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        auto cmp = [](const vector<int>& a,const vector<int>& b){
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        };

        sort(pairs.begin(),pairs.end(),cmp);
        vector<int> dp(pairs.size(),1);
        for(int i=1;i<pairs.size();i++){
            for(int j=0;j<i;j++){
                if(pairs[i][0] > pairs[j][1]){
                    dp[i] = max(dp[i],dp[j] + 1);
                }
            }
        }
        int maxLen = INT_MIN;
        for(int d:dp) maxLen = max(maxLen,d);

        return maxLen;
    }
};