class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        if(n==0) return 0;
        const int offset = 20000;
        vector<int> dp(40005,0);
        
        int maxLen = 0;
        for(int num : arr){
            int current = num + offset;
            int prev = current-difference;
            dp[current] = dp[prev] + 1;
        }
        for(int a : dp) maxLen = max(maxLen , a);
        return maxLen;
    }
};