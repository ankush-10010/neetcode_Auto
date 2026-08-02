class Solution {
    using vvi = vector<vector<int>>;
public:
    // void backtrack(int k,int n,int start,int currSum,vector<int>& current,vector<vector<int>>& result){
    //     if(currSum > n){
    //         return;
    //     }
    //     if(current.size() == k){
    //         if(currSum == n){
    //             result.push_back(current);
    //         }
    //     }
    //     for(int i=start;i<=9;i++){
    //         current.push_back(i);
    //         backtrack(k,n,i+1,currSum+i,current,result);
    //         current.pop_back();
    //     }
    // }
    vector<vector<int>> backtrack(int k_left,int n_left,int start,vector<vector<vector<vvi>>>& memo,vector<vector<vector<bool>>>& visited){
        if(k_left == 0 && n_left == 0) return {{}};
        if(k_left == 0 || n_left < 0 || start > 9) return {};

        if(visited[start][k_left][n_left]) return memo[start][k_left][n_left];

        vvi current_combinations;

        vvi skip = backtrack(k_left,n_left,start+1,memo,visited);
        for(auto& comb:skip){
            current_combinations.push_back(comb);
        }
        vvi take = backtrack(k_left-1,n_left-start,start+1,memo,visited);
        for(auto& comb:take){
            comb.push_back(start);
            current_combinations.push_back(comb);
        }
        visited[start][k_left][n_left] = true;
        return memo[start][k_left][n_left] = current_combinations;

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        // vector<vector<int>>result;
        // vector<int>current;
        // backtrack(k,n,1,0,current,result);
        // return result;
        vector<vector<vector<bool>>> visited(11,vector<vector<bool>>(11,vector<bool>(65,false)));
        vector<vector<vector<vvi>>> memo(11,vector<vector<vvi>>(11,vector<vvi>(65)));
        return backtrack(k,n,1,memo,visited);
    }
};