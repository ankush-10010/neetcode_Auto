class Solution {
public:
    vector<vector<int>> result;
    
    void dfs(int index , vector<int> &nums, vector<int>& current){
        if(index==nums.size()){
            result.push_back(current);
            return;
        }

        current.push_back(nums[index]);
        dfs(index+1 , nums, current);
        current.pop_back();

        dfs(index+1, nums,current);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        dfs(0,nums,current);
        return result;
    }
};
