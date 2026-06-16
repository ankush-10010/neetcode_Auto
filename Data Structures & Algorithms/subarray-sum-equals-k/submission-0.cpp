class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // how do i keep track of all the subarrays
        unordered_map<int,int> prefixSum;
        prefixSum[0] = 1; // a sum of 0 has been seen 1 time 
        int cs = 0;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            cs += nums[i];
            int target = cs - k;
            if(prefixSum.find(target) != prefixSum.end()){
                count += prefixSum[target];
            }

            prefixSum[cs]++;
        }

        return count;
    }
};