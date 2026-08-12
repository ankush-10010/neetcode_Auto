class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left = 0;
        int maxLength = 0;
        unordered_map<int,int> freq;

        for(int right=0;right<nums.size();right++){
            freq[nums[right]]++;
            while(freq[nums[right]] > k){
                freq[nums[left]]--;
                left++;
            }
            int length = (right-left+1);
            maxLength = max(maxLength,length);
        }

        return maxLength;
    }
};