class Solution {
public:
    bool dfs(int score_diff, int nA, int nB) {
        if ((nA + nB) % 2 != 0) {
            return true; 
        }
    
        if (score_diff * 2 == (nB - nA) * 9) {
            return false; 
        }
        
        return true; 
    }

    bool sumGame(string nums) {
        int n = nums.size();
        int n_alice = 0; 
        int n_bob = 0;   

        int sum_alice = 0; 
        int sum_bob = 0;   
        
        for (int i = 0; i < nums.size(); i++) {
            if (i < nums.size() / 2) { 
                if (nums[i] == '?') {
                    n_alice++;
                } else {
                    sum_alice += nums[i] - '0';
                }
            } else {
                if (nums[i] == '?') {
                    n_bob++;
                } else {
                    sum_bob += nums[i] - '0';
                }
            }
        }

        return dfs(sum_alice - sum_bob, n_alice, n_bob);
    }
};