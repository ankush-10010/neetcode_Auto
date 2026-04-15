class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> Output;
        for(int i=0; i<nums.size() ; i++){
            for(int j=i+1 ; j<nums.size() ; j++){
                if((nums[i]+nums[j])==target){
            
                    Output.push_back(i);
                    Output.push_back(j);
                    return Output;
                }
            }
        }
        return Output;
    }
};
