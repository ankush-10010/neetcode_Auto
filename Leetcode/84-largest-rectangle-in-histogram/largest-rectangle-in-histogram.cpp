class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> minPrev(n,-1);
        vector<int> minNext(n,n);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                st.pop();
            }
            if(!st.empty()){
                minPrev[i] = st.top();
            }
            st.push(i);
        }
        
        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                minNext[i] = st.top();
            }
            st.push(i);
        }

        int maxarea = 0;
        for(int i = 0; i < n; i++) {
            int width = minNext[i] - minPrev[i] - 1; 
            int area = width * heights[i];
            maxarea = max(maxarea, area);
        }
        return maxarea;
    }
};