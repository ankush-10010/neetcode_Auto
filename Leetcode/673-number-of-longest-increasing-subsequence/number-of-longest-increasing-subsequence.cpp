class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        
        vector<int> length(n,1);
        vector<int> count(n,1);
        
        int maxLen = 1;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j]){
                    if(length[j] + 1 > length[i]){
                        length[i] = length[j] + 1;
                        count[i] = count[j];
                    }
                    else if(length[j] + 1 == length[i]){
                        count[i] += count[j];
                    }
                }
            }
            maxLen = max(maxLen,length[i]);
        }
        int totalWays = 0;
        for(int i=0;i<n;i++){
            if(length[i] == maxLen) totalWays += count[i];
        }

        return totalWays;
    }
};