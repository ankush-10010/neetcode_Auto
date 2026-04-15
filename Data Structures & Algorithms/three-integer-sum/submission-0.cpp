class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 3) return result;

        for (int i = 0; i < n - 2; ++i) {
            // skip duplicate i values (minimal change to your flow)
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int target = -nums[i];
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum == target) {
                    // push only when a valid pair is found
                    result.push_back({nums[i], nums[left], nums[right]});

                    // move both pointers to look for other pairs
                    ++left;
                    --right;

                    // skip duplicates for left and right
                    while (left < right && nums[left] == nums[left - 1]) ++left;
                    while (left < right && nums[right] == nums[right + 1]) --right;
                }
                else if (sum > target) {
                    --right;
                }
                else { // sum < target
                    ++left;
                }
            }
        }
        return result;
    }
};
