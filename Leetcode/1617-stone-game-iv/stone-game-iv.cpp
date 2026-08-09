class Solution {
public:
    vector<pair<int,int>> perfectSqr(int n){
        vector<pair<int,int>> pf;
        for(int i=1;i*i<=n;i++){
            pf.push_back({i*i,i});
        }
        return pf;
    }
    bool winnerSquareGame(int n) {
        vector<pair<int,int>> pf;
        pf = perfectSqr(n);
        vector<int> dp(n+1,false);
        dp[0] = false;
        dp[1] = true;
        for(int i=1;i<n+1;i++){
            //for this particular i take the closest sq 
            for(const auto p : pf){
                int sq = p.first;
                int number = p.second;
                int complement = i - sq;
                if(i-sq >= 0){
                    if(!dp[complement]){
                        dp[i] = !dp[complement] | dp[i];
                        break;
                    }
                }
            }
        }

        return dp[n];
    }
};