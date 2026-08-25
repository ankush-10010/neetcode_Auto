class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;
        for(int i=0;i<n;i++){
            int minE = INT_MAX;
            int maxE = INT_MIN;
            
            for(int j=i;j<n;j++){
                long long currentCount = 0;
                minE = min(minE,nums[j]);
                maxE = max(maxE,nums[j]);
                currentCount += (maxE - minE);
                total += currentCount;
            }
        }

        return total;
    }
};