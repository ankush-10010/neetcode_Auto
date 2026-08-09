class Solution {
public:
    int AliceScore(int i,int j,vector<int>& stoneValue,vector<int>& sum_in,vector<vector<int>>& memo){
        if(i>=j) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        
        int max_score = 0;
        for(int k=i;k<j;k++){
            int leftSum = sum_in[i] - sum_in[k+1];
            int rightSum = sum_in[k+1] - (j+1 < stoneValue.size() ? sum_in[j+1] : 0);
            if(leftSum < rightSum){
                // aliceScore(i,mid-1)mn
                max_score = max(max_score,leftSum + AliceScore(i,k,stoneValue,sum_in,memo));
            }else if(leftSum > rightSum){
                // aliceScore(mid,right)
                max_score = max(max_score,rightSum + AliceScore(k+1,j,stoneValue,sum_in,memo));
            }else{
                int takeLeft = leftSum + AliceScore(i, k, stoneValue, sum_in, memo);
                int takeRight = rightSum + AliceScore(k + 1, j, stoneValue, sum_in, memo);
                max_score = max({max_score,takeLeft,takeRight});
            }
        }
        return memo[i][j] = max_score;
    }
    int stoneGameV(vector<int>& stoneValue) {
        vector<int> sum_in(stoneValue.size(),0);
        int n = stoneValue.size();
        sum_in[n-1] = stoneValue[n-1];
        for(int i=n-2;i>=0;i--){
            sum_in[i] = sum_in[i+1] + stoneValue[i];
        }
        vector<vector<int>> memo(n,vector<int>(n,-1));

        return AliceScore(0,n-1,stoneValue,sum_in,memo);
    }
};