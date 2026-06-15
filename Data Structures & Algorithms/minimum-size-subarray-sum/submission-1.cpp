class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<long long> s(n + 1, 0);
        for (int i = 0; i < n; i++) {
            s[i + 1] = s[i] + nums[i];
        }

        int minLength = INT_MAX;
        for (int i = 0; i < n; i++) {
            long long targetToFind = s[i] + target;
            auto it = lower_bound(s.begin(), s.end(), targetToFind);
            if (it != s.end()) {
                int j = distance(s.begin(), it); 
                minLength = min(minLength, j - i);
            }
        }

        return minLength == INT_MAX ? 0 : minLength;
    }
};