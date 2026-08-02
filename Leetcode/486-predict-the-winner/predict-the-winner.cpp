// class Solution {
//     unordered_map<string,bool>memo;
// public:
//     bool solve(int i,int j,int scoreA,bool aturn,vector<int>& nums){
//         if(i>j) return scoreA >= 0;
//         string key = to_string(i) + "," + to_string(j) + "," + to_string(scoreA)  + "," + to_string(aturn);
//         if(memo.find(key) != memo.end()) return memo[key];

//         bool result;
//         if(aturn){
//             //updation in scoreA
//             // scoreA += nums[i];
//             aturn = !aturn;
//             bool left = solve(i+1,j,scoreA+nums[i],aturn,nums);
//             bool right = solve(i,j-1,scoreA+nums[j],aturn,nums);
//             aturn = !aturn;
//             result = left || right;
//         }else{
//             //updation in scoraB
//             aturn = !aturn;
//             bool left = solve(i+1,j,scoreA-nums[i],aturn,nums);
//             bool right = solve(i,j-1,scoreA-nums[j],aturn,nums);
//             aturn = !aturn;
//             result = left && right;
//         }

//         return memo[key] = result;
//     }
//     bool predictTheWinner(vector<int>& nums) {
//         // memo[i][j][chanceA][currA][currB] --> MLE
//         // use unordered_map for this then 
//         return solve(0,nums.size()-1,0,true,nums);
//     }
// };


class Solution{
// pair<int,int> memo[25][25];
// vector<vector<bool>> visited(25,vector<bool>(25,false));
public:
    pair<int,int> solve(int i,int j,vector<int>& nums,vector<vector<bool>>& visited,vector<vector<pair<int,int>>>& memo){
        if(i>j) return {0,0};
        if(visited[i][j]) return memo[i][j];
        pair<int,int> leftResult = solve(i+1,j,nums,visited,memo);
        int myResult_left = nums[i] + leftResult.second;
        int oppResult_left = leftResult.first;
        pair<int,int> rightResult = solve(i,j-1,nums,visited,memo);
        int myResult_right = nums[j] + rightResult.second;
        int oppResult_right = rightResult.first;
        visited[i][j] = true;
        if(myResult_left > myResult_right){
            return memo[i][j] = {myResult_left,oppResult_left};
        }else{
            return memo[i][j] = {myResult_right,oppResult_right};
        }
    }
    bool predictTheWinner(vector<int>& nums){
        // memset(visited,false,sizeof(visited));
        vector<vector<pair<int,int>>> memo(25,vector<pair<int,int>>(25,{0,0}));
        vector<vector<bool>> visited(25,vector<bool>(25,false));
        pair<int,int> finalScore = solve(0,nums.size()-1,nums,visited,memo);
        int aliceScore = finalScore.first;
        int oppScore = finalScore.second;
        return aliceScore >= oppScore;
    }
};