class Solution {
public:
    bool solve(int i,int j,int scoreA,int scoreB,bool aturn,vector<int>& nums){
        if(i>j){
            return scoreA >= scoreB;
        }
        if(aturn){
            //updation in scoreA
            // scoreA += nums[i];
            aturn = !aturn;
            bool left = solve(i+1,j,scoreA+nums[i],scoreB,aturn,nums);
            bool right = solve(i,j-1,scoreA+nums[j],scoreB,aturn,nums);
            aturn = !aturn;
            return left || right;
        }else{
            //updation in scoraB
            aturn = !aturn;
            bool left = solve(i+1,j,scoreA,scoreB+nums[i],aturn,nums);
            bool right = solve(i,j-1,scoreA,scoreB+nums[j],aturn,nums);
            aturn = !aturn;
            return left && right;
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        return solve(0,nums.size()-1,0,0,true,nums);
    }
};