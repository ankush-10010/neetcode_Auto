class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int maxSize = r;
        int minSize = l;
        vector<int> prefixSum(n,0);
        prefixSum[0] = nums[0];

        for(int i=1;i<n;i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        int minSum = INT_MAX;
        for(int right = 0;right < nums.size();right++){
            for(int left = 0;left <= right ; left++){
                if((right - left + 1) > maxSize) continue;
                if((right - left + 1 < minSize)) continue;
                int currentSum = prefixSum[right] - prefixSum[left] + nums[left];
                if(currentSum > 0) minSum = min(minSum,currentSum);
            }   
        }
        return (minSum == INT_MAX ? -1 : minSum);

    }
};