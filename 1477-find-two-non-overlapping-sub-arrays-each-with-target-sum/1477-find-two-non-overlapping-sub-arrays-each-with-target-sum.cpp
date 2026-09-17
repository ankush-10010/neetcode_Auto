class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> min_len(n, 1e9);
        int sum = 0;
        int left = 0;
        int ans = 1e9;
        int current_min = 1e9;
        
        for (int right = 0; right < n; ++right) {
            sum += arr[right];
            
            while (sum > target) {
                sum -= arr[left];
                left++;
            }
            
            if (sum == target) {
                int len = right - left + 1;
                
                if (left > 0 && min_len[left - 1] != 1e9) {
                    ans = min(ans, len + min_len[left - 1]);
                }
                
                current_min = min(current_min, len);
            }
            
            min_len[right] = current_min;
        }
        
        return ans == 1e9 ? -1 : ans;
    }
};