class Solution {
public:
    int area(vector<int>& heights, int index){
        int left = 0;
        if(index == 0){
            int right = 0;
            for(int i=index+1;i<heights.size();i++){
                if(heights[i] >= heights[index]){
                    right+=heights[index];
                }else{
                    break;
                }
            }
            return right + heights[index];
        }
        if(index == heights.size()-1){
            int left = 0;
            for(int i=index-1;i>=0;i--){
                if(heights[i] >= heights[index]){
                    left+=heights[index];
                }else{
                    break;
                }
            }
            return left + heights[index];
        }
        for(int i=index-1;i>=0;i--){
            if(heights[i] >= heights[index]){
                left+=heights[index];
            }else{
                break;
            }
        }
        int right = 0;
        for(int i=index+1;i<heights.size();i++){
            if(heights[i] >= heights[index]){
                right+=heights[index];
            }else{
                break;
            }
        }
        return left + right + heights[index];
        
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> a(heights.size(),0);
        for(int i=0;i<a.size();i++){
            a[i] = area(heights,i);
        }
        
        sort(a.begin(),a.end());
        for(int i=0;i<a.size();i++){
            cout << a[i] << "\t";
        }
        return a[a.size()-1];    
    }
};
