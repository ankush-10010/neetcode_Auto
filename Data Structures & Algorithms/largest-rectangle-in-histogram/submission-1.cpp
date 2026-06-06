class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        // Iterate up to 'n' to include the mock 0-height bar at the end
        for (int i = 0; i <= n; i++) {
            // Treat the out-of-bounds index 'n' as height 0
            int currHeight = (i == n) ? 0 : heights[i];
            
            // If current bar is shorter than the stack's top bar, we found a right boundary
            while (!st.empty() && currHeight < heights[st.top()]) {
                // The height of the rectangle is the popped element's height
                int h = heights[st.top()];
                st.pop();
                
                // The right boundary is 'i'
                // The left boundary is the NEW top of the stack
                int width;
                if (st.empty()) {
                    width = i; // It extends all the way to the beginning
                } else {
                    width = i - st.top() - 1; // Distance between left and right boundaries
                }
                
                // Update maximum area found so far
                maxArea = max(maxArea, h * width);
            }
            
            // Push the current index onto the stack
            st.push(i);
        }
        
        return maxArea;
    }
};