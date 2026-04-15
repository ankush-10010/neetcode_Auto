class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 3) return result;

        for (int i = 0; i < n - 2; ++i) {
            // skip duplicate i values
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int target = -nums[i];
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum == target) {
                    // push the triplet
                    result.push_back({nums[i], nums[left], nums[right]});

                    // move both pointers
                    ++left;
                    --right;

                    // skip duplicate left values
                    while (left < right && nums[left] == nums[left - 1]) ++left;

                    // skip duplicate right values
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

