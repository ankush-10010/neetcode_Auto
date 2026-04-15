class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (rows == 0) return false;
        int cols = matrix[0].size();
        if (cols == 0) return false;

        for(int i=0; i<matrix.size(); i++){
            if(matrix[i][cols-1]<target){
                continue;
            }
            if (target < matrix[i][0]) {
                return false;
            }
            
            int start=0;
            int end=cols-1;
            while(start<=end){
                int mid = start + (end-start)/2;
                if(matrix[i][mid]==target){
                return true;
                 }
                if(matrix[i][mid]>target){
                    end=mid-1;
                }
                if(matrix[i][mid]<target){
                    start=mid+1;
                }
            }
            
        }
        return false;
    }
};
