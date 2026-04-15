class Solution {
public:
    int trap(vector<int>& height) {
        // determine the leftmost tallest and right most tallest
        int n = height.size();
        vector<int> dp_left(n,-1);
        vector<int> dp_right(n,-1);

        for(int i=1;i<n;i++){
            dp_left[i] = max(dp_left[i-1],height[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            dp_right[i] = max(dp_right[i+1],height[i+1]);
        }
        vector<int> maxHeight(n,-1);
        for(int i=0;i<n;i++){
            maxHeight[i] = min(dp_left[i],dp_right[i]);
        }
        int currSum = 0;
        for(int i=0;i<n;i++){
            if((maxHeight[i] - height[i]) > 0){
                currSum += (maxHeight[i] - height[i]);
            }
        }
        return currSum;
    }
};