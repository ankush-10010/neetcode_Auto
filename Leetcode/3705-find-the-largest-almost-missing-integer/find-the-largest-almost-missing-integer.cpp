class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> subarray_count; 
        for (int i = 0; i <= n - k; i++) {
            unordered_set<int> unique_in_window(nums.begin() + i, nums.begin() + i + k);
            for (int num : unique_in_window) {
                subarray_count[num]++;
            }
        }

        int missing = -1;
        for (auto& [num, count] : subarray_count) {
            if (count == 1) {
                missing = max(missing, num);
            }
        }

        return missing;
    }
};