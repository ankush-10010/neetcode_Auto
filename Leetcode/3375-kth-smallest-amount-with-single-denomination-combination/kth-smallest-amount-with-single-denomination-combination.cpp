class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long left = 1; 
        long long min_coin = *min_element(coins.begin(), coins.end());
        long long right = min_coin * k; 
        long long ans = right;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            
            if (countMultiples(mid, coins) >= k) {
                ans = mid;        
                right = mid - 1;  
            } else {
                left = mid + 1;   
            }
        }
        
        return ans;
    }

private:
    long long countMultiples(long long X, const vector<int>& coins) {
        long long count = 0;
        int n = coins.size();
        
        int total_subsets = (1 << n);
        for (int mask = 1; mask < total_subsets; mask++) {
            long long current_lcm = 1;
            int set_bits = 0;
            
            for (int i = 0; i < n; i++) {
                if ((mask >> i) & 1) {
                    set_bits++;
                    current_lcm = std::lcm(current_lcm, (long long)coins[i]);
                }
            }
            
            if (set_bits % 2 == 1) {
                count += (X / current_lcm);
            } else {
                count -= (X / current_lcm);
            }
        }
        
        return count;
    }
};