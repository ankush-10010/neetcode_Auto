class Solution {
public:
    void backtrack(int k,int n,int start,int currSum,vector<int>& current,vector<vector<int>>& result){
        if(currSum > n){
            return;
        }
        if(current.size() == k){
            if(currSum == n){
                result.push_back(current);
            }
        }
        for(int i=start;i<=9;i++){
            current.push_back(i);
            backtrack(k,n,i+1,currSum+i,current,result);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>result;
        vector<int>current;
        backtrack(k,n,1,0,current,result);
        return result;
    }
};