class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> sumIndex;
        
        sumIndex[0] = -1; 
        
        int maxLen = 0;
        int currentSum = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            currentSum += (nums[i] == 1) ? 1 : -1;
            if (sumIndex.find(currentSum) != sumIndex.end()) {
                int currentLen = i - sumIndex[currentSum];
                maxLen = max(maxLen, currentLen);
            } else {
                sumIndex[currentSum] = i;
            }
        }
        
        return maxLen;
    }
};