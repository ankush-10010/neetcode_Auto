class Solution {
public:
    int trap(vector<int>& height) {
        // maintain left_max , right_max for each point 
        // water holding is (min(l_m,r_m),0) - heights[i]
        if(height.size() == 0) return 0;
        int left = 0;
        int right = height.size() - 1;
        int left_max = 0;
        int right_max = 0;
        int total_water = 0;

        while(left < right){
            if(height[left] < height[right]){
                left_max = max(left_max,height[left]);
                total_water += left_max - height[left];
                left++;
            }else{
                right_max = max(right_max,height[right]);
                total_water += right_max - height[right];
                right--;
            }
        }
        return total_water;
    }
};