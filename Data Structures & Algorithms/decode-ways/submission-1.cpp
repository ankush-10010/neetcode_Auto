class Solution {
public:
    int numDecodings(string s) {
        /* 
        we will create a dp vector 
        where dp[i] = number of ways to decode the string of i length
        so dp[0] = 0 
        now for dp[i] we will check if the i-1th element from the string 
        and ith element are taken as combined element or not
        so first if they are taken as combined then dp[i]= dp[i-1](combined contribution)
        if they are not taken as combined then dp[i] = dp[i-1]+1 (not combined cnotribution)
        we will add them up
        but what about the edge case if string[i-1] is 0
        from what i have learnt there should not be any exception while 
        building the dp matrix so we cant just add statements like if(string[i-1] == '0')
        then do this or do that
        */
        int n = s.size();
        if(n==0 || s[0]=='0'){
            return 0;
        }
        vector<int>dp(s.size()+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<n+1;i++){
            if(s[i-1] != '0'){
                dp[i] += dp[i-1];
            }
            int twoDigits = stoi(s.substr(i-2,2));
            if(twoDigits>=10 && twoDigits<=26){
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};
