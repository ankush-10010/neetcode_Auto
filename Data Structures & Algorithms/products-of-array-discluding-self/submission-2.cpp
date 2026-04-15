class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // nums[i] = left pi nums[i] * right pi nums[i]
        vector<int> left(nums.size(),1);
        left[0] = 1;
        for(int i=1;i<nums.size();i++){
            left[i] = left[i-1] * nums[i-1];
        }
        vector<int> right(nums.size(),1);
        right[nums.size()-1] = 1;
        for(int i=nums.size()-2;i>=0;i--){
            right[i] = right[i+1] * nums[i+1];
        } 

        vector<int> ans(nums.size(),1);
        for(int i=0;i<nums.size();i++){
            ans[i] = left[i] * right[i];
        }
        return ans;
    }
};
