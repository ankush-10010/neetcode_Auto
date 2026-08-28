class Solution {
public:
    int solve(int i, int j, vector<int>& stones, int K, vector<int>& prefix, vector<vector<int>>& memo) {
        if (i == j) return 0;
        
        if (memo[i][j] != -1) return memo[i][j];

        int minCost = INT_MAX;
        for (int mid = i; mid < j; mid += K - 1) {
            int leftCost = solve(i, mid, stones, K, prefix, memo);
            int rightCost = solve(mid + 1, j, stones, K, prefix, memo);
            
            minCost = min(minCost, leftCost + rightCost);
        }

        if ((j - i) % (K - 1) == 0) {
            minCost += prefix[j + 1] - prefix[i];
        }

        return memo[i][j] = minCost;
    }
    
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        
        if ((n - 1) % (K - 1) != 0) return -1;
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stones[i];
        }
        vector<vector<int>> memo(n, vector<int>(n, -1));

        return solve(0, n - 1, stones, K, prefix, memo);
    }
};