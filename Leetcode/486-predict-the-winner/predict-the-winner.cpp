class Solution {
public:
    int solve(int i,int j,vector<int>& nums,vector<vector<int>>& memo){
        if(i>j) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        int left = nums[i] - solve(i+1,j,nums,memo); 
        int right = nums[j] - solve(i,j-1,nums,memo);
        return memo[i][j] = max(left,right); 
    }
    bool predictTheWinner(vector<int>& nums) {
        vector<vector<int>> memo(nums.size(),vector<int>(nums.size(),-1));
        return solve(0,nums.size()-1,nums,memo)>=0;
    }
};