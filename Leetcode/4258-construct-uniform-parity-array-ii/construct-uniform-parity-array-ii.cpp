class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        int minEven = INT_MAX;
        
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] % 2 != 0) {
                if (nums1[i] < minOdd) {
                    minOdd = nums1[i];
                }
            } else {
                if (nums1[i] < minEven) {
                    minEven = nums1[i];
                }
            }
        }
        
        return minOdd == INT_MAX || minOdd < minEven;
    }
};