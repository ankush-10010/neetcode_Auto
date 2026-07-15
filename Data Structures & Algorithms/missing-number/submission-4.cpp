#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int result = n; 
        
        for (int i = 0; i < n; i++) {
            // XOR the current index (expected number) 
            // AND the actual number found at that index
            result ^= i ^ nums[i]; 
        }
        
        return result;
    }
};