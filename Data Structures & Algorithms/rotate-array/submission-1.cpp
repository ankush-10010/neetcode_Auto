class Solution {
private:
    private:
    // Our custom Two-Pointer reverse function
    void reverseSection(vector<int>& nums, int left, int right) {
        while (left < right) {
            // Swap the elements
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            
            // Move pointers inward
            left++;
            right--;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Edge case: if k is larger than the array size, wrap it around
        k = k % n; 
        
        // Step 1: Reverse the whole array
        reverseSection(nums, 0, n - 1);
        
        // Step 2: Reverse the first k elements
        reverseSection(nums, 0, k - 1);
        
        // Step 3: Reverse the rest of the array
        reverseSection(nums, k, n - 1);
    }
};