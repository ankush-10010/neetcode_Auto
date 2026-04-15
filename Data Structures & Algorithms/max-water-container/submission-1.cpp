class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int leftptr = 0;
        int rightptr = n-1;
        int currMax = INT_MIN;

        while(leftptr < rightptr){
            int currArea = 0;
            if(heights[rightptr] == heights[leftptr]){
                currArea = heights[rightptr]*(rightptr-leftptr);
            }else{
                currArea = min(heights[rightptr],heights[leftptr])*(rightptr-leftptr);
            }
            
            currMax= max(currMax,currArea);
            if(heights[leftptr] < heights[rightptr]){
                leftptr++;
            }else{
                rightptr--;
            }
        }
        return currMax;
    }
};
