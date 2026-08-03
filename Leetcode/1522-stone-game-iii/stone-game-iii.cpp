class Solution {
    // unordered_map<int,int> memo[50010][2];
public:
    int dfs(int i ,bool chanceA,vector<int>& stoneValue,vector<vector<int>>& memo){
        if(i>=stoneValue.size()){
            return 0;
        }
        // return the diff value from this function --> memo
        if(memo[i][chanceA] != -1e9) return memo[i][chanceA];
        if(chanceA){
            int bestforAlice = -1e9;
            // has three options --> t1,t2,t3
            if(i < stoneValue.size()){
                int t1 = stoneValue[i] + dfs(i+1,!chanceA,stoneValue,memo);
                bestforAlice = max(bestforAlice,t1);
            }
            if(i+1 < stoneValue.size()){
                int t2 = stoneValue[i]+stoneValue[i+1] + dfs(i+2,!chanceA,stoneValue,memo);
                bestforAlice = max(bestforAlice,t2);
            }
            if(i+2 < stoneValue.size()){
                int t3 = stoneValue[i]+stoneValue[i+1]+stoneValue[i+2] + dfs(i+3,!chanceA,stoneValue,memo);
                bestforAlice = max(bestforAlice,t3);
            }

            return memo[i][chanceA] = bestforAlice;
        }else{
            int bestforBob = 1e9;
            if(i < stoneValue.size()){
                int t1 = - (stoneValue[i]) + dfs(i+1,!chanceA,stoneValue,memo);
                bestforBob = min(bestforBob,t1);
            }
            if(i+1 < stoneValue.size()){
                int t2 = -(stoneValue[i]+stoneValue[i+1]) + dfs(i+2,!chanceA,stoneValue,memo);
                bestforBob = min(bestforBob,t2);
            }
            if(i+2 < stoneValue.size()){
                int t3 = -(stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]) + dfs(i+3,!chanceA,stoneValue,memo);
                bestforBob = min(bestforBob,t3);
            }

            return memo[i][chanceA]=bestforBob;
        }

        
    }
    string stoneGameIII(vector<int>& stoneValue) {
        // i , chanceA , <t1,t2,t3>
        // vector<vector<vector<int>>> memo()
        vector<vector<int>> memo(stoneValue.size(),vector<int>(2,-1e9));
        int score = dfs(0,true,stoneValue,memo);
        if(score == 0) return "Tie";
        return score > 0 ? "Alice" : "Bob";
    }
};

// dp[][] --> i , chanceA 
// dp[i][chanceA] --> diff