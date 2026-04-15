class Solution {
public:
    vector<vector<int>> result;
    void dfs(vector<int>& nums, int curr_target, vector<int> &current, int index){
            if(curr_target == 0){
                result.push_back(current);
                return;
            }
            if(curr_target < 0 || index>=nums.size()){
                return;
            }
            for(int i=index;i<nums.size();i++){
                if(i>index && nums[i]==nums[i-1]){
                    continue;
                }
                
                current.push_back(nums[i]);
                dfs(nums , curr_target - nums[i],current,i+1);
                current.pop_back();
                // dfs(nums, curr_target , current , index+1);
            }
            

        }
    vector<vector<int>> combinationSum2(vector<int>& candidates , int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> current;
        dfs(candidates, target , current , 0);
        return result;
    }
};
