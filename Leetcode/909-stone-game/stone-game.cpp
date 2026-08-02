class Solution {
public:
    int solve(int i,int j,vector<int>& piles,vector<vector<int>>& memo){
        if(i>j) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        int left = piles[i] - solve(i+1,j,piles,memo);
        int right = piles[j] - solve(i,j-1,piles,memo);

        return memo[i][j] = max(left,right);
    }
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> memo(piles.size(),vector<int>(piles.size(),-1));
        return solve(0,piles.size()-1,piles,memo)>0;
    }
};