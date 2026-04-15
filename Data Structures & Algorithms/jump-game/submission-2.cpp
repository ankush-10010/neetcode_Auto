class Solution {
public:
    bool canJump(vector<int>& nums) {
        //maintain for each index if the index is reachable or not
        vector<bool> Isreachable(nums.size(),false);
        Isreachable[0] = true;
        for(int i=0;i<nums.size();i++){
            // what are the index that we can reach through  index 0
            if(Isreachable[i]){
                Isreachable[nums[i] + i] = true;
            }
            if(Isreachable[nums[i] + i]){
                //all the before indexes will have true value
                for(int j=0;j<(nums[i] + i);j++){
                    Isreachable[j] = true;
                }
            }
            // if we can reach this index then we could have 
            //reach all the indexes before this index through this i only
        }
        return Isreachable[nums.size()-1];
    }
};
