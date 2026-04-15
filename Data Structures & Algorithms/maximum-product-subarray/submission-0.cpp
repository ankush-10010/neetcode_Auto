class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxEnd = nums[0];
        int minEnd = nums[0];
        int ans = nums[0];

        for(int i=1;i<nums.size();i++){
            int x = nums[i];

            int tempMax = max({x,maxEnd*x,minEnd*x});
            int tempMin = min({x,maxEnd*x,minEnd*x});

            maxEnd = tempMax;
            minEnd = tempMin;
            ans = max(ans,maxEnd);
        }
        return ans;
    }
};
