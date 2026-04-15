class Solution {
public:
    int backtrack(vector<int>& nums,int index,int currentXOR){
        if(index==nums.size()){
            return currentXOR;
        }
        int taken = backtrack(nums,index+1,currentXOR^nums[index]);
        int nottaken = backtrack(nums,index+1,currentXOR);

        return taken+nottaken;
    }
    int subsetXORSum(vector<int>& nums) {
        
        return backtrack(nums,0,0);
    }
};