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
            current.push_back(nums[index]);
            // curr_target = curr_target - nums[index];
            dfs(nums , curr_target - nums[index],current,index);
            // curr_target += nums[index];
            current.pop_back();

            dfs(nums, curr_target , current , index+1);

        }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> current;
        dfs(nums , target ,current , 0);
        return result;
    }
};
