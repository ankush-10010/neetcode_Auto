class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int totalWeight = 0;
        for (int stone : stones) {
            totalWeight += stone;
        }
        int target = totalWeight / 2;

        vector<bool> dp(target + 1, false);

        dp[0] = true; 
        for (int stone : stones) {
            for (int j = target; j >= stone; j--) {
                if (dp[j - stone]) {
                    dp[j] = true;
                }
            }
        }
        for (int j = target; j >= 0; j--) {
            if (dp[j]) {
                return totalWeight - (2 * j);
            }
        }

        return 0;
    }
};