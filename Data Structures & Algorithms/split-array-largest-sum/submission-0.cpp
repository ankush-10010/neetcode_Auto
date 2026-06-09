class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        // basically we have to find the minimum capacity 
        int m = 0;
        int total = 0;
        for(int num : nums){
            m = max(m,num);
            total += num;
        }

        while(m < total){
            int mid = m + (total - m)/2;
            int k_needed = 1;
            int currentLoad = 0;

            for(int i=0;i<nums.size();i++){
                if(currentLoad + nums[i] > mid){
                    k_needed++;
                    currentLoad = nums[i];
                }else{
                    currentLoad += nums[i];
                }
            }
            if(k_needed > k){
                m = mid + 1;
            }else{
                total = mid;
            }
        }
        return m;
    }
};