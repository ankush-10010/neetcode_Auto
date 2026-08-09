class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        
        vector<int> suffix(n);
        suffix[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffix[i] = suffix[i + 1] + piles[i];
        }
        
        vector<vector<int>> memo(n, vector<int>(n + 1, -1));
        
        return dfs(0, 1, suffix, memo);
    }

private:
    int dfs(int i, int M, const vector<int>& suffix, vector<vector<int>>& memo) {
        int n = suffix.size();
    
        if (i >= n) {
            return 0;
        }
        if (i + 2 * M >= n) {
            return suffix[i];
        }

        if (memo[i][M] != -1) {
            return memo[i][M];
        }
        
        int max_stones = 0;
        
        for (int x = 1; x <= 2 * M; ++x) {
            int next_M = max(M, x);
            
            int next_player_stones = dfs(i + x, next_M, suffix, memo);

            int current_stones = suffix[i] - next_player_stones;
            
            max_stones = max(max_stones, current_stones);
        }
        
        return memo[i][M] = max_stones;
    }
};