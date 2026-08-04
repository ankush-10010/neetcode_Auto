class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> result;
        
        int i = 0;
        int curr = nums[0]; 
        
        while (i < nums.size()) {
            if (nums[i] != curr) {
                result.push_back(curr);
                curr++; 
            } else {
                curr++;
                i++;
            }
        }
        return result;
    }
};