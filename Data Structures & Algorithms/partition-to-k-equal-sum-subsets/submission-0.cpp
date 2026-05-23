class Solution {
public:
    bool backtrack(int k,int current_sum,int target_sum,int start_index,vector<int>& nums,vector<bool>& visited){
        if(k==1){
            return true;
        }
        if(current_sum == target_sum){
            return backtrack(k-1,0,target_sum,0,nums,visited);
        }

        for(int i=start_index;i<nums.size();i++){
            if(visited[i] || current_sum + nums[i] > target_sum){
                continue;
            }

            visited[i] = true;

            if(backtrack(k,current_sum+nums[i],target_sum,i+1,nums,visited)){
                return true;
            }

            visited[i] = false;

            if(current_sum == 0){
                break;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalSum = 0;
        for(int num : nums){
            totalSum += num;
        }
        if(totalSum % k != 0){
            return false;
        }

        int target_sum = totalSum/k;
        sort(nums.rbegin(),nums.rend());

        vector<bool> visited(nums.size(),false);
        // now we have to find the pairs that will make up Sum.. not pairs exactly..
        return backtrack(k,0,target_sum,0,nums,visited);
    }
};